#include <iostream>
#include <vector>
#include <cstdint>
#include <cstring>   // memset
#include <lodepng.h>
#include <fstream>
#include <sstream>
#include "Vector3.hpp"

// Safer setPixel (bounds check so we don't write outside the buffer)
void setPixel(std::vector<uint8_t>& image,
    int x, int y,
    int width, int height,
    uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255)
{
    if (x < 0 || y < 0 || x >= width || y >= height) return;
    int pixelIdx = x + y * width;
    image[pixelIdx * 4 + 0] = r;
    image[pixelIdx * 4 + 1] = g;
    image[pixelIdx * 4 + 2] = b;
    image[pixelIdx * 4 + 3] = a;
}

int main()
{
    std::string outputFilename = "output.png";

    const int width = 512, height = 512;
    const int nChannels = 4;

    std::vector<uint8_t> imageBuffer(height * width * nChannels);

    // Clear to black
    std::memset(imageBuffer.data(), 0, imageBuffer.size() * sizeof(uint8_t));

    std::string bunnyFilename = "../models/stanford_bunny_simplified.obj";
    std::ifstream bunnyFile(bunnyFilename);

    if (!bunnyFile.is_open()) {
        std::cout << "Failed to open OBJ file: " << bunnyFilename << std::endl;
        return 1;
    }

    // --------------------------------------------------------------------
    // Task 2: Load vertices (lines beginning with "v ")
    // Note: OBJ also contains lines like "vn" and "vt". We only want "v".
    std::vector<Vector3> vertices;
    std::string line;
    while (std::getline(bunnyFile, line))
    {
        if (line.size() < 2) continue;
        if (line[0] != 'v') continue;
        if (!(line.size() >= 2 && std::isspace((unsigned char)line[1]))) continue; // ensure it's "v " not "vn"/"vt"

        std::stringstream lineSS(line);
        char vChar;
        lineSS >> vChar;

        Vector3 v;
        lineSS >> v[0] >> v[1] >> v[2];
        if (!lineSS.fail()) {
            vertices.push_back(v);
        }
    }

    // --------------------------------------------------------------------
    // Task 3: Draw vertices as points
    // Map mesh coords (~ -0.5..0.5) to image coords (0..511)
    const float scale = 250.0f;

    for (const auto& v : vertices)
    {
        int x = (int)(v[0] * scale + (float)width * 0.5f);
        int y = (int)(-v[1] * scale + (float)height * 0.5f); // flip y so +Y goes up
        setPixel(imageBuffer, x, y, width, height, 255, 255, 255, 255);
    }

    // Save PNG
    int errorCode = lodepng::encode(outputFilename, imageBuffer, width, height);
    if (errorCode) {
        std::cout << "lodepng error encoding image: " << lodepng_error_text(errorCode) << std::endl;
        return errorCode;
    }

    return 0;
}