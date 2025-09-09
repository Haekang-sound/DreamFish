#pragma once
#include "CObject.h"
class CWall :
	public CObject
{

private:
	virtual void OnCollisionEnter(CCollider* _pOther);
	virtual void OnCollision(CCollider* _pOther);
	virtual void OnCollisionExit(CCollider* _pOther);

public:
	virtual void Update();

public:
	CWall();
	~CWall();
};

