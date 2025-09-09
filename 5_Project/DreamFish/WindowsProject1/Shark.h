#pragma once
#include "CObject.h"
#include "CCollider.h"
#include "CBattery.h"

class CTexture;

class Shark :
    public CObject
{

private:
	virtual void OnCollisionEnter(CCollider* _pOther);
	virtual void OnCollision(CCollider* _pOther);
	virtual void OnCollisionExit(CCollider* _pOther);
	CTexture* m_pTex;

	
public:
	virtual void Update();
	virtual void Render(HDC _dc);
	float moveSpeed;

	bool& HaveBattery() { return CBattery::GetisHave(); } ///***버튼을 누르면 문이 열리게끔 하기위해 isOpen값을 가져온다.

public:
	Shark();
	~Shark();
};

