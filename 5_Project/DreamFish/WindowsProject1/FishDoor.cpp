#include "pch.h"
#include "FishDoor.h"
#include "CTimeManager.h"
#include "CCollider.h"

#include "CAnimator.h"

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
	static Vecor2 originalPosition = vPos; // 문의 원래 위치를 저장하는 변수

	if (fishbuttonIsOpen)
	{
		if (vPos.y > originalPosition.y - 300.f) // 문이 아직 최대 높이에 도달하지 않은 경우
		{
			vPos.y -= 300.f * fDT; // 일정한 속도로 올림
		}
	}

	SetPos(vPos);

}

void FishDoor::Render(HDC _dc)
{
	Vecor2 vPos = CCamera::GetInstance()->GetRenderPos(GetPos());
	SetRenderPos(vPos);

	// 애니메이션인자를 채우기 위한 내용들
	Vecor2 vScale = { 1.f, 1.f };
	CAnimator* pAni = new CAnimator;


	// 애니메이션 적용
	pAni->MakeMap(_dc, vPos, vScale, 0, GROUP_TYPE::DOOR);

	// 컴포넌트 (충돌체, etc

	delete pAni;
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

