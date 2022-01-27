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

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Rectangle{
public:
    Rectangle();
    void setUniforms() const;
    void transform() const;
    void transform2() const;
    void transform3D() const;
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
    Texture texture1 = Texture("assets/container.jpg", GL_RGB, GL_RGB, 0);
    Texture texture2 = Texture("assets/awesomeface.png", GL_RGB, GL_RGBA, 1);
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

void Rectangle::setUniforms() const {
    shader.setInt("texture1", 0);
    shader.setInt("texture2", 1);
}

void Rectangle::transform() const {
    glm::mat4 trans = glm::mat4(1.0f);
    //trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));
    trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
    trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));
    shader.setMat4("transform", 1, GL_FALSE, glm::value_ptr(trans));
}

void Rectangle::transform2() const {
    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
    trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
    shader.setMat4("transform", 1, GL_FALSE, glm::value_ptr(trans));
}

void Rectangle::transform3D() const {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    shader.setMat4("model", 1, GL_FALSE, glm::value_ptr(model));

    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    shader.setMat4("view", 1, GL_FALSE, glm::value_ptr(view));

    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    shader.setMat4("projection", 1, GL_FALSE, glm::value_ptr(projection));
}

#endif //COGNIVERSE_RECTANGLE_H
