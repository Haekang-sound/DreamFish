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
	bool& buttonIsOpen = GetButtonIsOpen(); /// DoorButton�� isOpen ���� ���� ���� ����ȴ�.
	Vecor2 vPos = GetPos();
	
	///------------------��ư���� ��ȣ�ۿ�-----------
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

