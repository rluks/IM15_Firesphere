#include "Models_Manager.h"

using namespace Managers;
using namespace Rendering;

Models_Manager::Models_Manager()
{
	Models::Sphere* sphere = new Models::Sphere();
	sphere->SetProgram(Shader_Manager::GetShader("textureShader"));
	sphere->Create();
	gameModelList["sphere"] = sphere;

	Models::Circle* circle = new Models::Circle();
	circle->SetProgram(Shader_Manager::GetShader("textureShader"));
	circle->Create();
	gameModelList["circle"] = circle;

	Models::Ray* ray = new Models::Ray();
	ray->SetProgram(Shader_Manager::GetShader("colorShader"));
	ray->Create();
	gameModelList["ray"] = ray;
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

void Models_Manager::AddLine(glm::vec3 a, glm::vec3 b, const glm::vec4 &color)
{
	std::string mapKey = "line" + std::to_string(gameModelList.size());
	//std::cout << "mapkey" << mapKey << std::endl;

	Models::Line* line = new Models::Line(a, b, color);
	line->SetProgram(Shader_Manager::GetShader("colorShader"));
	line->Create();
	gameModelList[mapKey] = line;
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

std::string Models_Manager::GetColorName(const glm::vec4 &color)
{
	glm::vec4 red = glm::vec4(1, 0, 0, 1);
	glm::vec4 green = glm::vec4(0, 1, 0, 1);
	glm::vec4 blue = glm::vec4(0, 0, 1, 1);
	glm::vec4 yellow = glm::vec4(1, 1, 0, 1);
	glm::vec4 grey = glm::vec4(0.5, 0.5, 0.5, 1);
	glm::vec4 pink = glm::vec4(1, 0, 1, 1);
	glm::vec4 azure = glm::vec4(0, 1, 1, 1);

	if (color == red)
		return "red";
	else if (color == green)
		return "green";
	else if (color == blue)
		return "blue";
	else if (color == yellow)
		return "yellow";
	else if (color == grey)
		return "grey";
	else if (color == pink)
		return "pink";
	else if (color == azure)
		return "azure";
	else{
		//std::string colorStr = std::to_string(color.a) + "," + std::to_string(color.g) + "," + std::to_string(color.b);
		std::string colorStr = "UNKNOWN";
		return colorStr;
	}

}
