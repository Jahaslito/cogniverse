//
// Created by tony on 28/01/2022.
//

#ifndef COGNIVERSE_SPLASH_H
#define COGNIVERSE_SPLASH_H

#include "../classes/VertexArray/VertexArray.h"
#include "../classes/VertexBuffer/VertexBuffer.h"
#include "../classes/ElementBuffer/ElementBuffer.h"
#include "../classes/Texture/Texture.h"
#include "../classes/Shader/Shader.h"

class Splash {
public:
    Splash();
    void setUniforms() const;
    float vertices[32] = {
            //vertices                     // texture coords
            0.5f, 0.5f, 0.0f, 1.0, 1.0,
            0.5f, -0.0625f,  0.0f, 1.0f, 0.0f,
            -0.5f, -0.0625f,  1.0f, 0.0f, 0.0f,
            -0.5f, 0.5f, 0.0f, 0.0f, 1.0f

    };

    unsigned int indices[6] = {
            0, 1, 3,
            1, 2, 3
    };

    VertexArray va;
    VertexBuffer vb = VertexBuffer(vertices, GL_STATIC_DRAW, sizeof(vertices));
    ElementBuffer eb = ElementBuffer(6, indices, GL_STATIC_DRAW);
    SingleTexture texture1 = SingleTexture("assets/splash.png", GL_RGB, GL_RGBA, 0);
    Shader shader = Shader("shaders/Splash.vs", "shaders/Splash.fs");
};

Splash::Splash() {
    va.bind();

    vb.setAttribPointers(0, 3, GL_FLOAT,
                         GL_FALSE, 5 * sizeof(float), (void*)0);
    vb.setAttribPointers(1, 2, GL_FLOAT,GL_FALSE,
                         5 * sizeof(float ), (void*)(3 * sizeof(float)));
    va.unBind();
    vb.unBind();
    eb.unBind();
}

void Splash::setUniforms() const {
    shader.setInt("texture1", 0);
}


#endif //COGNIVERSE_SPLASH_H
