//
// Created by tony on 24/01/2022.
//

#ifndef COGNIVERSE_HEXAGON_H
#define COGNIVERSE_HEXAGON_H


#include "../classes/VertexArray/VertexArray.h"
#include "../classes/VertexBuffer/VertexBuffer.h"
#include "../classes/ElementBuffer/ElementBuffer.h"
#include "../classes/Shader/Shader.h"


class Hexagon {
public:
    Hexagon();
    //define vertices or texture or color values
    float vertices[18] = {
        -0.5f, 1.0f, 0.0f,
        -1.0f, 0.0f, 0.0f,
        -0.5, -1.0f, 0.0f,
        0.5f, -1.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        0.5f, 1.0f, 0.0f
    };

    //define indices to specify order of drawing vertices
    unsigned int indices[12] = {
            1, 0, 2,
            0, 2, 3,
            0, 5, 3,
            5, 3, 4
    };

    // you should create these too
    // -> vertx array
    // -> vertex buffer
    // -> element buffer
    // -> shader
    VertexArray va;
    VertexBuffer vb = VertexBuffer(vertices, GL_STATIC_DRAW, sizeof(vertices));
    //make sure to specify number of indices that you defined
    // automatically bound same as vertex buffer
    ElementBuffer eb = ElementBuffer(12, indices, GL_STATIC_DRAW);
    Shader shader = Shader("shaders/Hexagon.vs", "shaders/Hexagon.fs");
};

Hexagon::Hexagon(){
    // configure VAO, VBO, and EBO
    va.bind();
    vb.setAttribPointers(0, 3, GL_FLOAT,
                         GL_FALSE, 3 * sizeof(float), (void*)0);

    //unbind the VAO,VBO and EBO, they will be bound by the renderer when needed
    va.unBind();
    vb.unBind();
    eb.unBind();
}



#endif //COGNIVERSE_HEXAGON_H
