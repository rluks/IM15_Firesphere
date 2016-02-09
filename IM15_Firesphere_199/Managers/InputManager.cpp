#include "InputManager.h"

using namespace Managers;

bool InputManager::switchShaders = false;
bool InputManager::rotate = false;

//handles input from user
InputManager::InputManager()
{


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

void InputManager::Rotate(float x, float y)
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


void InputManager::ChangeTimeDivider(int n)
{
	Rendering::Models::Sphere::ChangeTimeDivider(n);
}

void InputManager::ChangeTexture(int n, Core::IListener*& iListener)
{
	Scene_Manager* scene = dynamic_cast<Scene_Manager*>(iListener);
	scene->ChangeTexture(n);
	//Rendering::Models::Sphere::ChangeTexture(n);
}


void InputManager::ChangeFrequency(int n)
{
	Rendering::Models::Sphere::ChangeFrequency(n);
}

void InputManager::ChangeHeight(int n)
{
	Rendering::Models::Sphere::ChangeHeight(n);
}

void InputManager::ChangeThickness(int n)
{
	Rendering::Models::Sphere::ChangeThickness(n);

}

void InputManager::InverseNoise()
{
	Rendering::Models::Sphere::InverseNoise();
}

