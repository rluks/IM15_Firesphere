#include "Scene_Manager.h"

using namespace Managers;

Scene_Manager::Scene_Manager()
{
	glEnable(GL_DEPTH_TEST);

	shader_manager = new Shader_Manager();
	shader_manager->CreateProgram("colorShader",
		"Shaders\\Vertex_Shader.glsl",
		"Shaders\\Fragment_Shader.glsl");

	shader_manager->CreateProgram("textureShader",
		"Shaders\\Texture_Vertex_Shader.glsl",
		"Shaders\\Texture_Fragment_Shader.glsl");

	shader_manager->CreateProgram("textureAlphaShader",
		"Shaders\\TextureAlpha_Vertex_Shader.glsl",
		"Shaders\\TextureAlpha_Fragment_Shader.glsl");

	models_manager = new Models_Manager();

	Score = 0; 
	std::cout << "Score: " + std::to_string(Score) << std::endl;

	std::cout << "Loading physics..." << std::endl;

	float y = 0.125f;
	float pi = 3.14159265358979323846f;
	float angleDelta = pi / 12.0f;
	float endAngle = 2.0f * pi - angleDelta;
	float smallerRadius = 0.7f;
	int counter = 0;

	Ball::selectVelocity = true;
	Ball::enableMovement = false;

}

Scene_Manager::~Scene_Manager()
{
	delete shader_manager;
	delete models_manager;
}

void Scene_Manager::notifyBeginFrame()
{

	if (Ball::enableMovement){
		glm::vec2 ballPosition2D = glm::vec2(Ball::position.x, Ball::position.z);
		glm::vec2 ballVelocity2D = glm::vec2(Ball::velocity.x, Ball::velocity.z);
	}
		
	models_manager->Update();
	Camera::Update();
	Ball::Update();

	glm::vec3 normal = glm::vec3(0.0f - Ball::position.x, 0, 0.0f - Ball::position.z);
	float distanceFromCenter = glm::length(normal);

	if (distanceFromCenter + Ball::radius > 2.0f)
	{
		//std::cout << "reached outer wall of arena" << std::endl;

		Score -= 10;
		std::cout << "Score: " + std::to_string(Score) << std::endl;

		normal = glm::normalize(normal);
		normal = -1.0f * normal;

		glm::vec3 vel = Ball::velocity;
		Ball::velocity = vel - 2 * glm::dot(vel, normal) * normal;
	}
}

void Scene_Manager::notifyDisplayFrame()
{
	//TimeManager::CalculateFrameRate();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	models_manager->Draw();
}

void Scene_Manager::notifyEndFrame()
{
	//nothing here for the moment
	//Ball::Update();
}

void Scene_Manager::notifyReshape(int width,
	int height,
	int previous_width,
	int previous_height)
{
	//nothing here for the moment 

}