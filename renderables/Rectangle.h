//
// Created by tony on 26/01/2022.
//

#ifndef COGNIVERSE_RECTANGLE_H
#define COGNIVERSE_RECTANGLE_H


#include "../classes/VertexArray/VertexArray.h"
#include "../classes/VertexBuffer/VertexBuffer.h"
#include "../classes/ElementBuffer/ElementBuffer.h"
#include "../classes/Texture/Texture.h"
#include "../classes/Shader/Shader.h"

class Rectangle {
public:
    Rectangle();
    float vertices[32] = {
            //vertices                     //colors                      // texture coords
            0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0, 1.0,
            0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
            -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f

    };

    unsigned int indices[6] = {
            0, 1, 3,
            1, 2, 3
    };

    VertexArray va;
    VertexBuffer vb = VertexBuffer(vertices, GL_STATIC_DRAW, sizeof(vertices));
    ElementBuffer eb = ElementBuffer(6, indices, GL_STATIC_DRAW);
    Texture texture = Texture("assets/container.jpg");
    Shader shader = Shader("shaders/Rectangle.vs", "shaders/Rectangle.fs");
};

Rectangle::Rectangle() {
    va.bind();

    vb.setAttribPointers(0, 3, GL_FLOAT,
                         GL_FALSE, 8 * sizeof(float), (void*)0);
    vb.setAttribPointers(1, 3, GL_FLOAT,GL_FALSE,
                         8 * sizeof(float ), (void*)(3 * sizeof(float)));
    vb.setAttribPointers(2, 2, GL_FLOAT, GL_FALSE,
                         8 * sizeof(float), (void*)(6 * sizeof(float)));
    va.unBind();
    vb.unBind();
    eb.unBind();
}

#endif //COGNIVERSE_RECTANGLE_H
