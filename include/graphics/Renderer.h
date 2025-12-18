#ifndef RENDERER_H
#define RENDERER_H

#include "core/RubiksCube.h"
#include "core/Camera.h"

class Renderer {
public:
    static void initialize();
    static void setupLighting();
    static void drawCubeFace(int faceIndex, float halfSize, const Color& color);
};

#endif // RENDERER_H
