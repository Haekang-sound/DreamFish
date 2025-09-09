#pragma once
#include "CScene.h"
class CTitle :
    public CScene
{
public:
    virtual void Update();
    virtual void Enter();
    virtual void Exit();

private:
    Vecor2 m_MousePos;

public:
    CTitle();
    ~CTitle();
};

