#include "core/Color.h"

Color::Color(float r, float g, float b) : r(r), g(g), b(b) {}

Color Color::White() { return Color(1.0f, 1.0f, 1.0f); }
Color Color::Yellow() { return Color(1.0f, 1.0f, 0.0f); }
Color Color::Red() { return Color(0.8f, 0.0f, 0.0f); }
Color Color::Orange() { return Color(1.0f, 0.5f, 0.0f); }
Color Color::Green() { return Color(0.0f, 0.8f, 0.0f); }
Color Color::Blue() { return Color(0.0f, 0.0f, 0.8f); }
Color Color::Black() { return Color(0.1f, 0.1f, 0.1f); }
