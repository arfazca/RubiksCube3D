#include "input/InputHandler.h"
#include "core/RubiksCube.h"
#include "core/Camera.h"
#include "graphics/OpenGLHeaders.h"
#include <cstdio>
#include <cstdlib>

// Static member definition
LayerSelection InputHandler::s_selection;

// Forward declarations for global access
extern RubiksCube* g_cube;
extern Camera* g_camera;
extern float g_aspect;

void InputHandler::handleKeyboard(unsigned char key, int x, int y) {
    switch (key) {
    // Vim-style camera rotation
    case 'h': g_camera->rotate(0, -5); break;
    case 'l': g_camera->rotate(0, 5); break;
    case 'j': g_camera->rotate(5, 0); break;
    case 'k': g_camera->rotate(-5, 0); break;
    
    // Gap adjustment
    case '+': case '=': g_cube->adjustGap(3); break;
    case '-': case '_': g_cube->adjustGap(-3); break;
    
    // Layer selection - X axis
    case 'q': s_selection.axis = 'x'; s_selection.layer = 0; break;
    case 'w': s_selection.axis = 'x'; s_selection.layer = 1; break;
    case 'e': s_selection.axis = 'x'; s_selection.layer = 2; break;
    
    // Layer selection - Y axis
    case 'a': s_selection.axis = 'y'; s_selection.layer = 0; break;
    case 's': s_selection.axis = 'y'; s_selection.layer = 1; break;
    case 'd': s_selection.axis = 'y'; s_selection.layer = 2; break;
    
    // Layer selection - Z axis
    case 'z': s_selection.axis = 'z'; s_selection.layer = 0; break;
    case 'x': s_selection.axis = 'z'; s_selection.layer = 1; break;
    case 'c': s_selection.axis = 'z'; s_selection.layer = 2; break;
    
    // Rotate selected layer
    case 'u': g_cube->rotateLayer(s_selection.axis, s_selection.layer, -90); break;
    case 'o': g_cube->rotateLayer(s_selection.axis, s_selection.layer, 90); break;
    
    // Quit
    case 27: // ESC
        delete g_cube;
        delete g_camera;
        exit(0);
        break;
    }
    
    glutPostRedisplay();
}

void InputHandler::handleMouse(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) {
        if (button == GLUT_LEFT_BUTTON) {
            g_camera->zoom(-5);
        } else if (button == GLUT_RIGHT_BUTTON) {
            g_camera->zoom(5);
        }
        g_camera->updatePerspective(g_aspect);
        glutPostRedisplay();
    }
}

void InputHandler::printControls() {
    printf("=== Rubik's Cube Controls ===\n");
    printf("Camera (Vim-style):\n");
    printf("  h/l - Rotate left/right\n");
    printf("  j/k - Rotate down/up\n");
    printf("  Mouse - Zoom in/out\n");
    printf("\nLayer Selection:\n");
    printf("  q/w/e - X-axis layers (left/middle/right)\n");
    printf("  a/s/d - Y-axis layers (bottom/middle/top)\n");
    printf("  z/x/c - Z-axis layers (back/middle/front)\n");
    printf("\nRotation:\n");
    printf("  u - Rotate selected layer counterclockwise\n");
    printf("  o - Rotate selected layer clockwise\n");
    printf("\nOther:\n");
    printf("  +/- - Adjust gap between cubes\n");
    printf("  ESC - Quit\n");
    printf("=============================\n");
}
