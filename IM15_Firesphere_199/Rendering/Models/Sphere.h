#pragma once

#include "Model.h"

#include "..\..\myglm.h"

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

			glm::vec3 spherePosition;
			glm::mat4 identityMx;
			glm::mat4 modelmx;
			glm::mat4 rotated;
			glm::mat4 scaledMx;
			
			void ChangeTexture(int n);
			static void ChangeThickness(int n);
			static void ChangeHeight(int n);
			static void ChangeFrequency(int n);
			static void ChangeTimeDivider(int n); 
			static void InverseNoise();

			void SetTexture(tdogl::Bitmap bmp);//ballTexture is set implicitly
			float scale;//size of the sphere
			float rotationIncrement;

			//enum textures; 
			int currentTexture;
			static int sign;

			static double timeDivider;
			static double thickness;
			static double freq;
			static double height;
		};
	}
}