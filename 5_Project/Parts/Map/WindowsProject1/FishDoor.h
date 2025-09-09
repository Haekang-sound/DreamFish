#pragma once
#include "CObject.h"
#include "FishButton.h"
class FishDoor :
	public CObject
{

private:
	virtual void OnCollisionEnter(CCollider* _pOther);
	virtual void OnCollision(CCollider* _pOther);
	virtual void OnCollisionExit(CCollider* _pOther);

public:
	virtual void Update();

	
	bool& GetFishButtonIsOpen() { return FishButton::GetisOpen(); } ///***��ư�� ������ ���� �����Բ� �ϱ����� isOpen���� �����´�.

public:
	FishDoor();
	~FishDoor();
};



