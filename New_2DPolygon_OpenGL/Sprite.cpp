#include "Sprite.hpp"

Sprite::Sprite() {
    //VAO(バッファデータや設定)の生成
    glGenVertexArrays(1, &mVAO);
    //VBO(バッファ)の生成
    glGenBuffers(1, &mVBO);
    //現在のVBOに設定(GL_ARRAY_BUFFER: 頂点データやTexture座標のバッファ)
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
}

Sprite::~Sprite() {

}

void Sprite::Draw(GLint glCount) {
    //現在のVAOに設定
    glBindVertexArray(mVAO);

    //現在のバッファにデータを送信
    glBufferData(
            GL_ARRAY_BUFFER,
            sizeof(vertices), //アップロードするデータのバイト数
            vertices, //アップロードするデータのポイントの設定
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

    glDrawArrays(glCount, 0, 4);
    glBindVertexArray(0);
}

void Sprite::DeleteVAO() {
    //arraysで指定された頂点配列オブジェクト(VAO)を削除
    glDeleteVertexArrays(1, &mVAO);
    //使用済みのバッファオブジェクトの削除
    glDeleteBuffers(1, &mVBO);
}
