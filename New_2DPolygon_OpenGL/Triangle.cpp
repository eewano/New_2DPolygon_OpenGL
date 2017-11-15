#include "Triangle.hpp"

Triangle::Triangle() {
    mVertices[0] = {0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f}; //トップ
    mVertices[1] = {0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f}; //右下
    mVertices[2] = {-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f}; //左下
    
    //初期位置の設定
    mPos.x = -0.5f;
    mPos.y = 0.5f;
}

Triangle::~Triangle() {
    
}

void Triangle::Move() {
    //毎フレームの移動量
    mPos.x += 0.001f;
    mPos.y -= 0.001f;
}
