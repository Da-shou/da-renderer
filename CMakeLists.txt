cmake_minimum_required(VERSION 4.0.0)

# Requiring C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Defining compilations flags
set(GCC_COMPILE_FLAGS "-Wall -Wextra -O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}")

# Project info
project(da_renderer VERSION 1.0)
add_executable(da_renderer src/config.h src/main.cpp)

# Loading the GLFW package
find_package(glfw3 3.3 REQUIRED)
target_link_libraries(da_renderer PRIVATE glfw)
