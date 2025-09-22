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

	// Code snippet to make sure GLAD has initialized.
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD" << std::endl;
		return EXIT_FAILURE;
	}
	
	// Clearing the window with a fixed color.
	glClearColor(0.25f, 0.5f, 0.75f, 1.0f);

	// As long as the window isn't told to close
	while (not glfwWindowShouldClose(window)) {
		glfwPollEvents();

		// Clear the color buffer by giving the correct
		// bit mask to the glClear function.
		glClear(GL_COLOR_BUFFER_BIT);

		// Swapping the buffers since OpenGL is a double
		// buffer system.
		glfwSwapBuffers(window);
	}
	
	std::cout << "Ending GLFW program..." << std::endl;
	return EXIT_SUCCESS;
}
