#pragma once

#include "Core\Init\Init_GLUT.h"
#include "Managers\Scene_Manager.h"
#include "Managers\InputManager.h"

using namespace Core;
using namespace Init;

std::string helpMsg = 
"Welcome to Firesphere 199";

//Methods handling input from user
void keySpecialUp(int key, int x, int y) {

	switch (key)
	{
	case GLUT_KEY_LEFT:
		//TODO
		break;
	case GLUT_KEY_RIGHT:
		//TODO
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

//main
int main(int argc, char **argv)
{
	std::cout << helpMsg << std::endl;

	WindowInfo window(std::string("Firesphere 199"),
		400, 200,//position
		800, 600, //size
		true);//reshape

	//initialize
	ContextInfo context(3, 3, true);
	FramebufferInfo frameBufferInfo(true, true, true, true);
	Init_GLUT::init(window, context, frameBufferInfo);

	IListener* scene = new Managers::Scene_Manager();
	Init::Init_GLUT::setListener(scene);

	//set input methods
	InputManager* input = new InputManager();
	glutMouseWheelFunc(mouseWheel);
	glutKeyboardFunc(keyboardInput);
	glutSpecialUpFunc(keySpecialUp);

	srand(static_cast <unsigned> (time(0)));

	//run it!
	Init_GLUT::run();

	delete scene;
	return 0;
}

