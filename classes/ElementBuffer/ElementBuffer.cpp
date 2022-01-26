//
// Created by tony on 25/01/2022.
//

#include "ElementBuffer.h"

ElementBuffer::ElementBuffer(unsigned int _count, unsigned int indices[], GLenum type) {
    ElementBuffer::count = _count;
    glGenBuffers(1, &(ElementBuffer::rendererId));
    bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), indices, type);
}

void ElementBuffer::bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererId);

}

void ElementBuffer::unBind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

int ElementBuffer::getCount() {
    return count;
}