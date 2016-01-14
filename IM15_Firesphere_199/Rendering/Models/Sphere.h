#pragma once

#include "Model.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <cmath>

#include "..\..\Physics\Ball.h"

#include "..\..\GLError.h"

namespace Rendering
{
	namespace Models
	{
		class Sphere : public Models::Model
		{
		public:
			Sphere();
			~Sphere();

			void Create();
			virtual void Draw() override final;
			virtual void Update() override final;

			static void DecreaseTimeDivider();
			static void IncreaseTimeDivider();

			glm::vec3 spherePosition;
			glm::mat4 identityMx;
			glm::mat4 modelmx;
			glm::mat4 rotated;
			glm::mat4 scaledMx;
			
			static void ChangeTexture(int n);

			void SetTexture(tdogl::Bitmap bmp);//ballTexture is set implicitly
			float scale;//size of the sphere
			float rotationIncrement;

			enum textures; 

			static int currentTexture;
			
			static int timeDividerChanger;
			double timeDivider;
		};
	}
}