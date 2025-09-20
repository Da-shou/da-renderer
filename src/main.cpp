#include <iostream>
#include <cstdlib>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {
	GLFWwindow* window;

	// Checking if GLFW initialized correctly
	if (not glfwInit()) {
		std::cout << "GLFW couldn't start" << std::endl;
		return EXIT_FAILURE;
	}

	// Initializing a window object
	window = glfwCreateWindow(640,480,"GLFW Debug Window", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD" << std::endl;
		return EXIT_FAILURE;
	}

	// As long as the window isn't told to close
	while (not glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}
	
	std::cout << "Ending GLFW program..." << std::endl;
	return EXIT_SUCCESS;
}
