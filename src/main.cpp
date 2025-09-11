#include <iostream>
#include <cstdlib>
#include <GLFW/glfw3.h>

int main() {
	GLFWwindow* window;

	// Checking if GLFW initialized correctly
	if (not glfwInit()) {
		std::cout << "GLFW couldn't start" << std::endl;
		return EXIT_FAILURE;
	}

	// Initializing a window object
	window = glfwCreateWindow(640,480,"GLFW Custom Window", nullptr, nullptr);

	// As long as the window isn't told to close
	while (not glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}

	return EXIT_SUCCESS;
}
