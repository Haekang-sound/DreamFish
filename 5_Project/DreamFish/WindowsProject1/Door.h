#pragma once
#include "CObject.h"
#include "DoorButton.h"

class CTexture;

class Door :
	public CObject
{

private:

	virtual void OnCollisionEnter(CCollider* _pOther);
	virtual void OnCollision(CCollider* _pOther);
	virtual void OnCollisionExit(CCollider* _pOther);


public:
	virtual void Update();
	virtual void Render(HDC	_dc);

	bool& GetButtonIsOpen() { return DoorButton::GetisOpen(); } ///***��ư�� ������ ���� �����Բ� �ϱ����� isOpen���� �����´�.

	

public:
	Door();
	~Door();
};

