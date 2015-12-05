#pragma once

#include <iostream>
#include <string>
#include <iomanip>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "..\Managers\TimeManager.h"

class Ball
{
public:
	Ball();
	~Ball();

	static glm::vec3 position;
	static void Update();
};

