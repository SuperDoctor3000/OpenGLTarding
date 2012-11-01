#include <GL/glew.h>
#include <GL/glfw.h>
#include <stdio.h>
int openWindow(int width, int height, int majVer, int minVer, char* title) {
	glfwOpenWindowHint( GLFW_OPENGL_VERSION_MAJOR, majVer );
	glfwOpenWindowHint( GLFW_OPENGL_VERSION_MINOR, minVer );
	glfwOpenWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
	glfwOpenWindowHint( GLFW_WINDOW_NO_RESIZE, GL_FALSE );
	if (glfwOpenWindow( width, height, 0, 0, 0, 0, 0, 0, GLFW_WINDOW ) != GL_TRUE) {
		printf("failed to open window");
		return 1;
	}
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		printf("Glew failed to initialize");
		return 2;
	}
	glfwSetWindowTitle(title);
	return 0;
}
