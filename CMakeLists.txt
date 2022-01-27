cmake_minimum_required(VERSION 3.20)
project(splashScreen)

set(CMAKE_CXX_STANDARD 14)

add_executable(splashScreen main.cpp bmpLoader.h bmpLoader.cpp video.html)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
