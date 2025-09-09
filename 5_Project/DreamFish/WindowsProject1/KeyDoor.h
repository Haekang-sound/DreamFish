#pragma once
#include "CObject.h"
#include "DoorKey.h"

class KeyDoor :
    public CObject
{

private:

	virtual void OnCollisionEnter(CCollider* _pOther);
	virtual void OnCollision(CCollider* _pOther);
	virtual void OnCollisionExit(CCollider* _pOther);
public:
	virtual void Update();
    bool& GetButtonIsOpen2() { return DoorKey::GetisOpen(); } ///***��ư�� ������ ���� �����Բ� �ϱ����� isOpen���� �����´�.

public:
	KeyDoor();
	~KeyDoor();
};

