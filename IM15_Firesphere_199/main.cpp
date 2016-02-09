#include "main.h"

using namespace Core;
using namespace Init;
using namespace Managers;

IListener* scene;

std::string helpMsg = 
"Welcome to Firesphere 199";

int last_mx = 0, last_my = 0, cur_mx = 0, cur_my = 0;
int arcball_on = false;

//Methods handling input from user
void keySpecialUp(int key, int x, int y) {

	switch (key)
	{
	case GLUT_KEY_UP:
		InputManager::ChangeHeight(1);
		break;
	case GLUT_KEY_DOWN:
		InputManager::ChangeHeight(-1);
		break;
	case GLUT_KEY_LEFT:
		InputManager::ChangeTimeDivider(-1);
		break;
	case GLUT_KEY_RIGHT:
		InputManager::ChangeTimeDivider(1);
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
	if (key == 'b')
		InputManager::BackwardCamera();

	if (key == '1')
		InputManager::ChangeTexture(1, scene);
	if (key == '2')
		InputManager::ChangeTexture(2, scene);
	if (key == '3')
		InputManager::ChangeTexture(3, scene);

	if(key == 'i')
		InputManager::InverseNoise();

	if (key == '+')
		InputManager::ChangeFrequency(1);
	if (key == '-')
		InputManager::ChangeFrequency(-1);

	if (key == '>')
		InputManager::ChangeThickness(1);
	if (key == '<')
		InputManager::ChangeThickness(-1);

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



void PrintInstruction()
{
	std::cout << std::endl << std::endl;
	std::cout << "***************************************************" << std::endl;
	std::cout << "KEYBOARD INPUT:" << std::endl;

	std::cout << "[Right_Arrow_key]: To increase speed." << std::endl;
	std::cout << "[Left_Arrow_key]: To decrease speed." << std::endl;
	std::cout << "[Up_Arrow_key]: To increase height of disturbance." << std::endl;
	std::cout << "[Down_Arrow_key]: To decrease height of disturbance." << std::endl;

	std::cout << "[+]: To increase the noise's frequency." << std::endl;
	std::cout << "[-]: To decrease the noise's frequency." << std::endl;


	std::cout << "[>]: To increase the noise's density." << std::endl;
	std::cout << "[<]: To decrease the noise's density." << std::endl;

	std::cout << "[1]: To change texture to LAVA." << std::endl;
	std::cout << "[2]: To change texture to POISON." << std::endl;
	std::cout << "[3]: To change texture to PLASMA." << std::endl;

	std::cout << "[R]: To enable rotation." << std::endl;
	std::cout << "[W]: To move camera up." << std::endl;
	std::cout << "[S]: To move camera down." << std::endl;
	std::cout << "[A]: To move camera to the left." << std::endl;
	std::cout << "[D]: To move camera to the right." << std::endl;
	std::cout << "[F]: To move camera forward." << std::endl;
	std::cout << "[B]: To move camera backward." << std::endl;
	std::cout << "[I]: Inverse the noise." << std::endl;

	std::cout << "MOUSE INPUT:" << std::endl;
	std::cout << "Mouse scroll: To zoom in and out." << std::endl;
	std::cout << "Left Mouse Button + movement: camera movement." << std::endl;

	std::cout << "***************************************************";
	std::cout << std::endl << std::endl;
	
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

	scene = new Managers::Scene_Manager();
	Init::Init_GLUT::setListener(scene);

	//set input methods
	InputManager* input = new InputManager();
	glutMouseWheelFunc(mouseWheel);
	glutKeyboardFunc(keyboardInput);
	glutSpecialUpFunc(keySpecialUp);
	glutMouseFunc(onMouse);
	glutMotionFunc(onMotion);
	

	srand(static_cast <unsigned> (time(0)));
	
	PrintInstruction();

	//run it!
	Init_GLUT::run();

	delete scene;
	return 0;
}