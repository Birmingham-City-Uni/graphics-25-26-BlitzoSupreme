#include <iostream>
#include <lodepng.h>

int main()
{
	std::string outputFilename = "output.png";

	const int width = 1920, height = 1080;
	const int nChannels = 4;

    struct float3 {
        float x, y, z;
    };

	// Set up an image buffer
	std::vector<uint8_t> imageBuffer(height*width*nChannels);


// Light + material settings
    float3 lightDir = { 0.0f, 0.0f, -1.0f };   
    float3 viewDir = { 0.0f, 0.0f, -1.0f };   

    // Normalise helper
    auto normalize = [](float3 v) {
        float len = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
        return float3{ v.x / len, v.y / len, v.z / len };
        };

    // Dot product
    auto dot = [](float3 a, float3 b) {
        return a.x * b.x + a.y * b.y + a.z * b.z;
        };

    // Reflect vector i around normal n
    auto reflect = [&](float3 i, float3 n) {
        float d = dot(i, n);
        return float3{
            i.x - 2.0f * d * n.x,
            i.y - 2.0f * d * n.y,
            i.z - 2.0f * d * n.z
        };
        };

    // Material coefficients
    float ka = 0.1f;  // ambient
    float kd = 0.7f;  // diffuse
    float ks = 0.5f;  // specular
    float shininess = 32.0f;

    lightDir = normalize(lightDir);
    viewDir = normalize(viewDir);

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            int pixelIdx = x + y * width;

            // Fake normal (sphere-like shading)
            float nx = (2.0f * x / width) - 1.0f;
            float ny = (2.0f * y / height) - 1.0f;
            float nz = 1.0f;

            float3 normal = normalize({ nx, ny, nz });

            // Diffuse
            float diff = std::max(dot(normal, lightDir), 0.0f);

            // Reflection vector
            float3 refl = reflect({ -lightDir.x, -lightDir.y, -lightDir.z }, normal);
            refl = normalize(refl);

            // Specular
            float spec = pow(std::max(dot(refl, viewDir), 0.0f), shininess);

            // Combine (Phong model)
            float intensity = ka + kd * diff + ks * spec;

            // Base colour (cyan-ish)
            float r = 0.0f;
            float g = 1.0f;
            float b = 1.0f;

            // Apply lighting
            r *= intensity;
            g *= intensity;
            b *= intensity;

            // Clamp to [0,255]
            imageBuffer[pixelIdx * nChannels + 0] = (uint8_t)(std::min(r, 1.0f) * 255);
            imageBuffer[pixelIdx * nChannels + 1] = (uint8_t)(std::min(g, 1.0f) * 255);
            imageBuffer[pixelIdx * nChannels + 2] = (uint8_t)(std::min(b, 1.0f) * 255);
            imageBuffer[pixelIdx * nChannels + 3] = 255;
        }
    }

    // Set pixel values to Cyan
    for(int y = 0; y < height; ++y) 
		for (int x = 0; x < width; ++x) {
			int pixelIdx = x + y * width;
			imageBuffer[pixelIdx * nChannels + 0] = 0; 
			imageBuffer[pixelIdx * nChannels + 1] = 255;
			imageBuffer[pixelIdx * nChannels + 2] = 255; 
			imageBuffer[pixelIdx * nChannels + 3] = 255; 
		}

    // **** End lovely rasteriser code ****

    // Save the image
    int errorCode;
        errorCode = lodepng::encode(outputFilename, imageBuffer, width, height);
        if (errorCode) { // check the error code, in case an error occurred.
            std::cout << "lodepng error encoding image: " << lodepng_error_text(errorCode) << std::endl;
            return errorCode;
        }

    return 0;
}
