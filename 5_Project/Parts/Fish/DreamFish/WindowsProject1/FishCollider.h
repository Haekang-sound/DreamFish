#pragma once
#include "CCollider.h"
class FishCollider :
    public CCollider
{
public:
    virtual void render(HDC _hdc);

public:
    FishCollider();
    ~FishCollider();
};

