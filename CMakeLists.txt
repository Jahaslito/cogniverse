cmake_minimum_required(VERSION 3.21)
project(cogniverse)

set(CMAKE_CXX_STANDARD 14)

add_executable(cogniverse main.cpp glad.c classes/Shader/Shader.h classes/Shader/Shader.cpp renderables/Hexagon.h classes/VertexBuffer/VertexBuffer.cpp classes/VertexBuffer/VertexBuffer.h classes/VertexArray/VertexArray.cpp classes/VertexArray/VertexArray.h classes/Renderer/Renderer.cpp classes/Renderer/Renderer.h classes/ElementBuffer/ElementBuffer.cpp classes/ElementBuffer/ElementBuffer.h renderables/Rectangle.h classes/Texture/Texture.cpp classes/Texture/Texture.h util/stb_util.cpp
        renderables/Cube.h classes/Camera/Camera.cpp classes/Camera/Camera.h
        classes/ModelLoad/Mesh.h classes/ModelLoad/Model.h classes/ModelLoad/Vertex.h classes/Camera/Cam.h main.cpp)

find_package(OpenGL REQUIRED)
#include glfw3
find_package(glfw3 3.3 REQUIRED)

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glfw assimp)