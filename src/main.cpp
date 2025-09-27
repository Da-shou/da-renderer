#include <glad/gl.h>    // GLAD helper library
#include <GLFW/glfw3.h> // GLFW main library

#include <cstdlib>    // C Standard Library
#include <filesystem> // Get current working directory
#include <iostream>   // Input / Output

#include "meshes/triangle.h" // Get our triangle mesh
#include "utils.h"           // Get our useful functions

int main() {
        // Print current working directory for debugging purposes.
        std::cout << "Working from " << std::filesystem::current_path()
                  << std::endl;

        // Checking if GLFW initialized correctly
        if (not glfwInit()) {
                std::cout << "GLFW couldn't start" << std::endl;
                return EXIT_FAILURE;
        }

        GLFWwindow *window;

        // Initializing a window object
        window =
            glfwCreateWindow(640, 480, "GLFW Debug Window", nullptr, nullptr);
        glfwMakeContextCurrent(window);

        // Code snippet to make sure GLAD has initialized.
        int version = gladLoadGL(glfwGetProcAddress);
        if (not version) {
                std::cerr << "Failed to initialize GLAD" << std::endl;
                return EXIT_FAILURE;
        }

        // Log the GLFW and GLAD versions.
        printf("Using GLFW %d.%d\n", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR);
        printf("Using GLAD %d.%d\n", GLAD_VERSION_MAJOR(version),
               GLAD_VERSION_MINOR(version));

        // Clearing the window with a fixed color.
        glClearColor(0.25f, 0.5f, 0.75f, 1.0f);

        int w, h;
        glfwGetFramebufferSize(window, &w, &h);
        glViewport(0, 0, w, h);

        Triangle *triangle = new Triangle();

        // Create a shader
        unsigned int shader =
            make_shader("src/shaders/vertex.txt", "src/shaders/fragment.txt");

        // As long as the window isn't told to close
        while (not glfwWindowShouldClose(window)) {
                // Get any event OpenGL can register
                glfwPollEvents();

                // Clear the color buffer by giving the correct
                // bit mask to the glClear function.
                glClear(GL_COLOR_BUFFER_BIT);

                // Using the custom shader
                glUseProgram(shader);

                // Using our triangle mesh to draw a triangle
                triangle->draw();

                // Swapping the buffers since OpenGL is a double
                // buffer system.
                glfwSwapBuffers(window);
        }

        // Deleting the dynamically made program.
        glDeleteProgram(shader);

        std::cout << "Ending GLFW program..." << std::endl;
        return EXIT_SUCCESS;
}
