#include <iostream>
#include <vector>
#include <cstdint>
#include <lodepng.h>

// (Optional) helper from previous lab
inline void setPixel(std::vector<uint8_t>& imageBuffer,
    unsigned width, unsigned height,
    int x, int y,
    uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    if (x < 0 || y < 0 || x >= (int)width || y >= (int)height) return;
    const unsigned idx = (unsigned)x + (unsigned)y * width;
    imageBuffer[idx * 4 + 0] = r;
    imageBuffer[idx * 4 + 1] = g;
    imageBuffer[idx * 4 + 2] = b;
    imageBuffer[idx * 4 + 3] = a;
}

int main()
{
    std::string inputFilename = "../images/stanford_bunny.png";
    std::string outputFilename = "output_bunny.png";

    std::vector<uint8_t> imageBuffer;
    unsigned int width = 0, height = 0;

    unsigned decodeErr = lodepng::decode(imageBuffer, width, height, inputFilename);
    if (decodeErr) {
        std::cout << "lodepng error decoding image: "
            << lodepng_error_text(decodeErr) << std::endl;
        return (int)decodeErr;
    }

    // --------------------------------------------------------------------
    // Task 1: Negative image
    // Commented out the brightness-reduction example and replaced with negative.
    // For 8-bit values (0..255): negative is (255 - v).
    for (unsigned y = 0; y < height; ++y)
        for (unsigned x = 0; x < width; ++x) {
            unsigned pixelIdx = x + y * width;

            // RGB channels
            imageBuffer[pixelIdx * 4 + 0] = 255 - imageBuffer[pixelIdx * 4 + 0];
            imageBuffer[pixelIdx * 4 + 1] = 255 - imageBuffer[pixelIdx * 4 + 1];
            imageBuffer[pixelIdx * 4 + 2] = 255 - imageBuffer[pixelIdx * 4 + 2];

            // Alpha usually left unchanged; you can invert it too if you want:
            // imageBuffer[pixelIdx * 4 + 3] = 255 - imageBuffer[pixelIdx * 4 + 3];
        }

    // --------------------------------------------------------------------
    // Optional Task 2: Downsample to 1/2 resolution (average each 2x2 block)
    //
    // If you want to *also* downsample, keep this block enabled.
    // If you ONLY want the negative at full res, comment this block out.
    {
        const unsigned newW = width / 2;
        const unsigned newH = height / 2;

        std::vector<uint8_t> downsampled(newW * newH * 4);

        for (unsigned y = 0; y < newH; ++y) {
            for (unsigned x = 0; x < newW; ++x) {
                // Top-left pixel of the 2x2 block in the original image
                unsigned ox = x * 2;
                unsigned oy = y * 2;

                auto srcIndex = [&](unsigned sx, unsigned sy) -> unsigned {
                    return (sx + sy * width) * 4;
                };

                const unsigned i00 = srcIndex(ox, oy);
                const unsigned i10 = srcIndex(ox + 1, oy);
                const unsigned i01 = srcIndex(ox, oy + 1);
                const unsigned i11 = srcIndex(ox + 1, oy + 1);

                const unsigned dst = (x + y * newW) * 4;

                // Average with integer math (sum fits in 0..1020, safe in int)
                for (int c = 0; c < 4; ++c) {
                    int sum = (int)imageBuffer[i00 + c]
                        + (int)imageBuffer[i10 + c]
                        + (int)imageBuffer[i01 + c]
                        + (int)imageBuffer[i11 + c];
                    downsampled[dst + c] = (uint8_t)((sum + 2) / 4); // +2 for rounding
                }
            }
        }

        // Replace buffer + update dimensions
        imageBuffer.swap(downsampled);
        width = newW;
        height = newH;
    }

    unsigned errorCode = lodepng::encode(outputFilename, imageBuffer, width, height);
    if (errorCode) {
        std::cout << "lodepng error encoding image: " << lodepng_error_text(errorCode) << std::endl;
        return (int)errorCode;
    }

    return 0;
}