#include "Models_Manager.h"

using namespace Managers;
using namespace Rendering;

Models_Manager::Models_Manager()
{
	Models::Sphere* sphere = new Models::Sphere();
	sphere->SetProgram(Shader_Manager::GetShader("textureShader"));
	//sphere->SetProgram(Shader_Manager::GetShader("noiseShader"));
	sphere->Create();
	gameModelList["fireball"] = sphere;

	Models::Sphere* sphereSky = new Models::Sphere();
	sphereSky->SetProgram(Shader_Manager::GetShader("spaceShader"));
	sphereSky->Create();
	sphereSky->SetTexture(Models::Model::spaceTexture);
	sphereSky->scale = 13.2f;
	sphereSky->rotationIncrement = 0.0025f;
	gameModelList["sky"] = sphereSky;

	//Models::Circle* circle = new Models::Circle();
	//circle->SetProgram(Shader_Manager::GetShader("textureShader"));
	//circle->Create();
	//gameModelList["circle"] = circle;
}

Models_Manager::~Models_Manager()
{
	//auto -it's a map iterator
	for (auto model : gameModelList)
	{
		delete model.second;
	}
	gameModelList.clear();
}

void Models_Manager::DeleteModel(const std::string& gameModelName)
{
	if (gameModelList.find(gameModelName) == gameModelList.end()){
		std::cout << "Unable to find desired model" << std::endl;
		return;
	}

	IGameObject* model = gameModelList[gameModelName];
	model->Destroy();
	gameModelList.erase(gameModelName);
}

const IGameObject& Models_Manager::GetModel(const std::string& gameModelName) const
{
	return (*gameModelList.at(gameModelName));
}

void Models_Manager::Update()
{
	//auto -it's a map iterator
	for (auto model : gameModelList)
	{
		model.second->Update();
	}
}

void Models_Manager::Draw()
{
	//auto -it's a map iterator
	for (auto model : gameModelList)
	{
		model.second->Draw();
	}
}
