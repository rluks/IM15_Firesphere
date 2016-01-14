#pragma once

#include "Core\Init\Init_GLUT.h"
#include "Managers\Scene_Manager.h"
#include "Managers\InputManager.h"

using namespace Core;
using namespace Init;

std::string helpMsg = 
"Welcome to Firesphere 199";

int last_mx = 0, last_my = 0, cur_mx = 0, cur_my = 0;
int arcball_on = false;

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

	if (key == '+')
		InputManager::DecreaseTimeDivider();
	if (key == '-')
		InputManager::IncreaseTimeDivider();

	if (key == '1')
		InputManager::ChangeTexture(1);
	if (key == '2')
		InputManager::ChangeTexture(2);
	if (key == '3')
		InputManager::ChangeTexture(3);
		
	return;
}

//arcball implementation
void onMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		arcball_on = true;
		last_mx = cur_mx = x;
		last_my = cur_my = y;
	}
	else {
		arcball_on = false;
	}
}

void onMotion(int x, int y) {
	if (arcball_on) {  // if left button is pressed
		cur_mx = x;
		cur_my = y;
	}
	if (cur_mx != last_mx || cur_my != last_my) {
		InputManager::Rotate((cur_mx - last_mx)*0.1f, (cur_my - last_my)*0.1f);
		last_mx = cur_mx;
		last_my = cur_my;
	}
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
	glutMouseFunc(onMouse);
	glutMotionFunc(onMotion);
	

	srand(static_cast <unsigned> (time(0)));

	//run it!
	Init_GLUT::run();

	delete scene;
	return 0;
}

