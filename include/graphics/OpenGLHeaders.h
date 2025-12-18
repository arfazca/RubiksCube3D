#ifndef OPENGL_HEADERS_H
#define OPENGL_HEADERS_H

#ifdef __APPLE__
    #define GL_SILENCE_DEPRECATION
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
    #include <GLUT/glut.h>
#elif _WIN32
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
    #include <GL/gl.h>
    #include <GL/glu.h>
    #include <GL/glut.h>
#else 
    #include <GL/gl.h>
    #include <GL/glu.h>
    #include <GL/glut.h>
#endif

#endif // OPENGL_HEADERS_H