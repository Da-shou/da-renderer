#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "meshes/triangle.h"

Triangle::Triangle() {
	std::vector<float> positions = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

	std::vector<int> colorIndices = {0, 1, 2};

	// Updating our vertex_count
	vertex_count = 3;

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	VBOs.resize(2);

	glGenBuffers(2, VBOs.data());

	// This function requires the number of bytes of the buffer
	// and also the data location in memory, provided by .data()
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
	glBufferData(GL_ARRAY_BUFFER, positions.size() * sizeof(float),
			positions.data(), GL_STATIC_DRAW);
	// Telling OpenGL of our position attribute (3 floats, not normalized)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 12, (void*)0);
	glEnableVertexAttribArray(0);

	// Same, but with color attribute. They are integer so they don't
	// have the option to be normalized.
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
	glBufferData(GL_ARRAY_BUFFER, colorIndices.size() * sizeof(float),
			colorIndices.data(), GL_STATIC_DRAW);
	glVertexAttribIPointer(1, 1, GL_INT, 4, (void*)0);
	glEnableVertexAttribArray(1);
}

void Triangle::draw() {
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, vertex_count);
}

Triangle::~Triangle() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(2, VBOs.data());
}
