cmake_minimum_required(VERSION 3.21)
project(cogniverse)

set(CMAKE_CXX_STANDARD 14)

add_executable(cogniverse main.cpp)

find_package(OpenGL REQUIRED)
#include glfw3
find_package(glfw3 3.3 REQUIRED)

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glfw)