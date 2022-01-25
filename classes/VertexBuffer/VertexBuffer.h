//
// Created by tony on 25/01/2022.
//

#ifndef COGNIVERSE_VERTEXBUFFER_H
#define COGNIVERSE_VERTEXBUFFER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>


class VertexBuffer {
private:
    unsigned int rendererId;
public:
    VertexBuffer(unsigned int rendererId);
    void bind(float vertices[], GLenum type, int size);
    void setAttribPointers(GLuint index, GLint size, GLenum type,
                           GLboolean normalized, GLsizei stride, const GLvoid * pointer);
};


#endif //COGNIVERSE_VERTEXBUFFER_H
