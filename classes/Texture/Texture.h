//
// Created by tony on 26/01/2022.
//

#ifndef COGNIVERSE_TEXTURE_H
#define COGNIVERSE_TEXTURE_H

#include <glad/glad.h>
#include <GLFW//glfw3.h>
#include "../../util/stb_image.h"
#include <iostream>

class Texture {
public:
    Texture(const char* texturePath);
    void bind();
    void unBind();
    void setOptions();
    void load(const char* texturePath);

private:
    unsigned int id;
    int width, height, nrChannels;
    unsigned char* data;
};


#endif //COGNIVERSE_TEXTURE_H
