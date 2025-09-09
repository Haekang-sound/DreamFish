#pragma once
#include "CObject.h"

class CTexture;

class Floor :
	public CObject
{

public:
	virtual void OnCollision(CCollider* _pOther);

public:
	virtual void Update();
	virtual void Render(HDC	_dc);

public:
	Floor();
	~Floor();
};

