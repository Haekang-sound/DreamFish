#pragma once
#include "CObject.h"

class CButtonQuit :
    public CObject
{
public:
    virtual void Update();


public:
    CButtonQuit();
    ~CButtonQuit();
};