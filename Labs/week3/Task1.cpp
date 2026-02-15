#include <iostream>
#include <vector>
#include <cstdint>
#include <cstring>    // memset
#include <algorithm>  // std::min/std::max
#include <cmath>      // std::abs
#include <cstdlib>    // rand
#include <lodepng.h>
#include <fstream>
#include <sstream>

#include "Vector3.hpp"
#include "Vector2.hpp"

// Safer setPixel (bounds check to avoid memory errors)
void setPixel(std::vector<uint8_t>& image, int x, int y, int width, int height,
    uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255)
{
    if (x < 0 || y < 0 || x >= width || y >= height) return;
    int pixelIdx = x + y * width;
    image[pixelIdx * 4 + 0] = r;
    image[pixelIdx * 4 + 1] = g;
    image[pixelIdx * 4 + 2] = b;
    image[pixelIdx * 4 + 3] = a;
}

// Task 2: barycentric triangle fill
void drawTriangle(std::vector<uint8_t>& image, int width, int height,
    const Vector2& p0, const Vector2& p1, const Vector2& p2,
    uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255)
{
    // 1) Bounding box
    int minX = (int)std::floor(std::min({ p0.x(), p1.x(), p2.x() }));
    int maxX = (int)std::ceil(std::max({ p0.x(), p1.x(), p2.x() }));
    int minY = (int)std::floor(std::min({ p0.y(), p1.y(), p2.y() }));
    int maxY = (int)std::ceil(std::max({ p0.y(), p1.y(), p2.y() }));

    // 2) Clamp to image bounds
    minX = std::max(minX, 0);
    minY = std::max(minY, 0);
    maxX = std::min(maxX, width - 1);
    maxY = std::min(maxY, height - 1);

    // 3) Edge vectors and total area (signed)
    Vector2 e01 = p1 - p0;
    Vector2 e02 = p2 - p0;
    float triangleArea = Vector2::cross(e01, e02);

    // Degenerate triangle? (area ~ 0)
    if (std::abs(triangleArea) < 1e-8f) return;

    // Optional backface culling (only draw one winding)
    // If you want culling, uncomment this:
    // if (triangleArea < 0.0f) return;

    // 4) Rasterize pixels in bounding box
    // Use edge-function style barycentrics via signed areas
    for (int y = minY; y <= maxY; ++y) {
        for (int x = minX; x <= maxX; ++x) {
            Vector2 p((float)x + 0.5f, (float)y + 0.5f); // sample at pixel center

            // Sub-triangle signed areas (relative to full triangle winding)
            float a0 = Vector2::cross(p1 - p, p2 - p); // area opposite p0
            float a1 = Vector2::cross(p2 - p, p0 - p); // area opposite p1
            float a2 = Vector2::cross(p0 - p, p1 - p); // area opposite p2

            float b0 = a0 / triangleArea;
            float b1 = a1 / triangleArea;
            float b2 = a2 / triangleArea;

            // Inside test: all barycentrics in [0,1] (with small epsilon)
            const float eps = -1e-5f;
            if (b0 >= eps && b1 >= eps && b2 >= eps) {
                setPixel(image, x, y, width, height, r, g, b, a);
            }
        }
    }
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

    std::vector<Vector3> vertices;
    std::vector<std::vector<unsigned int>> faces;
    std::string line;

    while (!bunnyFile.eof())
    {
        std::getline(bunnyFile, line);
        std::stringstream lineSS(line.c_str());
        char lineStart;
        lineSS >> lineStart;
        char ignoreChar;

        if (lineStart == 'v') {
            Vector3 v;
            for (int i = 0; i < 3; ++i) lineSS >> v[i];
            vertices.push_back(v);
        }

        if (lineStart == 'f') {
            std::vector<unsigned int> face;
            unsigned int idx, idxTex, idxNorm;
            while (lineSS >> idx >> ignoreChar >> idxTex >> ignoreChar >> idxNorm) {
                face.push_back(idx - 1);
            }
            if (face.size() > 0) faces.push_back(face);
        }
    }

    // Choose which bunny to draw:
    // 0 = solid red (original)
    // 1 = random colour bunny
    // 2 = diffuse lighting bunny
    int bunnyMode = 1;

    for (const auto& face : faces) {
        // Screen-space triangle points
        Vector2 p0(vertices[face[0]].x() * 250 + width / 2, -vertices[face[0]].y() * 250 + height / 2);
        Vector2 p1(vertices[face[1]].x() * 250 + width / 2, -vertices[face[1]].y() * 250 + height / 2);
        Vector2 p2(vertices[face[2]].x() * 250 + width / 2, -vertices[face[2]].y() * 250 + height / 2);

        uint8_t r = 255, g = 0, b = 0;

        if (bunnyMode == 0) {
            // Solid red
            r = 255; g = 0; b = 0;
        }
        else if (bunnyMode == 1) {
            // Bunny 1: Random colour per triangle
            r = (uint8_t)(rand() % 256);
            g = (uint8_t)(rand() % 256);
            b = (uint8_t)(rand() % 256);
        }
        else if (bunnyMode == 2) {
            // Bunny 2: (Sort of) diffuse lighting bunny

            // Compute triangle normal in *model space* using 3D vertices
            const Vector3& v0 = vertices[face[0]];
            const Vector3& v1 = vertices[face[1]];
            const Vector3& v2 = vertices[face[2]];

            Vector3 e1 = v1 - v0;
            Vector3 e2 = v2 - v0;
            Vector3 n = Vector3::cross(e1, e2).normalized();

            // Light direction / view direction: (0,0,1)
            float brightness = Vector3::dot(n, Vector3(0.0f, 0.0f, 1.0f));

            // Clamp to [0,1]
            if (brightness < 0.0f) brightness = 0.0f;
            if (brightness > 1.0f) brightness = 1.0f;

            uint8_t c = (uint8_t)(brightness * 255.0f);
            r = g = b = c; // grayscale shading
        }

        drawTriangle(imageBuffer, width, height, p0, p1, p2, r, g, b, 255);
    }

    int errorCode = lodepng::encode(outputFilename, imageBuffer, width, height);
    if (errorCode) {
        std::cout << "lodepng error encoding image: " << lodepng_error_text(errorCode) << std::endl;
        return errorCode;
    }

    return 0;
}