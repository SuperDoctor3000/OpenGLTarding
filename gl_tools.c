#include <stdio.h>
#include <stdlib.h>
//#include "gl_tools.h"
#include <GL/glew.h>
#include <GL/glfw.h>
//#include <gsl>

typedef struct{
	GLuint shader;
	GLuint vertexarray;
	GLuint vertexbuffer;
	GLuint elementbuffer;
	float* data;
	int size;
} model;

char *LoadFile(char *Filename)
{
	long Lenght;
	char *Source;
	FILE *SourceFile = fopen(Filename, "rb");

	fseek(SourceFile, 0, SEEK_END);
	Lenght = ftell(SourceFile) + 1;
	rewind(SourceFile);

	Source = malloc(Lenght + 1);
	fread(Source, 1, Lenght, SourceFile);
	*(Source + Lenght) = 0;

	return(Source);
}

GLuint
MakeShader(char *Filename, GLenum Type) 
{
	char *Source = LoadFile(Filename);
	GLuint Shader = glCreateShader(Type);

	glShaderSource(Shader, 1, (const GLchar **)&Source, NULL);
	glCompileShader(Shader);
	GLint status;
	glGetShaderiv(Shader, GL_COMPILE_STATUS, &status);
	if( status != GL_TRUE )
	{
		GLint log_lenght;
		glGetShaderiv(Shader, GL_INFO_LOG_LENGTH, &log_lenght);

		char *info_log = malloc(log_lenght +1);
		glGetShaderInfoLog(Shader, log_lenght, NULL, info_log);
		printf("%s\n", info_log);
	}

	printf("%d\n", sizeof(GLint) );
	free(Source);
	return(Shader);
}

model makeModel(GLuint shader, float* data, int size) {
	model output;
	output.shader = shader;
	output.data = data;
	output.size = size;
	glGenBuffers(1, &output.vertexbuffer);
	return output;
}

void updateModel(model updatee, GLenum style) {
	glBindBuffer(GL_ARRAY_BUFFER, updatee.vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, updatee.size, updatee.data, style);
}
