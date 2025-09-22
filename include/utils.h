#ifndef UTILS_H
#define UTILS_H

#include <string>

/**
 * @brief Compiles a shader given a filepath and a module type.
 * @param filepath Path to the shader file
 * @param module_type Type of shader to compile.
 **/
unsigned int make_module(const std::string& filepath, unsigned int module_type);


/**
 * @brief Compiles a shader program using a vertex and fragment shader.
 * @param vertex_filepath Path to the vertex shader file.
 * @param fragment_filepath Path to the fragment shader file.
 **/
unsigned int make_shader(const std::string& vertex_filepath, const std::string& fragment_filepath);

#endif // !UTILS_H
