#include "core/Camera.h"
#include "graphics/OpenGLHeaders.h"
#include <cmath>

Camera::Camera() 
    : m_rotX(0.0f), m_rotY(0.0f), 
      m_distance(DEFAULT_DISTANCE), 
      m_fov(DEFAULT_FOV) {
}

void Camera::rotate(float dx, float dy) {
    m_rotX += dx;
    m_rotY += dy;
    m_rotX = fmod(m_rotX, 360.0f);
    m_rotY = fmod(m_rotY, 360.0f);
}

void Camera::zoom(float delta) {
    m_fov += delta;
    if (m_fov < MIN_FOV) m_fov = MIN_FOV;
    if (m_fov > MAX_FOV) m_fov = MAX_FOV;
}

void Camera::apply() const {
    glLoadIdentity();
    gluLookAt(0, 80, m_distance, 0, 0, 0, 0, 1, 0);
    glRotatef(m_rotX, 1.0f, 0.0f, 0.0f);
    glRotatef(m_rotY, 0.0f, 1.0f, 0.0f);
}

void Camera::updatePerspective(float aspect) const {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(m_fov, aspect, 0.4, 500.0);
    glMatrixMode(GL_MODELVIEW);
}
