#ifndef Quadrangle_hpp
#define Quadrangle_hpp

#include "Sprite.hpp"

class Quadrangle : public Sprite {
public:
    Quadrangle();

    ~Quadrangle();
    
    void Move();
};

#endif /* Quadrangle_hpp */
