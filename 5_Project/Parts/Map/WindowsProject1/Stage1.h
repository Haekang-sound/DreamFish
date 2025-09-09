#pragma once
#include "CScene.h"

class Stage1 :
	public CScene
{

private:

public:
	virtual void Update();
	virtual void Enter();
	virtual void Exit();

public:
	Stage1();
	~Stage1();
};

