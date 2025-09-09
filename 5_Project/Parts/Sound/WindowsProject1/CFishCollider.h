#pragma once
#include "CCollider.h"
class CFishCollider :
    public CCollider
{
public:
    virtual void Render(HDC _hdc);
    virtual void FinalUpdate();


public:
    CFishCollider();
    ~CFishCollider();
};

