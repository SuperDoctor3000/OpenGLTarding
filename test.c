#include "basics.c"
int main(){
	glfwInit();
	openWindow(800, 600, 4, 1, "TestGL");
	while (glfwGetWindowParam(GLFW_OPENED)) {
		glfwSwapBuffers();
	}
	glfwTerminate();
	return 0;
}
