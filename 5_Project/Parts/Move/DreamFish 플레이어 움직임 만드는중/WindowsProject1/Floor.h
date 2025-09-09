#pragma once
#include "cObject.h"

class Floor:
	public cObject
{

public:
	virtual void OnCollision(CCollider* _pOther);

public:
	virtual void update();

public:
	Floor();
	~Floor();
};

