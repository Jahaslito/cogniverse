//
// Created by tony on 25/01/2022.
//

#include "VertexBuffer.h"
#include <glad/glad.h>

VertexBuffer::VertexBuffer(float vertices[], GLenum type, int size){
    glGenBuffers(1, &(VertexBuffer::rendererId));
    bind();
    glBufferData(GL_ARRAY_BUFFER, size, vertices, type);
}

void VertexBuffer::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, rendererId);
}

void VertexBuffer::unBind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::setAttribPointers(GLuint index, GLint size, GLenum type,
                                     GLboolean normalized, GLsizei stride,
                                     const GLvoid *pointer) {
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    glEnableVertexAttribArray(index);
}