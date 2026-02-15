#include <iostream>
#include <vector>
#include <cstdint>
#include <cstring>   // memset
#include <cmath>     // std::abs
#include <algorithm> // std::swap
#include <lodepng.h>
#include <fstream>
#include <sstream>
#include <string>

#include "Vector3.hpp"

// Safe pixel write (bounds checked)
void setPixel(std::vector<uint8_t>& image,
	int x, int y, int width, int height,
	uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255)
{
	if (x < 0 || y < 0 || x >= width || y >= height) return;
	int pixelIdx = x + y * width;
	image[pixelIdx * 4 + 0] = r;
	image[pixelIdx * 4 + 1] = g;
	image[pixelIdx * 4 + 2] = b;
	image[pixelIdx * 4 + 3] = a;
}

// Robust line drawing (handles vertical lines, steep lines, etc.) using a simple DDA
void drawLine(std::vector<uint8_t>& image,
	int width, int height,
	int x0, int y0, int x1, int y1)
{
	int dx = x1 - x0;
	int dy = y1 - y0;

	int steps = std::max(std::abs(dx), std::abs(dy));
	if (steps == 0) {
		setPixel(image, x0, y0, width, height, 255, 255, 255);
		return;
	}

	float fx = (float)x0;
	float fy = (float)y0;
	float xInc = dx / (float)steps;
	float yInc = dy / (float)steps;

	for (int i = 0; i <= steps; ++i) {
		setPixel(image, (int)std::lround(fx), (int)std::lround(fy), width, height, 255, 255, 255);
		fx += xInc;
		fy += yInc;
	}
}

// Parse an OBJ face token like "12", "12/3", "12//7", "12/3/7" and return the vertex index (0-based)
static bool parseFaceVertexIndex(const std::string& token, unsigned& outIndex0Based)
{
	if (token.empty()) return false;

	// Take substring up to first '/'
	size_t slashPos = token.find('/');
	std::string vStr = (slashPos == std::string::npos) ? token : token.substr(0, slashPos);

	if (vStr.empty()) return false;

	// OBJ indices are 1-based; negative indices exist in OBJ spec, but we’ll keep it simple here
	int idx = 0;
	try {
		idx = std::stoi(vStr);
	}
	catch (...) {
		return false;
	}
	if (idx <= 0) return false;

	outIndex0Based = (unsigned)(idx - 1);
	return true;
}

int main()
{
	std::string outputFilename = "output.png";

	const int width = 512, height = 512;
	const int nChannels = 4;

	std::vector<uint8_t> imageBuffer(height * width * nChannels);
	std::memset(imageBuffer.data(), 0, imageBuffer.size() * sizeof(uint8_t));

	std::string bunnyFilename = "../models/stanford_bunny_simplified.obj";
	std::ifstream bunnyFile(bunnyFilename);
	if (!bunnyFile.is_open()) {
		std::cout << "Failed to open OBJ file: " << bunnyFilename << std::endl;
		return 1;
	}

	// *** Task 2 ***
	// Load vertices ('v' lines) and faces ('f' lines)
	std::vector<Vector3> vertices;
	std::vector<std::vector<unsigned int>> faces;

	std::string line;
	while (std::getline(bunnyFile, line))
	{
		if (line.empty()) continue;

		std::stringstream lineSS(line);
		std::string prefix;
		lineSS >> prefix;

		// Vertex positions: "v x y z"
		if (prefix == "v")
		{
			Vector3 v;
			lineSS >> v[0] >> v[1] >> v[2];
			if (!lineSS.fail()) vertices.push_back(v);
		}
		// Faces: "f a b c ..." where each token may be "v", "v/vt", "v//vn", "v/vt/vn"
		else if (prefix == "f")
		{
			std::vector<unsigned int> face;
			std::string tok;
			while (lineSS >> tok) {
				unsigned vi = 0;
				if (parseFaceVertexIndex(tok, vi)) {
					face.push_back(vi);
				}
			}

			// keep only faces with at least 3 vertices
			if (face.size() >= 3) faces.push_back(face);
		}
	}

	// Helper to project mesh coords (~ -0.5..0.5) into screen coords
	auto project = [&](const Vector3& v) -> std::pair<int, int> {
		const float scale = 250.0f;
		int x = (int)std::lround(v[0] * scale + width * 0.5f);
		int y = (int)std::lround(-v[1] * scale + height * 0.5f); // flip Y
		return { x, y };
	};

	// *** Task 3 ***
	// Draw wireframe by drawing edges of each face.
	// If a face has >3 vertices, connect them in a loop (polygon outline).
	for (size_t f = 0; f < faces.size(); ++f)
	{
		const auto& face = faces[f];

		for (size_t i = 0; i < face.size(); ++i) {
			unsigned i0 = face[i];
			unsigned i1 = face[(i + 1) % face.size()];

			// Safety: check indices are valid
			if (i0 >= vertices.size() || i1 >= vertices.size()) continue;

			auto [x0, y0] = project(vertices[i0]);
			auto [x1, y1] = project(vertices[i1]);

			drawLine(imageBuffer, width, height, x0, y0, x1, y1);
		}
	}

	// Save PNG
	int errorCode = lodepng::encode(outputFilename, imageBuffer, width, height);
	if (errorCode) {
		std::cout << "lodepng error encoding image: " << lodepng_error_text(errorCode) << std::endl;
		return errorCode;
	}

	return 0;
}
