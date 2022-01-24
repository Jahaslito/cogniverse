//
// Created by tony on 24/01/2022.
//

#ifndef COGNIVERSE_SHADER_H
#define COGNIVERSE_SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glad/glad.h>
using namespace std;

class Shader {
public:
    unsigned int id;

    Shader(const char* vertexPath, const char* fragmentPath);

    void use();
    void unUse();

    void setBool(const string &name, bool val) const;
    void setInt(const string &name, int val) const;
    void setFloat(const string &name, float val) const;
};


#endif //COGNIVERSE_SHADER_H
