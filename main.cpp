#include <iostream>
#include "classes/Window/Window.h"
#include "classes/Shader/Shader.h"

int Window::width;
int Window::height;

int main() {
    Window window("test", 800, 600, false);
    window.render();
}
