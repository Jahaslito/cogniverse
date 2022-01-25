cmake_minimum_required(VERSION 3.21)
project(cogniverse)

set(CMAKE_CXX_STANDARD 14)

add_executable(cogniverse main.cpp glad.c classes/Shader/Shader.h classes/Shader/Shader.cpp renderables/Triangle.h classes/VertexBuffer/VertexBuffer.cpp classes/VertexBuffer/VertexBuffer.h classes/VertexArray/VertexArray.cpp classes/VertexArray/VertexArray.h classes/Renderer.cpp classes/Renderer.h classes/ElementBuffer/ElementBuffer.cpp classes/ElementBuffer/ElementBuffer.h)

find_package(OpenGL REQUIRED)
#include glfw3
find_package(glfw3 3.3 REQUIRED)

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glfw)