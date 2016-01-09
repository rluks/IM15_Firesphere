#include "Scene_Manager.h"

using namespace Managers;

//stores shaders and models
//its state is updated every frame
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

	shader_manager->CreateProgram("spaceShader",
		"Shaders\\spaceTexture_Vertex_Shader.glsl",
		"Shaders\\spaceTexture_Fragment_Shader.glsl");

	//shader_manager->CreateProgram("noiseShader",
	//	"Shaders\\noise_Vertex_Shader.glsl",
	//	"Shaders\\noise_Fragment_Shader.glsl");

	models_manager = new Models_Manager();
}

Scene_Manager::~Scene_Manager()
{
	delete shader_manager;
	delete models_manager;
}

void Scene_Manager::notifyBeginFrame()
{	
	models_manager->Update();
	Camera::Update();
	//Ball::Update();
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
}

void Scene_Manager::notifyReshape(int width,
	int height,
	int previous_width,
	int previous_height)
{
	//nothing here for the moment 

}