#pragma once
#include "cObject.h"

class CFoothold :
    public cObject
{

public:
    virtual void update();

public:
    CFoothold();
    ~CFoothold();
};

