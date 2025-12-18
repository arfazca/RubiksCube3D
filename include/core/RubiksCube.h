#ifndef RUBIKS_CUBE_H
#define RUBIKS_CUBE_H

#include "core/Color.h"
#include "core/Rotation.h"
#include <array>
#include <vector>

class RubiksCube {
public:
    static constexpr int GRID_SIZE = 3;
    static constexpr float CUBE_SIZE = 30.0f;
    static constexpr float DEFAULT_GAP = 5.0f;
    
    RubiksCube();
    
    void drawCube(int x, int y, int z) const;
    void drawAll() const;
    
    void rotateLayer(char axis, int layer, float angle);
    
    void adjustGap(float delta);
    float getGap() const { return m_currentGap; }
    float getCubeSize() const { return CUBE_SIZE; }
    
private:
    using ColorArray = std::array<std::array<std::array<std::array<Color, 6>, GRID_SIZE>, GRID_SIZE>, GRID_SIZE>;
    using RotationArray = std::array<std::array<std::array<std::vector<Rotation>, GRID_SIZE>, GRID_SIZE>, GRID_SIZE>;
    
    ColorArray m_faceColors;
    RotationArray m_rotationHistory;
    float m_currentGap;
    
    void initializeColors();
};

#endif // RUBIKS_CUBE_H
