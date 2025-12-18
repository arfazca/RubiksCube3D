cmake_minimum_required(VERSION 3.15)
project(RubiksCube VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenGL and GLUT
find_package(OpenGL REQUIRED)

if(APPLE)
    find_library(GLUT_LIBRARY GLUT)
    set(GLUT_LIBRARIES ${GLUT_LIBRARY})
elseif(UNIX)
    find_package(GLUT REQUIRED)
elseif(WIN32)
    find_package(GLUT REQUIRED)
endif()

# Source files
set(SOURCES
    src/main.cpp
    src/core/RubiksCube.cpp
    src/core/Camera.cpp
    src/core/Color.cpp
    src/core/Rotation.cpp
    src/graphics/Renderer.cpp
    src/input/InputHandler.cpp
)

# Header files
set(HEADERS
    include/core/RubiksCube.h
    include/core/Camera.h
    include/core/Color.h
    include/core/Rotation.h
    include/graphics/Renderer.h
    include/graphics/OpenGLHeaders.h
    include/input/InputHandler.h
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${OPENGL_INCLUDE_DIR}
    ${GLUT_INCLUDE_DIR}
)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
)

# Platform-specific settings
if(APPLE)
    target_compile_definitions(${PROJECT_NAME} PRIVATE GL_SILENCE_DEPRECATION)
endif()
