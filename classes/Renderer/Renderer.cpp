//
// Created by tony on 25/01/2022.
//

#include "Renderer.h"

Renderer::Renderer(Camera& _camera) {
    enableDepthTest();
    clear();
    camera = &_camera;
}

Renderer::~Renderer() {
    delete camera;
}

void Renderer::clear() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::render(VertexArray& vertexArray, ElementBuffer& elementBuffer, Shader& shader) {
    shader.use();
    setMatrices(shader);
    vertexArray.bind();
    elementBuffer.bind();
    glDrawElements(GL_TRIANGLES, elementBuffer.getCount(), GL_UNSIGNED_INT, 0);
}

void Renderer::renderWithoutEb(VertexArray& vertexArray, int vCount,Shader& shader) {
    shader.use();
    setMatrices(shader);
    vertexArray.bind();
    glDrawArrays(GL_TRIANGLES, 0, vCount);
}

void Renderer::enableDepthTest() {
    glEnable(GL_DEPTH_TEST);
}

void Renderer::setMatrices(Shader shader) {
    shader.setMat4("view", 1, GL_FALSE, glm::value_ptr(camera->getViewMatrix()));
    shader.setMat4("projection", 1, GL_FALSE, glm::value_ptr(camera->getProjectionMatrix()));
}