#ifndef Sprite_hpp
#define Sprite_hpp

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Define.h"

class Sprite {
public:
    Sprite();

    ~Sprite();

    void Draw(GLint glCount);

    void DeleteVAO();

public:
    Vertex vertices[4];

    GLuint mVAO; //VAO: Vertex Array Object -> 描画に用いるバッファやバッファ設定の集まり
    GLuint mVBO; //VBO: Vertex Buffer Object -> 描画に用いるバッファ(データ)
};

#endif /* Sprite_hpp */
