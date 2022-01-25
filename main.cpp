#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "classes/Shader/Shader.h"
#include "renderables/Triangle.h"
#include "classes/VertexBuffer/VertexBuffer.h"
#include "classes/VertexArray/VertexArray.h"
#include "classes/Renderer.h"
#include "classes/ElementBuffer/ElementBuffer.h"

int width = 800;
int height = 600;
GLFWwindow* window = NULL;

void initGlfw() {
    glfwInit();
    // setting major and minor version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    //use the core profile
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // for Mac OS X
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

void initOpenGL() {
    // use glad to locate opengl functions (OS specific)
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }

    // set opengl viewport dimens
    glViewport(0, 0, width, height);
}

void create(const char *title) {
    // create the window object
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == NULL)
    {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        exit(-1);
    }
    //set window as main context for current thread
    glfwMakeContextCurrent(window);
}

void resizer(GLFWwindow *window, int _width, int _height) {
    width = _width;
    height = _height;
    glViewport(0, 0, width, height);
}

void registerResizer() {
    glfwSetFramebufferSizeCallback(window, resizer);
}

void processInput(GLFWwindow *window) {
    // check whether ESC key was pressed
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// initializes the window and openGL.
void initialize(){
    initGlfw();
    create("Cogniverse");
    initOpenGL();
    registerResizer();
}
int main() {

    initialize();

    Renderer renderer(1);
    Triangle triangle;

    VertexArray triangleVertexArray(renderer.id);
    triangleVertexArray.bind();

    VertexBuffer triangleVertexBuffer(renderer.id);
    triangleVertexBuffer.bind(triangle.vertices, GL_STATIC_DRAW, sizeof(triangle.vertices));

    ElementBuffer elementBuffer(renderer.id, 12);
    elementBuffer.bind(triangle.indices, GL_STATIC_DRAW, sizeof(triangle.indices));

    triangleVertexBuffer.setAttribPointers(0, 3, GL_FLOAT,
                                   GL_FALSE, 3 * sizeof(float), (void*)0);

    triangleVertexArray.unBind();

    Shader triangleShader("shaders/Triangle.vs", "shaders/Triangle.fs");

    while(!glfwWindowShouldClose(window))
    {
        processInput(window);

        renderer.clear();

        //rendering renderables here
        renderer.render(triangleVertexArray, elementBuffer, triangleShader);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    exit(0);
}
