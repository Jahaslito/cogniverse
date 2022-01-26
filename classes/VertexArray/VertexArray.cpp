//
// Created by tony on 25/01/2022.
//

#include "VertexArray.h"

VertexArray::VertexArray() {
    glGenVertexArrays(1, &(VertexArray::rendererId));
}

void VertexArray::bind() {
    glBindVertexArray(rendererId);
}

void VertexArray::unBind() {
    glBindVertexArray(0);
}
