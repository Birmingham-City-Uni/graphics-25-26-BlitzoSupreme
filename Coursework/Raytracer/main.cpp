#include <Eigen/Dense>
#include <lodepng.h>
#include <json/json.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include "BVHNode.hpp"
#include "Triangle.hpp"
#include "Scene.hpp"
#include "Camera.hpp"
#include "PointLight.hpp"
#include "DirectionalLight.hpp"
#include "LambertianShader.hpp"
#include "TexturedLambertianShader.hpp"
#include "PhongShader.hpp"
#include "MirrorShader.hpp"
#include "TexCoordTestShader.hpp"
#include "Model.hpp"
#include <fstream>

/// <summary>
/// Load a JSON config file using the nlohmann library.
/// </summary>
nlohmann::json loadConfig(const std::string& filename)
{
	std::ifstream configStream(filename);
	if (!configStream.is_open()) {
		std::cerr << "ERROR: Could not open config file: " << filename << std::endl;
		throw std::runtime_error("Config file not found: " + filename);
	}
	nlohmann::json config = nlohmann::json::parse(configStream);
	return config;
}

float radians(const float degrees) {

	if (degrees == 0.0f) {
		float radians = degrees;
		return radians;
	}
	else {
		float radians = degrees * (M_PI / 180);
		return radians;;
	}
}

struct ModelSpawner {
	Scene& scene;
	std::vector<std::shared_ptr<Model>> models;

	std::shared_ptr<BVHNode> addObject(const std::string& meshPath, const Shader* shader, int bvhDepth = 4, Eigen::Vector3f position = Eigen::Vector3f::Zero(), float rotX = 0.f, float rotY = 0.f, float rotZ = 0.f) {

		models.emplace_back(std::make_shared<Model>(meshPath.c_str()));
		std::shared_ptr <Model>& model = models.back();

		if (model->nfaces() == 0) {
			std::cerr << "WARNING: Model has no faces, skipping: " << meshPath << std::endl;
			models.pop_back();
			return nullptr;
		}

		Eigen::Matrix4f transform = makeTranslationMatrix(position) * rotateX(rotX) * rotateY(rotY) * rotateZ(rotZ);
		auto node = std::make_shared<BVHNode>(*model, shader, bvhDepth, transform, nullptr, false);
		scene.renderables.push_back(node);
		return node;
	}
};

/// <summary>
/// Load an Eigen Vector3f from a config file.
/// Call as for example loadVec3FromConfig(config["myVector3"]);
/// </summary>
Eigen::Vector3f loadVec3FromConfig(const nlohmann::json& config)
{
	return Eigen::Vector3f(config[0], config[1], config[2]);
}

int main(int argc, char* argv[]) {

	// *** Load the config file ***
	auto config = loadConfig("../config/config.json");

	const int pixHeight = config["pixHeight"], pixWidth = config["pixWidth"];
	const int nChannels = 4;

	// Camera ported from rasterizer:
	// cameraToWorld = T(2, -5, 2) * Rx(-10) * Rz(180) * Ry(50)
	// Decomposed into position, forward and up vectors for the raytracer Camera.
	Eigen::Matrix4f camRot = rotateX(radians(-10.f)) * rotateZ(radians(180.f)) * rotateY(radians(50.f));
	Eigen::Vector3f cameraPos(2.f, -5.0f, 2.f);
	Eigen::Vector3f cameraForward = (camRot.block<3, 3>(0, 0) * Eigen::Vector3f(0.f, 0.f, 1.f)).normalized();
	Eigen::Vector3f cameraUp = (camRot.block<3, 3>(0, 0) * Eigen::Vector3f(0.f, -1.f, 0.f)).normalized();

	// *** Set up camera and output image ***
	Camera cam(
		cameraPos,
		cameraForward,
		cameraUp,
		pixWidth, pixHeight,
		config["cameraFov"]);

	std::vector<uint8_t> outImage(pixHeight * pixWidth * nChannels);

	// *** Load room textures ***
	std::vector<uint8_t> r1T;
	unsigned int r1TW, r1TH;
	lodepng::decode(r1T, r1TW, r1TH, "../models/Room1Tex.png");

	std::vector<uint8_t> r2T;
	unsigned int r2TW, r2TH;
	lodepng::decode(r2T, r2TW, r2TH, "../models/Room2Tex.png");

	std::vector<uint8_t> r3T;
	unsigned int r3TW, r3TH;
	lodepng::decode(r3T, r3TW, r3TH, "../models/Room3Tex.png");

	std::vector<uint8_t> r4T;
	unsigned int r4TW, r4TH;
	lodepng::decode(r4T, r4TW, r4TH, "../models/Room4Tex.png");

	std::vector<uint8_t> r5T;
	unsigned int r5TW, r5TH;
	lodepng::decode(r5T, r5TW, r5TH, "../models/Room5Tex.png");

	std::vector<uint8_t> r6T;
	unsigned int r6TW, r6TH;
	lodepng::decode(r6T, r6TW, r6TH, "../models/Room6Tex.png");

	std::vector<uint8_t> r7T;
	unsigned int r7TW, r7TH;
	lodepng::decode(r7T, r7TW, r7TH, "../models/Room7Tex.png");

	std::vector<uint8_t> r8T;
	unsigned int r8TW, r8TH;
	lodepng::decode(r8T, r8TW, r8TH, "../models/Room8Tex.png");

	std::vector<uint8_t> r9T;
	unsigned int r9TW, r9TH;
	lodepng::decode(r9T, r9TW, r9TH, "../models/Room9Tex.png");

	std::vector<uint8_t> r10T;
	unsigned int r10TW, r10TH;
	lodepng::decode(r10T, r10TW, r10TH, "../models/Room10Tex.png");

	std::vector<uint8_t> r11T;
	unsigned int r11TW, r11TH;
	lodepng::decode(r11T, r11TW, r11TH, "../models/Room11Tex.png");

	std::vector<uint8_t> r12T;
	unsigned int r12TW, r12TH;
	lodepng::decode(r12T, r12TW, r12TH, "../models/Room12Tex.png");

	std::vector<uint8_t> r13T;
	unsigned int r13TW, r13TH;
	lodepng::decode(r13T, r13TW, r13TH, "../models/Room13Tex.png");

	// *** Load Heather textures ***
	std::vector<uint8_t> hHairT;
	unsigned int hHairTW, hHairTH;
	lodepng::decode(hHairT, hHairTW, hHairTH, "../models/hair.png");

	std::vector<uint8_t> hHeadT;
	unsigned int hHeadTW, hHeadTH;
	lodepng::decode(hHeadT, hHeadTW, hHeadTH, "../models/head.png");

	std::vector<uint8_t> hSkirtT;
	unsigned int hSkirtTW, hSkirtTH;
	lodepng::decode(hSkirtT, hSkirtTW, hSkirtTH, "../models/skirt.png");

	std::vector<uint8_t> hVestT;
	unsigned int hVestTW, hVestTH;
	lodepng::decode(hVestT, hVestTW, hVestTH, "../models/vest.png");

	// *** Load Doug textures ***
	std::vector<uint8_t> dArmsT;
	unsigned int dArmsTW, dArmsTH;
	lodepng::decode(dArmsT, dArmsTW, dArmsTH, "../models/Darms.png");

	std::vector<uint8_t> dBodyT;
	unsigned int dBodyTW, dBodyTH;
	lodepng::decode(dBodyT, dBodyTW, dBodyTH, "../models/Dbody.png");

	std::vector<uint8_t> dHairT;
	unsigned int dHairTW, dHairTH;
	lodepng::decode(dHairT, dHairTW, dHairTH, "../models/Dhair.png");

	std::vector<uint8_t> dHeadT;
	unsigned int dHeadTW, dHeadTH;
	lodepng::decode(dHeadT, dHeadTW, dHeadTH, "../models/Dhead.png");

	// *** Room shaders ***
	TexturedLambertianShader r1TShader(&r1T, r1TW, r1TH);
	TexturedLambertianShader r2TShader(&r2T, r2TW, r2TH);
	TexturedLambertianShader r3TShader(&r3T, r3TW, r3TH);
	TexturedLambertianShader r4TShader(&r4T, r4TW, r4TH);
	TexturedLambertianShader r5TShader(&r5T, r5TW, r5TH);
	TexturedLambertianShader r6TShader(&r6T, r6TW, r6TH);
	TexturedLambertianShader r7TShader(&r7T, r7TW, r7TH);
	TexturedLambertianShader r8TShader(&r8T, r8TW, r8TH);
	TexturedLambertianShader r9TShader(&r9T, r9TW, r9TH);
	TexturedLambertianShader r10TShader(&r10T, r10TW, r10TH);
	TexturedLambertianShader r11TShader(&r11T, r11TW, r11TH);
	TexturedLambertianShader r12TShader(&r12T, r12TW, r12TH);
	TexturedLambertianShader r13TShader(&r13T, r13TW, r13TH);

	// *** Heather shaders ***
	TexturedLambertianShader hHairTShader(&hHairT, hHairTW, hHairTH);
	TexturedLambertianShader hHeadTShader(&hHeadT, hHeadTW, hHeadTH);
	TexturedLambertianShader hSkirtTShader(&hSkirtT, hSkirtTW, hSkirtTH);
	TexturedLambertianShader hVestTShader(&hVestT, hVestTW, hVestTH);

	// *** Doug shaders ***
	TexturedLambertianShader dArmsTShader(&dArmsT, dArmsTW, dArmsTH);
	TexturedLambertianShader dBodyTShader(&dBodyT, dBodyTW, dBodyTH);
	TexturedLambertianShader dHairTShader(&dHairT, dHairTW, dHairTH);
	TexturedLambertianShader dHeadTShader(&dHeadT, dHeadTW, dHeadTH);

	// *** Set up scene ***
	Scene scene;
	ModelSpawner builder{ scene };

	// All objects share the same world transform ported from the rasterizer:
	// T(-28, 5, 25) * Rx(180) * Ry(100) * Rz(0)
	Eigen::Vector3f scenePos(-28.0f, 5.0f, 25.f);
	float rX = radians(180.f);
	float rY = radians(100.f);
	float rZ = radians(0.f);

	// Room meshes
	builder.addObject("../models/Room1.obj", &r1TShader, 4, scenePos, rX, rY, rZ);
	builder.addObject("../models/Room2.obj", &r2TShader, 4, scenePos, rX, rY, rZ);
	builder.addObject("../models/Room3.obj", &r3TShader, 4, scenePos, rX, rY, rZ);
	builder.addObject("../models/Room4.obj", &r4TShader, 4, scenePos, rX, rY, rZ);
	builder.addObject("../models/Room5.obj", &r5TShader, 4, scenePos, rX, rY, rZ);
	builder.addObject("../models/Room6.obj", &r6TShader, 4, scenePos, rX, rY, rZ);
	builder.addObject("../models/Room7.obj", &r7TShader, 4, scenePos, rX, rY, rZ);
	builder.addObject("../models/Room8.obj", &r8TShader, 4, scenePos, rX, rY, rZ);
	builder.addObject("../models/Room9.obj", &r9TShader, 4, scenePos, rX, rY, rZ);
	builder.addObject("../models/Room10.obj", &r10TShader, 4, scenePos, rX, rY, rZ);
	builder.addObject("../models/Room11.obj", &r11TShader, 4, scenePos, rX, rY, rZ);
	builder.addObject("../models/Room12.obj", &r12TShader, 4, scenePos, rX, rY, rZ);
	builder.addObject("../models/Room13.obj", &r13TShader, 4, scenePos, rX, rY, rZ);

	// Heather
	builder.addObject("../models/Heather_HAIR.obj", &hHairTShader, 4, scenePos, rX, rY, rZ);
	builder.addObject("../models/Heather_HEAD.obj", &hHeadTShader, 4, scenePos, rX, rY, rZ);
	builder.addObject("../models/Heather_SKIRT.obj", &hSkirtTShader, 4, scenePos, rX, rY, rZ);
	builder.addObject("../models/Heather_VEST.obj", &hVestTShader, 4, scenePos, rX, rY, rZ);

	// Doug
	builder.addObject("../models/Doug_ARMS.obj", &dArmsTShader, 4, scenePos, rX, rY, rZ);
	builder.addObject("../models/Doug_BODY.obj", &dBodyTShader, 4, scenePos, rX, rY, rZ);
	builder.addObject("../models/Doug_HAIR.obj", &dHairTShader, 4, scenePos, rX, rY, rZ);
	builder.addObject("../models/Doug_HEAD.obj", &dHeadTShader, 4, scenePos, rX, rY, rZ);

	// *** Add lights to scene ***
	Eigen::Vector3f ambientLight(0.35f, 0.32f, 0.28f);  // brighter, slightly warm ambient

	std::vector<std::unique_ptr<Light>> lightSources;

	// Strong window light from upper-left (key light — mimics the window in reference)
	lightSources.push_back(std::make_unique<DirectionalLight>(
		Eigen::Vector3f(0.6f, 0.5f, 0.3f).normalized(),
		Eigen::Vector3f(0.75f, 0.68f, 0.55f)));  // bright warm-white, main illumination

	// Cool secondary fill from right side (bounced from walls)
	lightSources.push_back(std::make_unique<DirectionalLight>(
		Eigen::Vector3f(-0.5f, 0.3f, -0.4f).normalized(),
		Eigen::Vector3f(0.18f, 0.17f, 0.20f)));  // subtle cool fill

	// Soft upward bounce light (floor reflection, brightens lower geometry)
	lightSources.push_back(std::make_unique<DirectionalLight>(
		Eigen::Vector3f(0.f, -1.f, 0.f).normalized(),
		Eigen::Vector3f(0.12f, 0.10f, 0.08f)));  // warm floor bounce

	// Rear/back wall fill (stops back wall going completely black)
	lightSources.push_back(std::make_unique<DirectionalLight>(
		Eigen::Vector3f(0.f, 0.2f, -1.f).normalized(),
		Eigen::Vector3f(0.10f, 0.09f, 0.08f)));  // subtle back fill

	// *** Render the scene ***

	// Shuffling the scanline order gets better CPU usage between threads
	// when some lines take longer to render than others.
	std::vector<unsigned int> scanlines(pixHeight);
	for (int i = 0; i < pixHeight; ++i) scanlines[i] = i;

	if (config["shuffleScanlines"]) {
		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(scanlines.begin(), scanlines.end(), g);
	}

	auto startTime = std::chrono::steady_clock::now();

#pragma omp parallel for
	for (int y = 0; y < pixHeight; ++y) {
		for (int x = 0; x < pixWidth; ++x) {
			Ray ray = cam.getRay(x, scanlines[y]);
			HitInfo hitInfo;
			if (scene.intersect(ray, 1e-6f, 1e6f, hitInfo, VISIBLE_BITMASK)) {
				Eigen::Vector3f color = hitInfo.shader->getColor(
					hitInfo, &scene,
					lightSources, ambientLight,
					0, config["maxBounces"]);

				color.x() = std::min(color.x(), 1.f);
				color.y() = std::min(color.y(), 1.f);
				color.z() = std::min(color.z(), 1.f);

				int line = scanlines[y];
				outImage[(x + line * pixWidth) * nChannels + 0] = color.x() * 255;
				outImage[(x + line * pixWidth) * nChannels + 1] = color.y() * 255;
				outImage[(x + line * pixWidth) * nChannels + 2] = color.z() * 255;
				outImage[(x + line * pixWidth) * nChannels + 3] = 255;
			}
			else {
				int line = (pixHeight - scanlines[y]) - 1;
				outImage[(x + line * pixWidth) * nChannels + 0] = 0;
				outImage[(x + line * pixWidth) * nChannels + 1] = 0;
				outImage[(x + line * pixWidth) * nChannels + 2] = 0;
				outImage[(x + line * pixWidth) * nChannels + 3] = 255;
			}
		}
		if (omp_get_thread_num() == omp_get_num_threads() - 1) {
			std::clog << "\rScanlines remaining: " << (pixHeight - y) << ' ' << std::flush;
		}
	}

	auto renderTime = std::chrono::steady_clock::now() - startTime;
	std::cout << "Render duration " << std::chrono::duration_cast<std::chrono::milliseconds>(renderTime).count() * 1e-3f << " seconds." << std::endl;

	// *** Save the output image ***
	int errorCode;
	errorCode = lodepng::encode(config["outputFilename"], outImage, pixWidth, pixHeight);
	if (errorCode) {
		std::cout << "lodepng error encoding image: " << lodepng_error_text(errorCode) << std::endl;
		return errorCode;
	}

	return 0;
}