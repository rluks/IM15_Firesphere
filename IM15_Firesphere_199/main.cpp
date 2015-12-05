#pragma once

#include "Core\Init\Init_GLUT.h"
#include "Managers\Scene_Manager.h"
#include "Managers\InputManager.h"

using namespace Core;
using namespace Init;

std::string helpMsg = 
"Welcome to Firesphere 199";
void SpecialInput(int key, int x, int y)
{

	switch (key)
	{
	case GLUT_KEY_UP:
		InputManager::ConfirmVelocity();
		break;
	case GLUT_KEY_DOWN:
		InputManager::SelectVelocity();
		break;
	case GLUT_KEY_LEFT:
		InputManager::left();
		break;
	case GLUT_KEY_RIGHT:
		InputManager::right();
		break;
	}
}

void keySpecialUp(int key, int x, int y) {

	switch (key)
	{
	case GLUT_KEY_LEFT:
		InputManager::stopTurning();
		break;
	case GLUT_KEY_RIGHT:
		InputManager::stopTurning();
		break;
	}
}

void mouseWheel(int button, int dir, int x, int y)
{
	if (dir > 0)
	{
		InputManager::zoomIn();
	}
	else
	{
		InputManager::zoomOut();
	}

	return;
}

void keyboardInput(unsigned char key, int x, int y)
{
	if (key == 'r')
		InputManager::Rotate();

	if (key == 'c')
		InputManager::switchCamera();

	if (key == 'w')
		InputManager::UpCamera();
	if (key == 's')
		InputManager::DownCamera();
	if (key == 'a')
		InputManager::LeftCamera();
	if (key == 'd')
		InputManager::RightCamera();
	if (key == 'f')
		InputManager::ForwardCamera();
	if (key == 'v')
		InputManager::BackwardCamera();

	return;
}

int main(int argc, char **argv)
{
	std::cout << helpMsg << std::endl;

	WindowInfo window(std::string("Firesphere 199"),
		400, 200,//position
		800, 600, //size
		true);//reshape

	ContextInfo context(3, 3, true);
	FramebufferInfo frameBufferInfo(true, true, true, true);
	Init_GLUT::init(window, context, frameBufferInfo);

	IListener* scene = new Managers::Scene_Manager();
	Init::Init_GLUT::setListener(scene);

	InputManager* input = new InputManager();
	glutSpecialFunc(SpecialInput);
	glutMouseWheelFunc(mouseWheel);
	glutKeyboardFunc(keyboardInput);
	glutSpecialUpFunc(keySpecialUp);

	srand(static_cast <unsigned> (time(0)));

	Init_GLUT::run();

	delete scene;
	return 0;
}

