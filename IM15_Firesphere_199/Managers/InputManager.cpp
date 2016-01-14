#include "InputManager.h"


bool InputManager::switchShaders = false;
bool InputManager::rotate = false;

//handles input from user
InputManager::InputManager()
{
	bool Continue = TRUE;
	int KeyEvents = 0;
	int MouseEvents = 0;

	hIn = GetStdHandle(STD_INPUT_HANDLE);
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	//cout << "Key Events   : " << endl;
	//cout << "Mouse Events : " << flush;

	KeyWhere.X = 15;
	KeyWhere.Y = 0;
	MouseWhere.X = 15;
	MouseWhere.Y = 1;
	EndWhere.X = 0;
	EndWhere.Y = 3;


}


//methods for which change camera (zoom, pos, rotation)
void InputManager::zoomIn()
{
	Camera::UpdateProjectionMatrix(-5.0f);
}

void InputManager::zoomOut()
{
	Camera::UpdateProjectionMatrix(5.0f);
}

void InputManager::Rotate()
{
	rotate = !rotate;

	if (rotate){
		Camera::Rotate();
	}
	else{
		Camera::DisableRotate();
	}
}

void InputManager::Rotate(double x, double y)
{
	Camera::Rotate(x, y);
}


void InputManager::UpCamera()
{
	Camera::Translate(0.5f, 0.0f, 0.0f);
}

void InputManager::DownCamera()
{
	Camera::Translate(-0.5f, 0.0f, 0.0f);
}

void InputManager::LeftCamera()
{
	Camera::Translate(0.0f, -0.5f, 0.0f);
}

void InputManager::RightCamera()
{
	Camera::Translate(0.0f, 0.5f, 0.0f);
}

void InputManager::ForwardCamera()
{
	Camera::Translate(0.0f, 0.0f, -0.5f);
}

void InputManager::BackwardCamera()
{
	Camera::Translate(0.0f, 0.0f, 0.5f);
}

void InputManager::DecreaseTimeDivider()
{
	Rendering::Models::Sphere::DecreaseTimeDivider();
}


void InputManager::IncreaseTimeDivider()
{
	Rendering::Models::Sphere::IncreaseTimeDivider();
}

void InputManager::ChangeTexture(int n)
{
	Rendering::Models::Sphere::ChangeTexture(n);
}