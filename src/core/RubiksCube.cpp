#include "core/RubiksCube.h"
#include "graphics/OpenGLHeaders.h"
#include "graphics/Renderer.h"

RubiksCube::RubiksCube() : m_currentGap(DEFAULT_GAP) {
    initializeColors();
}

void RubiksCube::initializeColors() {
    for (int x = 0; x < GRID_SIZE; ++x) {
        for (int y = 0; y < GRID_SIZE; ++y) {
            for (int z = 0; z < GRID_SIZE; ++z) {
                // Front face (z=2): Green
                m_faceColors[x][y][z][0] = (z == 2) ? Color::Green() : Color::Black();
                // Back face (z=0): Blue
                m_faceColors[x][y][z][1] = (z == 0) ? Color::Blue() : Color::Black();
                // Left face (x=0): Orange
                m_faceColors[x][y][z][2] = (x == 0) ? Color::Orange() : Color::Black();
                // Right face (x=2): Red
                m_faceColors[x][y][z][3] = (x == 2) ? Color::Red() : Color::Black();
                // Top face (y=2): White
                m_faceColors[x][y][z][4] = (y == 2) ? Color::White() : Color::Black();
                // Bottom face (y=0): Yellow
                m_faceColors[x][y][z][5] = (y == 0) ? Color::Yellow() : Color::Black();
            }
        }
    }
}

void RubiksCube::drawCube(int x, int y, int z) const {
    const auto& rotations = m_rotationHistory[x][y][z];
    
    glPushMatrix();
    
    float offset = CUBE_SIZE + m_currentGap;
    glTranslatef((x - 1) * offset, (y - 1) * offset, (z - 1) * offset);
    
    for (auto it = rotations.rbegin(); it != rotations.rend(); ++it) {
        glRotatef(it->angle, it->x, it->y, it->z);
    }
    
    float half = CUBE_SIZE / 2.0f;
    for (int face = 0; face < 6; ++face) {
        Renderer::drawCubeFace(face, half, m_faceColors[x][y][z][face]);
    }
    
    glPopMatrix();
}

void RubiksCube::drawAll() const {
    for (int x = 0; x < GRID_SIZE; ++x) {
        for (int y = 0; y < GRID_SIZE; ++y) {
            for (int z = 0; z < GRID_SIZE; ++z) {
                drawCube(x, y, z);
            }
        }
    }
}

void RubiksCube::rotateLayer(char axis, int layer, float angle) {
    Rotation rot;
    
    switch (axis) {
    case 'x':
        rot = Rotation(angle, 1.0f, 0.0f, 0.0f);
        for (int y = 0; y < GRID_SIZE; ++y) {
            for (int z = 0; z < GRID_SIZE; ++z) {
                m_rotationHistory[layer][y][z].push_back(rot);
            }
        }
        break;
    case 'y':
        rot = Rotation(angle, 0.0f, 1.0f, 0.0f);
        for (int x = 0; x < GRID_SIZE; ++x) {
            for (int z = 0; z < GRID_SIZE; ++z) {
                m_rotationHistory[x][layer][z].push_back(rot);
            }
        }
        break;
    case 'z':
        rot = Rotation(-angle, 0.0f, 0.0f, 1.0f);
        for (int x = 0; x < GRID_SIZE; ++x) {
            for (int y = 0; y < GRID_SIZE; ++y) {
                m_rotationHistory[x][y][layer].push_back(rot);
            }
        }
        break;
    }
}

void RubiksCube::adjustGap(float delta) {
    m_currentGap += delta;
    if (m_currentGap < 0) m_currentGap = 0;
}
