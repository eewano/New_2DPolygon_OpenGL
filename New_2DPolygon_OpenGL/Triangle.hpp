#ifndef Triangle_hpp
#define Triangle_hpp

#include "Sprite.h"

static constexpr int  TRIANGLE_VERTEX_COUNT = 3;

class Triangle : public Sprite<TRIANGLE_VERTEX_COUNT> {
public:
    Triangle();
    
    ~Triangle();
    
    void Move();
};

#endif /* Triangle_hpp */
