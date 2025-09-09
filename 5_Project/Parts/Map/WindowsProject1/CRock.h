#pragma once
#include "CObject.h"

class CRock :
	public CObject
{
public:
	bool isGravity;
	bool isTouchWall;
	bool canPush;
private:
	virtual void OnCollisionEnter(CCollider* _pOther);
	virtual void OnCollision(CCollider* _pOther);
	virtual void OnCollisionExit(CCollider* _pOther);

public:
	virtual void Update();

public:
	CRock();
	~CRock();
};

