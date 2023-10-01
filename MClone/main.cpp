#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

using namespace glm;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		switch (key) {
		case GLFW_KEY_ESCAPE:
			glfwSetWindowShouldClose(window, GLFW_TRUE); break;
		}
	}
}

int main() {
	if (!glfwInit()) return -1;

	GLFWwindow* window = glfwCreateWindow(640, 480, "MClone", NULL, NULL);

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);

	if (!window) {
		glfwTerminate();
		return -1;
	}

	if (glewInit() != GLEW_OK) {
		glfwTerminate();
		return -1;
	}

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}