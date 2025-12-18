#ifndef COLOR_H
#define COLOR_H

struct Color {
    float r, g, b;
    
    Color(float r = 1.0f, float g = 1.0f, float b = 1.0f);
    
    // Standard Rubik's cube colors
    static Color White();
    static Color Yellow();
    static Color Red();
    static Color Orange();
    static Color Green();
    static Color Blue();
    static Color Black();
};

#endif // COLOR_H
