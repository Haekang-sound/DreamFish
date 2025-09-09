#pragma once
#include "CCollider.h"
class COtherCollider :
    public CCollider
{
public:
    virtual void Render(HDC _hdc);

public:
    COtherCollider();
    ~COtherCollider();
};

