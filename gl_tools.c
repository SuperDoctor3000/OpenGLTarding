#include <stdio.h>
#include <stdlib.h>
#include "gl_tools.h"
#include <GL/glew.h>
#include <GL/glfw.h>

char *
LoadShaderSource(char *Filename)
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
	char *Source = LoadShaderSource(Filename);
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

