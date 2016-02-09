#pragma once

//#include <windows.h>
#include <iostream>

#include "..\OpenGLIncludes.h"
#include "..\Rendering\Models\Model.h"
#include "..\Rendering\Models\Sphere.h"
#include "..\Rendering\Camera.h"
#include "..\Physics\Ball.h"

#include "..\Core\Init\IListener.h"
#include "..\Managers\Scene_Manager.h"

using namespace std;

namespace Managers
{
class InputManager
{
	public:
		InputManager();

		//void SpecialInput(int key, int x, int y);

		static void zoomIn();
		static void zoomOut();
		static void Rotate();
		static void Rotate(double dx, double dy);

		static void UpCamera();
		static void DownCamera();
		static void LeftCamera();
		static void RightCamera();
		static void ForwardCamera();
		static void BackwardCamera();

		static void InverseNoise();

		static void ChangeTimeDivider(int n);
		static void ChangeTexture(int n, Core::IListener*& iListener);
		static void ChangeFrequency(int n);
		static void ChangeHeight(int n);
		static void ChangeThickness(int n);

		static bool switchShaders;

	private:

		bool Continue;
		int KeyEvents;
		int MouseEvents;

		static bool rotate;
};
}
