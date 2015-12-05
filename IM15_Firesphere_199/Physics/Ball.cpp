#include "Ball.h"

float Ball::radius = 0.125f;
glm::vec3 Ball::position = glm::vec3(1.0, radius, 1.0);
glm::vec3 Ball::velocity = 1.0f*glm::vec3(-1.0, 0, -1.0);
float Ball::velocityAngle = 0.0f;

Ball::Ball()
{

}

Ball::~Ball()
{
}

void Ball::Update()
{


}
