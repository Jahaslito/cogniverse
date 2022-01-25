//
// Created by tony on 24/01/2022.
//

#ifndef COGNIVERSE_TRIANGLE_H
#define COGNIVERSE_TRIANGLE_H


#include "../classes/VertexArray/VertexArray.h"

class Triangle {
public:
    Triangle();
    //size in bytes
    int size;
    float vertices[18] = {
        -0.5f, 1.0f, 0.0f,
        -1.0f, 0.0f, 0.0f,
        -0.5, -1.0f, 0.0f,
        0.5f, -1.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        0.5f, 1.0f, 0.0f
    };
    unsigned int indices[12] = {
            1, 0, 2,
            0, 2, 3,
            0, 5, 3,
            5, 3, 4
    };
    VertexArray vertexArray
};

Triangle::Triangle(){
    size = sizeof(vertices);
}



#endif //COGNIVERSE_TRIANGLE_H
