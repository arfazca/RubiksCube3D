#include "graphics/Renderer.h"
#include "graphics/OpenGLHeaders.h"

void Renderer::initialize() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    
    setupLighting();
}

void Renderer::setupLighting() {
    GLfloat ambientLight[] = {0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat diffuseLight[] = {0.7f, 0.7f, 0.7f, 1.0f};
    GLfloat specularLight[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat lightPosition[] = {0.0f, 50.0f, 50.0f, 1.0f};
    GLfloat specularity[] = {1.0f, 1.0f, 1.0f, 1.0f};
    
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularity);
    glMateriali(GL_FRONT, GL_SHININESS, 60);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void Renderer::drawCubeFace(int face, float half, const Color& c) {
    glBegin(GL_QUADS);
    glColor3f(c.r, c.g, c.b);
    
    switch (face) {
    case 0: // Front (positive Z)
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(half, half, half);
        glVertex3f(-half, half, half);
        glVertex3f(-half, -half, half);
        glVertex3f(half, -half, half);
        break;
    case 1: // Back (negative Z)
        glNormal3f(0.0f, 0.0f, -1.0f);
        glVertex3f(half, half, -half);
        glVertex3f(half, -half, -half);
        glVertex3f(-half, -half, -half);
        glVertex3f(-half, half, -half);
        break;
    case 2: // Left (negative X)
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glVertex3f(-half, half, half);
        glVertex3f(-half, half, -half);
        glVertex3f(-half, -half, -half);
        glVertex3f(-half, -half, half);
        break;
    case 3: // Right (positive X)
        glNormal3f(1.0f, 0.0f, 0.0f);
        glVertex3f(half, half, half);
        glVertex3f(half, -half, half);
        glVertex3f(half, -half, -half);
        glVertex3f(half, half, -half);
        break;
    case 4: // Top (positive Y)
        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-half, half, -half);
        glVertex3f(-half, half, half);
        glVertex3f(half, half, half);
        glVertex3f(half, half, -half);
        break;
    case 5: // Bottom (negative Y)
        glNormal3f(0.0f, -1.0f, 0.0f);
        glVertex3f(-half, -half, -half);
        glVertex3f(half, -half, -half);
        glVertex3f(half, -half, half);
        glVertex3f(-half, -half, half);
        break;
    }
    glEnd();
}
