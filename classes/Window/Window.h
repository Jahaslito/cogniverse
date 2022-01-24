//
// Created by tony on 24/01/2022.
//

#ifndef COGNIVERSE_WINDOW_H
#define COGNIVERSE_WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <list>

using namespace std;

/* Window class
 *
 * This class handles the usual OpenGL boilerplate for setting things up.
 *
 * */

class Window {
protected:
    static int width;
    static int height;
    GLFWwindow *window;

public:

    Window(const char *title, int width, int height, bool wrFrameMode);
    void init();
    void initOpenGL();
    void create(const char *title);
    void render();
    static void resizer(GLFWwindow* window, int width, int height);
    void registerResizer();
    void processInput(GLFWwindow *window);

};


#endif //COGNIVERSE_WINDOW_H
