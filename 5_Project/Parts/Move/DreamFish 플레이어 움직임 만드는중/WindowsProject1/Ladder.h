#pragma once
#include "cObject.h"
class Ladder :
    public cObject
{

private:
	virtual void OnCollisionEnter(CCollider* _pOther);
	virtual void OnCollision(CCollider* _pOther);
	virtual void OnCollisionExit(CCollider* _pOther);

public:
	virtual void update();

public:
	Ladder();
	~Ladder();
};

