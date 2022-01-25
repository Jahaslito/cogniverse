//
// Created by tony on 25/01/2022.
//

#include "ElementBuffer.h"

ElementBuffer::ElementBuffer(unsigned int rendererId, unsigned int _count) {
    ElementBuffer::count = _count;
    glGenBuffers(rendererId, &(ElementBuffer::rendererId));
}

void ElementBuffer::bind(unsigned int indices[], GLenum type, int size) {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, type);
}

int ElementBuffer::getCount() {
    return count;
}