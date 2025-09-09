#pragma once
#include "CScene.h"
class Stage3 :
    public CScene
{

private:

public:
	virtual void Update();
	virtual void Enter();
	virtual void Exit();

public:
	Stage3();
	~Stage3();
};

