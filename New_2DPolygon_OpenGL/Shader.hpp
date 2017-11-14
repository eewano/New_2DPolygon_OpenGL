#ifndef Shader_hpp
#define Shader_hpp

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>

class Shader {
public:
    Shader();

    ~Shader();

    //シェーダー生成関数
    void Setup(const GLchar *vertexPath, const GLchar *fragmentPath);

    //設定したシェーダーの使用関数
    void Use();

public:
    GLuint mProgram;
};

#endif /* Shader_hpp */
