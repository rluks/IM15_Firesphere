#include "Models_Manager.h"

using namespace Managers;
using namespace Rendering;

//stores 3d models
Models_Manager::Models_Manager()
{
	//firesphere
	Models::Sphere* sphere = new Models::Sphere();
	sphere->SetProgram(Shader_Manager::GetShader("textureShader"));
	sphere->Create();
	sphere->currentTexture = 1;
	gameModelList["fireball"] = sphere;

	//the skybox
	Models::Sphere* sphereSky = new Models::Sphere();
	sphereSky->SetProgram(Shader_Manager::GetShader("spaceShader"));
	sphereSky->Create();
	sphereSky->SetTexture(Models::Model::spaceTexture);
	sphere->currentTexture = 0;
	sphereSky->scale = 13.2f;
	sphereSky->rotationIncrement = 0.0025f;
	gameModelList["sky"] = sphereSky;
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

void Models_Manager::ChangeTexture(int n)
{
	Models::Sphere* sphere = dynamic_cast<Models::Sphere*>(gameModelList["fireball"]);
	sphere->currentTexture = n;
	gameModelList["fireball"] = sphere;
}
