#ifndef Quadrangle_hpp
#define Quadrangle_hpp

#include "Sprite.h"

static constexpr int QUADRANGLE_VERTEX_COUNT = 4;

class Quadrangle : public Sprite<QUADRANGLE_VERTEX_COUNT> {
public:
    Quadrangle();

    ~Quadrangle();
    
    void Move();
};

#endif /* Quadrangle_hpp */
