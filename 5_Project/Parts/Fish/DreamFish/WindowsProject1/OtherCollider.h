#pragma once
#include "CCollider.h"
class OtherCollider :
    public CCollider
{
public:
    virtual void render(HDC _hdc);

public:
    OtherCollider();
    ~OtherCollider();
};

