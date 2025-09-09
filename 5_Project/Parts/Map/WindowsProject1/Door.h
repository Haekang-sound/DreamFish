#pragma once
#include "CObject.h"
#include "DoorButton.h"

class Door :
	public CObject
{

private:
	virtual void OnCollisionEnter(CCollider* _pOther);
	virtual void OnCollision(CCollider* _pOther);
	virtual void OnCollisionExit(CCollider* _pOther);

public:
	virtual void Update();

	bool& GetButtonIsOpen() { return DoorButton::GetisOpen(); } ///***버튼을 누르면 문이 열리게끔 하기위해 isOpen값을 가져온다.
	

public:
	Door();
	~Door();
};

