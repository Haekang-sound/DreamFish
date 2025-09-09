#include "pch.h"
#include "Door.h"
#include "CTimeManager.h"
#include "CCollider.h"
#include "DoorButton.h"

Door::Door()
{
	CreateCollider();
	GetCollider()->SetScale(Vecor2(50.f, 200.f));
}

Door::~Door()
{
}

void Door::Update()
{
	bool& buttonIsOpen = GetButtonIsOpen(); /// DoorButton의 isOpen 값을 참조 이후 쓰면된다.
	Vecor2 vPos = GetPos();
	
	///------------------버튼과의 상호작용-----------
	if (buttonIsOpen)
	{
		if (vPos.y >=500)
			vPos.y -= 300 * fDT;
	}
	else
	{
		if (vPos.y <= 700)
			vPos.y += 300 * fDT;
	}

	SetPos(vPos);

}
void Door::OnCollisionEnter(CCollider* _pOther)
{

}

void Door::OnCollision(CCollider* _pOther)
{
}


void Door::OnCollisionExit(CCollider* _pOther)
{
}

