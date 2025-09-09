#pragma once
#include "cObject.h"

class CFoothold :
    public cObject
{

public:
    virtual void OnCollision(CCollider* _pOther);

public:
    virtual void update();

public:
    CFoothold();
    ~CFoothold();
};

