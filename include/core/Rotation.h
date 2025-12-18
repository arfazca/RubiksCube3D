#ifndef ROTATION_H
#define ROTATION_H

struct Rotation {
    float angle;
    float x, y, z;
    
    Rotation(float angle = 0.0f, float x = 0.0f, float y = 0.0f, float z = 0.0f);
};

#endif // ROTATION_H
