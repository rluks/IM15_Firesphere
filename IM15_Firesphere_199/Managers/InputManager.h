#pragma once

#include <windows.h>
#include <iostream>

#include "..\OpenGLIncludes.h"
#include "..\Rendering\Models\Model.h"
#include "..\Rendering\Camera.h"
#include "..\Physics\Ball.h"

using namespace std;

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

		static bool switchShaders;

	private:
		HANDLE hIn;
		HANDLE hOut;
		COORD KeyWhere;
		COORD MouseWhere;
		COORD EndWhere;
		INPUT_RECORD InRec;
		DWORD NumRead;

		bool Continue;
		int KeyEvents;
		int MouseEvents;

		static bool rotate;
};
