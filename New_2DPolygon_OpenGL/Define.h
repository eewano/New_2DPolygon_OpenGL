#ifndef Define_h
#define Define_h

#define V_BUFFER_SIZE 4
#define PI 3.1415926
#define DEG2RAD 0.0174532925
#define ANGLE 180

#include <GLFW/glfw3.h>

struct Vec2i {
    GLint x, y;
};

struct Vec2f {
    GLfloat x, y;
};

struct Vertex {
    GLfloat x, y, z;
    GLfloat r, g, b;
};

const Vec2i WINDOW_SIZE = {800, 600};

#endif /* Define_h */
