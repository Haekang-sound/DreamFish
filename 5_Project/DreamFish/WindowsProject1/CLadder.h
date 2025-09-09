#pragma once
#include "CObject.h"

class CTexture;

class CLadder :
	public CObject
{

private:
	virtual void OnCollisionEnter(CCollider* _pOther);
	virtual void OnCollision(CCollider* _pOther);
	virtual void OnCollisionExit(CCollider* _pOther);

public:
	virtual void Update();
	virtual void Render(HDC _dc);

public:
	CLadder();
	~CLadder();
};

