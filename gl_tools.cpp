#include <stdio.h>
#include <stdlib.h>
//#include "gl_tools.h"
#include <GL/glew.h>
#include <GL/glfw.h>
#include <vector>
//#include <gsl>

typedef struct{
	GLuint shader;
	GLuint vertexarray;
	GLuint vertexbuffer;
	GLuint elementbuffer;
	std::vector<float> data;
} model;

char *LoadFile(char *Filename)
{
	long Length;
	FILE *SourceFile = fopen(Filename, "rb");

	fseek(SourceFile, 0, SEEK_END);
	Length = ftell(SourceFile) + 1;
	rewind(SourceFile);

	char* Source = (char*)malloc(sizeof(char) * Length+1);
	fread(Source, 1, Length, SourceFile);
	*(Source + Length) = 0;

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

		char *info_log = (char*)malloc(log_lenght +1);
		glGetShaderInfoLog(Shader, log_lenght, NULL, info_log);
		printf("%s\n", info_log);
	}

	printf("%d\n", sizeof(GLint) );
	free(Source);
	return(Shader);
}

model makeModel(GLuint shader, std::vector<float> data) {
	model output;
	output.shader = shader;
	output.data = data;
	glGenBuffers(1, &output.vertexbuffer);
	return output;
}
