#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

unsigned int make_module(const std::string& filepath, unsigned int module_type) {
	// File reading variables
	std::ifstream file;
	std::stringstream bufferedLines;
	std::string line;

	// Reading the file line by line
	file.open(filepath);
	while (std::getline(file, line)) {
		bufferedLines << line << std::endl;
	}

	// Converting the lines to a C style string (const char*)
	std::string tmp = bufferedLines.str();
	const char* shaderSrc = tmp.c_str();
	bufferedLines.str("");
	file.close();

	// Create the shader module
	unsigned int shaderModule = glCreateShader(module_type);

	// Put the shader source code into our new shader.
	// NULL as the last parameter allows to put the whole file.
	glShaderSource(shaderModule, 1, &shaderSrc, NULL);

	// Compiling the shader
	glCompileShader(shaderModule);

	// Checking if compilation was successful
	int status;
	glGetShaderiv(shaderModule, GL_COMPILE_STATUS, &status);

	if (not status) {
		// 1024 chararcters array to store the error message.
		char errorLog[1024];
		glGetShaderInfoLog(shaderModule, 1024, NULL, errorLog);
		std::cout << "SHADER COMPILATION ERROR" << std::endl << 
			errorLog << std::endl;
	}

	return shaderModule;
}

unsigned int make_shader(const std::string& vertex_filepath, const std::string& fragment_filepath) {
	// Making a vector of the vertex and fragment shdader
	std::vector<unsigned int> modules;
	modules.push_back(make_module(vertex_filepath, GL_VERTEX_SHADER));
	modules.push_back(make_module(fragment_filepath, GL_FRAGMENT_SHADER));

	// Creating the actual shader program with the two shaders attached.
	unsigned int shader = glCreateProgram();
	for(unsigned int shaderModule : modules) {
		glAttachShader(shader, shaderModule);
	}

	// Link the new shader program to our main program.
	glLinkProgram(shader);

	// Check if the creation and linking failed
	int status;
	glGetProgramiv(shader, GL_LINK_STATUS, &status);
	if (not status) {
		char errorLog[1024];
		glGetProgramInfoLog(shader, 1024, NULL, errorLog);
		std::cout << "SHADER PROGRAM CREATION/LINKING ERROR" << std::endl 
			<< errorLog << std::endl;
	}

	// Now that the shader program is compiler, the shaders objects
	// aren't useful anymore.
	for (unsigned int shaderModule : modules) {
		glDeleteShader(shaderModule);
	}

	// Done !
	return shader;
}
