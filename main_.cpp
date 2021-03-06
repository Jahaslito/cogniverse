#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "renderables/Hexagon.h"
#include "classes/Renderer/Renderer.h"
#include "renderables/Rectangle.h"
#include "renderables/Cube.h"
#include "classes/Camera/Camera.h"
#include "classes/ModelLoad/Model.h"

int width = 800;
int height = 600;
GLFWwindow* window = NULL;

float deltaTime = 0.0f;
float lastFrame = 0.0f;

float yScrollOffset, xMousePos, yMousePos;

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

void mouse_callback(GLFWwindow* window, double xPos, double yPos){
   xMousePos = xPos;
   yMousePos = yPos;
}

void scroll_callback(GLFWwindow* window, double xOffset, double yOffset) {
    yScrollOffset = yOffset;
}

void setupMouse(){
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

}

// initializes the window and openGL.
void initialize(){
    initGlfw();
    create("Cogniverse");
    initOpenGL();
    registerResizer();
    setupMouse();
}

glm::vec3 cubePositions[] = {
        glm::vec3( 0.0f, 0.0f,0.0f),
        glm::vec3( 2.0f, 5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f, 3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f, 2.0f, -2.5f),
        glm::vec3( 1.5f, 0.2f, -1.5f),
        glm::vec3(-1.3f, 1.0f, -1.5f)
};

int main() {

    initialize();

    Camera cam = Camera(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, -1.0f)
                        , 0.05f, 2.5f);
    Renderer renderer(cam);

    //instantiate objects to be drawn.
    Cube cube;

    Shader ourShader("shaders/1.model_loading.vs", "shaders/1.model_loading.fs");
    Model ourModel("models/ChallengerTexture.obj");


    //render loop
    while(!glfwWindowShouldClose(window))
    {
        processInput(window);

        renderer.clear();

        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        cam.processKeyboard(window, deltaTime);
        cam.processMouseMove(xMousePos, yMousePos);
        cam.processMouseScroll(yScrollOffset);

//        cube.shader.use();
//        cube.setUniforms();
//
//        for(unsigned int i = 0; i < 10; i++){
//            glm::mat4 model = glm::mat4(1.0f);
//            model = glm::translate(model, cubePositions[i]);
//            float angle = 20.0f * i;
//            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0, 0.3f, 0.5f));
//            cube.shader.setMat4("model", 1, GL_FALSE, glm::value_ptr(model));
//            renderer.renderWithoutEb(cube.va, 36, cube.shader);
//        }

        ourShader.use();
        ourShader.setMat4("view", 1, GL_FALSE, glm::value_ptr(cam.getViewMatrix()));
        ourShader.setMat4("projection", 1, GL_FALSE, glm::value_ptr(cam.getProjectionMatrix()));

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
        model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
        ourShader.setMat4("model", 1, GL_FALSE, glm::value_ptr(model));
        ourModel.Draw(ourShader);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    exit(0);
}
