#pragma once
#include "CObject.h"
class Shark :
    public CObject
{

private:
	virtual void OnCollisionEnter(CCollider* _pOther);
	virtual void OnCollision(CCollider* _pOther);
	virtual void OnCollisionExit(CCollider* _pOther);
	Vecor2 firstShark;
public:
	virtual void Update();
	float moveSpeed;
public:
	Shark();
	~Shark();
};

