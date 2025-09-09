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

	bool& HaveBattery() { return CBattery::GetisHave(); } ///***��ư�� ������ ���� �����Բ� �ϱ����� isOpen���� �����´�.

public:
	Shark();
	~Shark();
};

