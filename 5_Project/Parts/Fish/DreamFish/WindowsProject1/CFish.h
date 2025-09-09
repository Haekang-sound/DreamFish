#pragma once
#include "cObject.h"
class CFish :
    public cObject
{
private:
    Vec2 direction;
    Vec2 velocity;
    Vec2 accelerate;

public:
    virtual void update();
    virtual void render(HDC _dc);
    
    void Move();
    

public:
    CFish();
    ~CFish();
};

