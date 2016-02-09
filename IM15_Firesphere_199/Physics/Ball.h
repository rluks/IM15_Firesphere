#pragma once

#include <iostream>
#include <string>
#include <iomanip>

#include "..\myglm.h"

#include "..\Managers\TimeManager.h"

class Ball
{
public:
	Ball();
	~Ball();

	static glm::vec3 position;
	static void Update();
};

