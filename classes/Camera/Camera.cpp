//
// Created by tony on 27/01/2022.
//

#include "Camera.h"

Camera::Camera(glm::vec3 pos, glm::vec3 front, float _mouseSensitivity, float _cameraSpeed) {
    cameraPos = pos;
    cameraFront = front;
    mouseSensitivity = _mouseSensitivity;
    cameraSpeed = _cameraSpeed;
}

glm::mat4 Camera::getViewMatrix() {
    return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}

void Camera::processKeyboard(GLFWwindow *window, float deltaTime) {
    cameraSpeed *= deltaTime;
    if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp))
                     * cameraSpeed;
    if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp))
                     * cameraSpeed;
}

void Camera::processMouseMove(double xPos, double yPos) {
    if(firstMouse){
        lastX = xPos;
        lastY = yPos;
        firstMouse = false;
    }

    float xOffset = xPos - lastX;
    float yOffset = yPos - lastY;
    lastX = xPos;
    lastY = yPos;

    xOffset *= mouseSensitivity;
    yOffset *= mouseSensitivity;

    yaw += xOffset;
    pitch += yOffset;

    if(pitch > 89.0f)
        pitch = 89.0f;
    if(pitch > -89.0f)
        pitch = -89.0f;

    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(direction);
}

void Camera::processMouseScroll(double yOffset) {
    fov -= (float)yOffset;
    if(fov < 1.0f)
        fov = 1.0f;
    if(fov > 45.0f)
        fov = 45.0f;
}

glm::mat4 Camera::getProjectionMatrix() {
    return glm::perspective(glm::radians(fov), 800.0f / 600.0f,
                            0.1f, 100.0f);
}