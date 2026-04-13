#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "lodepng.h"

#include "Image.hpp"
#include "LinAlg.hpp"
#include "Light.hpp"
#include "Mesh.hpp"
#include "Shading.hpp"


// Simple vector structs
struct float3 {
    float x, y, z;
};

struct Vec2 {
    float x, y;
};

int main()
{
    std::string outputFilename = "output.png";

    const int width = 1920, height = 1080;
    const int nChannels = 4;

    // Image buffer
    std::vector<uint8_t> imageBuffer(width * height * nChannels, 0);

    // triangle vertices
    Vec2 v0 = { 400, 200 };
    Vec2 v1 = { 1500, 300 };
    Vec2 v2 = { 900, 900 };

    // Flat normal
    float3 normal = { 0.0f, 0.0f, 1.0f };

    // Light + view
    float3 lightDir = { 0.0f, 0.0f, -1.0f };
    float3 viewDir = { 0.0f, 0.0f, -1.0f };

    // helper
    auto normalize = [](float3 v) {
        float len = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
        return float3{ v.x / len, v.y / len, v.z / len };
        };

    auto dot = [](float3 a, float3 b) {
        return a.x * b.x + a.y * b.y + a.z * b.z;
        };

    auto reflect = [&](float3 i, float3 n) {
        float d = dot(i, n);
        return float3{
            i.x - 2.0f * d * n.x,
            i.y - 2.0f * d * n.y,
            i.z - 2.0f * d * n.z
        };
        };

    auto edge = [](Vec2 a, Vec2 b, Vec2 c) {
        return (c.x - a.x) * (b.y - a.y) - (c.y - a.y) * (b.x - a.x);
        };

    lightDir = normalize(lightDir);
    viewDir = normalize(viewDir);

    // Phong parameters
    float ka = 0.1f;
    float kd = 0.7f;
    float ks = 0.5f;
    float shininess = 32.0f;

    // bounds
    int minX = std::max(0, (int)std::floor(std::min({ v0.x, v1.x, v2.x })));
    int maxX = std::min(width - 1, (int)std::ceil(std::max({ v0.x, v1.x, v2.x })));
    int minY = std::max(0, (int)std::floor(std::min({ v0.y, v1.y, v2.y })));
    int maxY = std::min(height - 1, (int)std::ceil(std::max({ v0.y, v1.y, v2.y })));

    // rasterise triangel
    for (int y = minY; y <= maxY; ++y)
    {
        for (int x = minX; x <= maxX; ++x)
        {
            Vec2 p = { (float)x, (float)y };

            float w0 = edge(v1, v2, p);
            float w1 = edge(v2, v0, p);
            float w2 = edge(v0, v1, p);

            // triangle test
            if ((w0 >= 0 && w1 >= 0 && w2 >= 0) ||
                (w0 <= 0 && w1 <= 0 && w2 <= 0))
            {
                int pixelIdx = x + y * width;

                // phong
                float diff = std::max(dot(normal, lightDir), 0.0f);

                float3 refl = reflect(
                    { -lightDir.x, -lightDir.y, -lightDir.z },
                    normal
                );
                refl = normalize(refl);

                float spec = pow(std::max(dot(refl, viewDir), 0.0f), shininess);

                float intensity = ka + kd * diff + ks * spec;

                // Base colour 
                float r = 0.0f;
                float g = 1.0f;
                float b = 1.0f;

                r *= intensity;
                g *= intensity;
                b *= intensity;

                // Write pixel
                imageBuffer[pixelIdx * nChannels + 0] = (uint8_t)(std::min(r, 1.0f) * 255);
                imageBuffer[pixelIdx * nChannels + 1] = (uint8_t)(std::min(g, 1.0f) * 255);
                imageBuffer[pixelIdx * nChannels + 2] = (uint8_t)(std::min(b, 1.0f) * 255);
                imageBuffer[pixelIdx * nChannels + 3] = 255;
            }
        }
    }

    // ---- Save image ----
    int errorCode = lodepng::encode(outputFilename, imageBuffer, width, height);
    if (errorCode) {
        std::cout << "lodepng error: " << lodepng_error_text(errorCode) << std::endl;
        return errorCode;
    }

    std::cout << "Rendered output.png successfully!\n";
    return 0;
}