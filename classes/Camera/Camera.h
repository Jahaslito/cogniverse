//
// Created by tony on 27/01/2022.
//

#ifndef COGNIVERSE_CAMERA_H
#define COGNIVERSE_CAMERA_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Camera {
public:
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    float yaw = -90.0f;
    float pitch = 0.0f;
    float fov = 45.0f;

    float mouseSensitivity, lastX, lastY;
    bool firstMouse = true;

    float cameraSpeed;

    Camera(glm::vec3 pos, glm::vec3 front, float _mouseSensitivity, float _cameraSpeed);
    glm::mat4 getViewMatrix();
    glm::mat4 getProjectionMatrix();
    void processKeyboard(GLFWwindow *window, float deltaTime);
    void processMouseMove(double xPos, double yPos);
    void processMouseScroll(double yOffset);
};

#endif //COGNIVERSE_CAMERA_H
