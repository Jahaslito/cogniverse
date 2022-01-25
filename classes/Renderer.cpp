//
// Created by tony on 25/01/2022.
//

#include "Renderer.h"

Renderer::Renderer(unsigned int _id) {
    id = _id;
    clear();
}

void Renderer::clear() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::render(VertexArray& vertexArray, ElementBuffer& elementBuffer, Shader& shader) {
    shader.use();
    vertexArray.bind();
    glDrawElements(GL_TRIANGLES, elementBuffer.getCount(), GL_UNSIGNED_INT, 0);
}