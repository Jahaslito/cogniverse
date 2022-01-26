# Cogniverse

### A 3d racing game: for gamification of learning

Built using OpenGL 3.3 Core Profile.

### Instructions

To render something, create a class for it under /renderables 
preferably just a header file. 
Look at Hexagon.h for an example.

Once you're done go to main.cpp and invoke the Renderer in the
render loop.

Shaders are stored under shaders with:

    .vs -> vertex shader
    .fs -> fragment shader
... just create normal files and add the above extension.

P.S: Read the fine comments in the code.