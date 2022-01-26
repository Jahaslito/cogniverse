//
// Created by tony on 25/01/2022.
//

#ifndef COGNIVERSE_ELEMENTBUFFER_H
#define COGNIVERSE_ELEMENTBUFFER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class ElementBuffer {
public:
    ElementBuffer(unsigned int _count, unsigned int indices[], GLenum type);
    void bind();
    void unBind();
    int getCount();
private:
    unsigned int rendererId;
    unsigned int count;
};


#endif //COGNIVERSE_ELEMENTBUFFER_H
