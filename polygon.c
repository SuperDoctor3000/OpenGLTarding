#include <GL/glew.h>
#include <GL/glfw.h>
#include "gl_tools.c"
#include "openWindow.c"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14155269f

typedef struct
{
	float x;
	float y;
} Cordinate;

Cordinate
position(float radian)
{
	Cordinate pos;

	pos.x = cos(radian);
	pos.y = sin(radian);

	return(pos);
}

Cordinate*
polygon_vectors(unsigned vcount, float size)
{
	float distance = 2.0*PI/vcount;
	Cordinate *vectors = malloc(vcount+1 * sizeof(Cordinate));
	vectors[0].x = 0.0f;
	vectors[0].y = 0.0f;
	int i;
	for(float pos = 0, i = 1;
								pos <= 2.0*PI-distance;
								i+=1, pos += distance)
		{
			vectors[(int)i] = position(pos);
		}

	return(vectors);
}
int
main(int argc, char **argv)
{
	if( !glfwInit() )
	{
		printf("Failed To Initiate glfw");
		return(1);
	}

	openWindow(800, 600, 3, 2, "Window");

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(vao);

	MakeShader("polygon.vertex.shader", GL_VERTEX_SHADER);

	while(glfwGetWindowParam(GLFW_OPENED))
		glfwSwapBuffers();

	return(0);
}
