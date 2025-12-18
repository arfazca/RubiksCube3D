#include "core/RubiksCube.h"
#include "core/Camera.h"
#include "graphics/Renderer.h"
#include "graphics/OpenGLHeaders.h"
#include "input/InputHandler.h"

// Global objects
RubiksCube* g_cube = nullptr;
Camera* g_camera = nullptr;
float g_aspect = 1.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    g_camera->apply();
    g_cube->drawAll();
    
    glutSwapBuffers();
}

void reshape(int w, int h) {
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    g_aspect = static_cast<float>(w) / static_cast<float>(h);
    g_camera->updatePerspective(g_aspect);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rubik's Cube - Vim Controls");
    
    Renderer::initialize();
    
    g_cube = new RubiksCube();
    g_camera = new Camera();
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(InputHandler::handleKeyboard);
    glutMouseFunc(InputHandler::handleMouse);
    
    InputHandler::printControls();
    
    glutMainLoop();
    
    delete g_cube;
    delete g_camera;
    
    return 0;
}
