#pragma once
#include "cObject.h"
class CMachine :
    public CObject
{
private:
	virtual void OnCollisionEnter(CCollider* _pOther);
	virtual void OnCollision(CCollider* _pOther);
	virtual void OnCollisionExit(CCollider* _pOther);

public:
	virtual void Update();

	//bool& GetButtonIsOpen() { return DoorButton::GetisOpen(); } ///***��ư�� ������ ���� �����Բ� �ϱ����� isOpen���� �����´�.


public:
	CMachine();
	~CMachine();
	
};

