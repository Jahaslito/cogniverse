//
// Created by tony on 25/01/2022.
//

#include "VertexBuffer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

VertexBuffer::VertexBuffer(unsigned int rendererId){
    glGenBuffers(rendererId, &(VertexBuffer::rendererId));
}

void VertexBuffer::bind(float vertices[], GLenum type, int size) {
    glBindBuffer(GL_ARRAY_BUFFER, rendererId);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, type);
}

void VertexBuffer::setAttribPointers(GLuint index, GLint size, GLenum type,
                                     GLboolean normalized, GLsizei stride,
                                     const GLvoid *pointer) {
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    glEnableVertexAttribArray(index);
}