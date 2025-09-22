cmake_minimum_required(VERSION 4.1.1)

# Project info
project(da_renderer VERSION 1.0)

# Requiring C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Export compile_commands.json for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Adding glad
add_subdirectory(external/glad)

# Finding GLFW (Installed system-wide)
find_package(glfw3 REQUIRED)

# Defining compilations flags
set(GCC_COMPILE_FLAGS "-Wall -Wextra -O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}")

add_executable(da_renderer src/main.cpp)

# Linking the libraries to the project
target_link_libraries(da_renderer PRIVATE glad glfw)
