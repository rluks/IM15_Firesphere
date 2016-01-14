#include "Model.h"

using namespace Rendering;
using namespace Models;

tdogl::Bitmap Model::ballTexture = tdogl::Bitmap::bitmapFromFile("Textures/lava.png");
tdogl::Bitmap Model::ballTexture2 = tdogl::Bitmap::bitmapFromFile("Textures/poison.png");
tdogl::Bitmap Model::ballTexture3 = tdogl::Bitmap::bitmapFromFile("Textures/plasma.png");
tdogl::Bitmap Model::spaceTexture = tdogl::Bitmap::bitmapFromFile("Textures/sky.png");

Model::Model()
{
	verticesSize = 0;
	gTexture = NULL;

	start = TimeManager::GetTime();
}

Model::~Model()
{
	Destroy();
}

glm::vec3 Model::getNorm(const glm::vec3 &A, const glm::vec3 &B, const glm::vec3 &C)
{
	glm::vec3 normal = glm::cross(B - A, C - A);

	normal = glm::normalize(normal);

	return normal;
}

void Model::Draw()
{
	//this will be again overridden
}

void Model::Update()
{
	//this will be again overridden
}

void Model::SetProgram(GLuint program)
{
	this->program = program;

	camera = glGetUniformLocation(program, "camera");
	projection = glGetUniformLocation(program, "projection");
	model = glGetUniformLocation(program, "model");
	texture2d = glGetUniformLocation(program, "tex");

	lightColor = glGetUniformLocation(program, "lightColor");
	lightPosition = glGetUniformLocation(program, "lightPosition");

	_time = glGetUniformLocation(program, "time");


}

GLuint Model::GetVao() const
{
	return vao;
}

const std::vector<GLuint>& Model::GetVbos() const
{
	return vbos;
}

void Model::Destroy()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(vbos.size(), &vbos[0]);
	vbos.clear();
}


void ChangeTexture(int number)
{

}