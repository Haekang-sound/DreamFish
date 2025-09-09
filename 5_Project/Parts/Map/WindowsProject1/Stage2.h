#pragma once
#include "CScene.h"
class Stage2 :
    public CScene
{

private:

public:
	virtual void Update();
	virtual void Enter();
	virtual void Exit();

public:
	Stage2();
	~Stage2();
};
