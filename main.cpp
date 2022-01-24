#include <iostream>
#include "classes/Window/Window.h"
#include "classes/Shader/Shader.h"

/* These two are static variables. I had to use them because glfw's
 callback function for resizing OpenGL viewport only take a static
 function.
*/
int Window::width;
int Window::height;

int main() {
    Window window("test", 800, 600, false);
    window.render();
}
