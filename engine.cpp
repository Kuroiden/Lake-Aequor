#include "engine.h"
#include "graphics.h"
#include "fish.h"

#include <glut.h>
#include <glfw3.h>
#include <iostream>
#include <math.h>

// Window size
const int windowWidth = 800, windowHeight = 600;

void createWindow(int* argc, char** argv) {
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(windowWidth, windowHeight);

    glutCreateWindow("Lake Aequor Ver.1.0");

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

