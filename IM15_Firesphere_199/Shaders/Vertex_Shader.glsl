#version 330 core

uniform mat4 camera;
uniform mat4 projection;
uniform mat4 model;

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec4 in_color;
layout(location = 2) in vec2 vertTexCoord; //this is the texture coord
 
out vec4 color;
out vec2 fragTexCoord;

void main()
{
	fragTexCoord = vertTexCoord;
	color = in_color;

	gl_Position = projection * camera * model * vec4(in_position, 1.0);//w is 1.0
	//projection is applied latest
}