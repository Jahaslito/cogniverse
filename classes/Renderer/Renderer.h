//
// Created by tony on 25/01/2022.
//

#ifndef COGNIVERSE_RENDERER_H
#define COGNIVERSE_RENDERER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../VertexBuffer/VertexBuffer.h"
#include "../VertexArray/VertexArray.h"
#include "../Shader/Shader.h"
#include "../ElementBuffer/ElementBuffer.h"

class Renderer {
public:
    Renderer();
    void render(VertexArray& vertexArray, ElementBuffer& elementBuffer, Shader& shader);
    void clear();
};


#endif //COGNIVERSE_RENDERER_H
