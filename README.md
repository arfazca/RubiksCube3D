# Rubik's Cube OpenGL Visualization

A cross-platform 3D Rubik's Cube visualization with Vim-style controls.

## Project Structure

```
rubiks-cube/
├── CMakeLists.txt
├── README.md
├── include/
│   ├── core/
│   │   ├── Camera.h
│   │   ├── Color.h
│   │   ├── Rotation.h
│   │   └── RubiksCube.h
│   ├── graphics/
│   │   ├── OpenGLHeaders.h
│   │   └── Renderer.h
│   └── input/
│       └── InputHandler.h
└── src/
    ├── main.cpp
    ├── core/
    │   ├── Camera.cpp
    │   ├── Color.cpp
    │   ├── Rotation.cpp
    │   └── RubiksCube.cpp
    ├── graphics/
    │   └── Renderer.cpp
    └── input/
        └── InputHandler.cpp
```

## Building

### Prerequisites

- CMake 3.15+
- C++17 compatible compiler
- OpenGL
- GLUT (freeglut on Windows/Linux, native on macOS)

### macOS
```bash
mkdir build && cd build
cmake ..
make
./RubiksCube
```

### Linux
```bash
sudo apt-get install freeglut3-dev  # Ubuntu/Debian
mkdir build && cd build
cmake ..
make
./RubiksCube
```

### Windows
```bash
# Install freeglut via vcpkg or manually
mkdir build && cd build
cmake ..
cmake --build .
.\Debug\RubiksCube.exe
```

## Controls

**Camera (Vim-style):**
- h/l - Rotate left/right
- j/k - Rotate down/up
- Mouse clicks - Zoom in/out

**Layer Selection:**
- q/w/e - X-axis layers (left/middle/right)
- a/s/d - Y-axis layers (bottom/middle/top)
- z/x/c - Z-axis layers (back/middle/front)

**Rotation:**
- u - Rotate selected layer counterclockwise
- o - Rotate selected layer clockwise

**Other:**
- +/- - Adjust gap between cubes
- ESC - Quit

## Architecture

- **core/**: Core game logic (Cube, Camera, data structures)
- **graphics/**: Rendering and OpenGL abstractions
- **input/**: Input handling and controls
- **OpenGLHeaders.h**: Platform-specific OpenGL header includes

## License

MIT License - see LICENSE file for details
