#pragma once
#include "CObject.h"

class Floor :
	public CObject
{

public:
	virtual void OnCollision(CCollider* _pOther);

public:
	virtual void Update();

public:
	Floor();
	~Floor();
};

