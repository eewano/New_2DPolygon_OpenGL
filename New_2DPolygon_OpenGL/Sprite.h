#ifndef Sprite_h
#define Sprite_h

#include <iostream>
#include <memory>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Define.h"
#include "Shader.hpp"

template<int VERTEX_COUNT>
class Sprite {
public:
    Sprite() {
        //VAO(バッファデータや設定)の生成
        glGenVertexArrays(1, &mVAO);
        //VBO(バッファ)の生成
        glGenBuffers(1, &mVBO);
        //現在のVBOに設定(GL_ARRAY_BUFFER: 頂点データやTexture座標のバッファ)
        glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    }
    
    ~Sprite() {
        
    }
    
    void Draw(GLint glCount) {
        //現在のVAOに設定
        glBindVertexArray(mVAO);
        
        //現在のバッファにデータを送信
        glBufferData(
                     GL_ARRAY_BUFFER,
                     sizeof(mVertices), //アップロードするデータのバイト数
                     mVertices, //アップロードするデータのポイントの設定
                     GL_STATIC_DRAW //データの利用方法(GL_STATIC_DRAW: 一度だけアップロードする)
                     );
        
        //Position属性
        glVertexAttribPointer(
                              0, //属性No. 0である必要は無いが、VertexShaderファイル内のlayout location(position)と一致していないと駄目
                              3, //VertexShaderファイルのpositionのデータ型がvec3(3要素)なので3
                              GL_FLOAT, //タイプ
                              GL_FALSE, //データ型が整数型であった時にそれを[0, 1]又は[-1, 1]の範囲に正規化するか否(GL_FALSE)かを指定
                              6 * sizeof(GLfloat), //頂点情報とその間隔を指定
                              (GLvoid *) 0 //頂点情報を格納している領域の先頭の位置を指定。ここでは頂点バッファオブジェクトの先頭から格納されているので0を指定
                              );
        glEnableVertexAttribArray(0);
        
        //Color属性
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *) (3 * sizeof(GLfloat)));
        glEnableVertexAttribArray(1);
        
        //transformationの生成
        glm::mat4 mTransform;
        //translate(transform, glm::vec3(current_posX, current_posY, current_posZ))
        mTransform = glm::translate(mTransform, glm::vec3(mPos.x, mPos.y, 0.0f));
        //rotate(tranform, 毎フレームごとの回転量と方向, 回転軸(x, y, z))
        mTransform = glm::rotate(mTransform, (GLfloat)glfwGetTime() * -2.0f, glm::vec3(0.0f, 0.0f, 1.0f));
        
        //uniform locationの基盤の取得とセット
        GLint mTransformLocation;
        mTransformLocation = glGetUniformLocation(mShader.mProgram, "transform");
        glUniformMatrix4fv(mTransformLocation, 1, GL_FALSE, glm::value_ptr(mTransform));
        
        //引数で来たglCountと、各ポリゴンの頂点数VERTEX_COUNTを代入
        glDrawArrays(glCount, 0, VERTEX_COUNT);
        glBindVertexArray(0);
    }
    
    void DeleteVAO() {
        //arraysで指定された頂点配列オブジェクト(VAO)を削除
        glDeleteVertexArrays(1, &mVAO);
        //使用済みのバッファオブジェクトの削除
        glDeleteBuffers(1, &mVBO);
    }
    
public:
    Vertex mVertices[VERTEX_COUNT];
    Vec2f mPos;
    GLuint mVAO; //VAO: Vertex Array Object -> 描画に用いるバッファやバッファ設定の集まり
    GLuint mVBO; //VBO: Vertex Buffer Object -> 描画に用いるバッファ(データ)
    Shader mShader; //Shaderクラスの取得
};

#endif /* Sprite_h */
