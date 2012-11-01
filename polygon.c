#include <GL/glew.h>
#include <GL/glfw.h>
#include "gl_tools.c"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14155269f
/*
struct Cordinate
{
	float x;
	float y;
};

struct Cordinate
position(float radian)
{
	struct Cordinate pos;

	pos.x = cos(radian);
	pos.y = sin(radian);

	return(pos);
}

struct Cordinate*
polygon_vectors(unsigned vcount, float size)
{
	float distance = 2.0*PI/vcount;
	struct Cordinate *vectors = malloc(vcount * sizeof(struct Cordinate) + 1);
	*vectors = {0.0f, 0.0f};

	for(float pos = 0, struct Cordinate cord = vectors +1;
								pos <= 2.0*PI-distance;
								cord++, pos += distance)
		{
			*cord = position(pos);
		}

	return(vectors);
}

GLuint
*/
int
main(int argc, char **argv)
{
	if( !glfwInit() )
	{
		printf("Failed To Initiate glfw");
		return(1);
	}

	glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 2);
	glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	if( !glfwOpenWindow(840,640, 8,8,8, 0, 32, 0, GLFW_WINDOW) ) 
	{
		printf("Failed to Open Window\n");
		return(1);
	}

	glewExperimental = GL_TRUE;
	if( glewInit() != GLEW_OK )
	{
		printf("Failed to Init Glew\n");
		return(1);
	}

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(vao);

	MakeShader("polygon.vertex.shader", GL_VERTEX_SHADER);

	while(glfwGetWindowParam(GLFW_OPENED))
		glfwSwapBuffers();

	return(0);
}