#include "Quadrangle.hpp"

Quadrangle::Quadrangle() {
    vertices[0] = {0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f}; //四角形の右上の座標
    vertices[1] = {0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f}; //右下
    vertices[2] = {-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f}; //左下
    vertices[3] = {-0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f}; //左上
}

Quadrangle::~Quadrangle() {

}
