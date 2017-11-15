#ifndef Sprite_hpp
#define Sprite_hpp

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Define.h"
#include "Shader.hpp"

class Sprite {
public:
    Sprite();
    
    ~Sprite();
    
    void Draw(GLint glCount);
    
    void DeleteVAO();
    
public:
    Vertex mVertices[4];
    Vec2f mPos;
    GLuint mVAO; //VAO: Vertex Array Object -> 描画に用いるバッファやバッファ設定の集まり
    GLuint mVBO; //VBO: Vertex Buffer Object -> 描画に用いるバッファ(データ)
    Shader mShader; //Shaderクラスの取得
};

#endif /* Sprite_hpp */
