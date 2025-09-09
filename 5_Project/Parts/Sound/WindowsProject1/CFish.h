#pragma once
#include "CObject.h"
class CFish :
    public CObject
{
private:
    Vecor2 direction;
    Vecor2 velocity;
    Vecor2 accelerate;

public:
    virtual void Update();
    virtual void Render(HDC _dc);
    
    void Move();
    

public:
    CFish();
    ~CFish();
};

