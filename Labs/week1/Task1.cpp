#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
#include <lodepng.h>

// Task 2: setPixel helper
// - Pass imageBuffer by NON-const reference because we modify it.
// - width/nChannels are needed to compute the index.
inline void setPixel(std::vector<uint8_t>& imageBuffer,
                     int width, int nChannels,
                     int x, int y,
                     uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    // Basic bounds check to avoid out-of-range writes
    if (x < 0 || y < 0) return;

    // NOTE: caller should ensure x < width and y < height if you want faster code
    int pixelIdx = x + y * width;
    int base = pixelIdx * nChannels;

    imageBuffer[base + 0] = r;
    imageBuffer[base + 1] = g;
    imageBuffer[base + 2] = b;
    imageBuffer[base + 3] = a;
}

int main()
{
    std::string outputFilename = "output.png";

    const int width = 1920, height = 1080;
    const int nChannels = 4;

    std::vector<uint8_t> imageBuffer(height * width * nChannels);

    // Task 1: Upper half cyan, lower half green
    for (int y = 0; y < height; ++y)
        for (int x = 0; x < width; ++x) {
            if (y < height / 2) {
                // cyan: (0,255,255)
                setPixel(imageBuffer, width, nChannels, x, y, 0, 255, 255, 255);
            } else {
                // green: (0,255,0)
                setPixel(imageBuffer, width, nChannels, x, y, 0, 255, 0, 255);
            }
        }

    // Task 2 test: draw a few colored pixels so you can verify setPixel works
    // (small 11x11 squares near top-left)
    for (int y = 20; y <= 30; ++y)
        for (int x = 20; x <= 30; ++x)
            setPixel(imageBuffer, width, nChannels, x, y, 255, 0, 0, 255);   // red

    for (int y = 20; y <= 30; ++y)
        for (int x = 40; x <= 50; ++x)
            setPixel(imageBuffer, width, nChannels, x, y, 0, 0, 255, 255);   // blue

    // Optional Task 3: circle in the centre (white)
    {
        const int cx = width / 2;
        const int cy = height / 2;
        const int radius = 250;

        const int r2 = radius * radius; // avoid sqrt for speed
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                int dx = x - cx;
                int dy = y - cy;
                if (dx * dx + dy * dy < r2) {
                    setPixel(imageBuffer, width, nChannels, x, y, 255, 255, 255, 255);
                }
            }
        }
    }

    // Optional Task 4: compression ratio (rough)
    // - "rawBytes" is how many bytes your uncompressed RGBA buffer occupies in memory.
    // - "pngBytes" is the size of the encoded PNG data.
    // Note: lodepng::encode overload can encode to memory.
    std::vector<unsigned char> pngData;
    unsigned errMem = lodepng::encode(pngData, imageBuffer, width, height);
    if (errMem) {
        std::cout << "lodepng error encoding to memory: "
                  << lodepng_error_text(errMem) << std::endl;
        return (int)errMem;
    }

    const size_t rawBytes = (size_t)width * (size_t)height * (size_t)nChannels;
    const size_t pngBytes = pngData.size();

    std::cout << "Raw buffer size: " << rawBytes << " bytes\n";
    std::cout << "PNG size:        " << pngBytes << " bytes\n";
    if (pngBytes > 0) {
        double ratio = (double)rawBytes / (double)pngBytes;
        std::cout << "Compression ratio (raw/png): " << ratio << "x\n";
    }

    // Save to disk using your original path-based encoder
    int errorCode = lodepng::encode(outputFilename, imageBuffer, width, height);
    if (errorCode) {
        std::cout << "lodepng error encoding image: "
                  << lodepng_error_text(errorCode) << std::endl;
        return errorCode;
    }

    return 0;
}