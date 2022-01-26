//
// Created by tony on 25/01/2022.
//

#ifndef COGNIVERSE_VERTEXARRAY_H
#define COGNIVERSE_VERTEXARRAY_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class VertexArray {
public:
    VertexArray();
    void bind();
    void unBind();

private:
    unsigned int rendererId;
};


#endif //COGNIVERSE_VERTEXARRAY_H
