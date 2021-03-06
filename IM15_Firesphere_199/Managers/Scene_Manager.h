#pragma once

//#include <glm/gtc/matrix_transform.hpp>
#include "..\..\packages\glm.0.9.6.3\build\native\include\glm\gtc\matrix_transform.hpp"

#include "Shader_Manager.h"
#include "Models_Manager.h"
#include "../Core/Init/IListener.h"

namespace Managers
{
	class Scene_Manager : public Core::IListener
	{
	public:
		Scene_Manager();
		~Scene_Manager();

		virtual void notifyBeginFrame();
		virtual void notifyDisplayFrame();
		virtual void notifyEndFrame();
		virtual void notifyReshape(int width,
			int height,
			int previous_width,
			int previous_height);
		void ChangeTexture(int n);
	private:
		Managers::Shader_Manager* shader_manager;
		Managers::Models_Manager* models_manager;
	};
}