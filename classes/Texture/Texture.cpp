//
// Created by tony on 26/01/2022.
//

#include "Texture.h"
#include "../../util/stb_image.h"

SingleTexture::SingleTexture(const char* texturePath, GLint internalFormat, GLenum format, int _textureUnit) {
    glGenTextures(1, &id);
    textureUnit = _textureUnit;
    bind();
    setOptions();
    load(texturePath, internalFormat, format);
}

void SingleTexture::bind() {
    glActiveTexture(GL_TEXTURE0 + textureUnit);
    glBindTexture(GL_TEXTURE_2D, id);
}

void SingleTexture::unBind() {
    glActiveTexture(GL_TEXTURE0 + textureUnit);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void SingleTexture::setOptions() {
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void SingleTexture::load(const char* texturePath, GLint internalFormat, GLenum format) {
    stbi_set_flip_vertically_on_load(true);
    data = stbi_load(texturePath, &width, &height, &nrChannels, 0);
    if(data){
        glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else{
        std::cout << std::endl <<"ERR: Failed to load texture";
    }
    //free the memory
    stbi_image_free(data);
}