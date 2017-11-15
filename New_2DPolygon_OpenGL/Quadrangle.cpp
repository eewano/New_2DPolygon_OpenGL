#include "Quadrangle.hpp"

Quadrangle::Quadrangle() {
    mVertices[0] = {0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f}; //四角形の右上の座標
    mVertices[1] = {0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f}; //右下
    mVertices[2] = {-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f}; //左下
    mVertices[3] = {-0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f}; //左上
    
    //初期位置の設定
    mPos.x = 0.5f;
    mPos.y = 0.5f;
}

Quadrangle::~Quadrangle() {

}

void Quadrangle::Move() {
    //毎フレームの移動量
    mPos.x -= 0.002f;
    mPos.y -= 0.002f;
}
