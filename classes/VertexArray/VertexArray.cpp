//
// Created by tony on 25/01/2022.
//

#include "VertexArray.h"

VertexArray::VertexArray(unsigned int rendererId) {
    glGenVertexArrays(rendererId, &(VertexArray::rendererId));
}

void VertexArray::bind() {
    glBindVertexArray(rendererId);
}

void VertexArray::unBind() {
    glBindVertexArray(0);
}
