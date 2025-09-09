#include "pch.h"
#include "FishDoor.h"
#include "CTimeManager.h"
#include "CCollider.h"
#include "DoorButton.h"

FishDoor::FishDoor()
{
	CreateCollider();
	// 발판 충돌 사이즈 값
	GetCollider()->SetScale(Vecor2(50.f, 200.f));
}

FishDoor::~FishDoor()
{
}
void FishDoor::Update()
{
	bool& fishbuttonIsOpen = GetFishButtonIsOpen();
	Vecor2 vPos = GetPos();

	///-----------------물고기 버튼과의 상호작용------------
	if (fishbuttonIsOpen)
	{
		if (vPos.y >= 500)
			vPos.y -= 300 * fDT;
		else
		{
		}
	}
	else
	{
		if (vPos.y <= 700)
			vPos.y += 300 * fDT;
		else
		{
		}
	}
	SetPos(vPos);

}
void FishDoor::OnCollisionEnter(CCollider* _pOther)
{
}

void FishDoor::OnCollision(CCollider* _pOther)
{
}


void FishDoor::OnCollisionExit(CCollider* _pOther)
{
}

