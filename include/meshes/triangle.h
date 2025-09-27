#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <vector>
class Triangle {
public:
	Triangle();
	Triangle(Triangle &&) = default;
	Triangle(const Triangle &) = default;
	Triangle &operator=(Triangle &&) = default;
	Triangle &operator=(const Triangle &) = default;
	~Triangle();

	void draw();
private:
	std::vector<unsigned int> VBOs;
	unsigned int VAO;
	unsigned int vertex_count;
};

#endif // !TRIANGLE_H
