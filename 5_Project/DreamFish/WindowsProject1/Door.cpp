#include "pch.h"
#include "Door.h"
#include "CTimeManager.h"
#include "CCollider.h"
#include "DoorButton.h"
#include "DoorKey.h"
#include "CScene.h"
#include "CSceneManager.h"
#include "CAnimator.h"

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
	bool& buttonIsOpen = GetButtonIsOpen(); /// DoorButton의 isOpen 값을 참조 이후 쓰면된다.ㅇ*
	CScene* pCurScene = CSceneManager::GetInstance()->GetCurScene();	///현재의 씬정보를 얻어오기위한..
	Vecor2 vPos = GetPos();

	if (pCurScene && pCurScene->GetName() == L"Stage3") ///현재의 씬정보를 체크한다.
	{
		static Vecor2 originalPosition = vPos;

		if (buttonIsOpen)
		{
			if (vPos.y > originalPosition.y - 300.f) // 문이 아직 최대 높이에 도달하지 않은 경우
			{
				vPos.y -= 300.f * fDT; // 일정한 속도로 올림
			}
		}
		else
		{
			if (vPos.y < originalPosition.y) // 문이 원래 위치에 도달하지 않은 경우
			{
				vPos.y += 300.f * fDT; // 일정한 속도로 내림
			}
		}


		SetPos(vPos);
	}

	if (pCurScene && pCurScene->GetName() == L"Stage5") ///현재의 씬정보를 체크한다.
	{
		static Vecor2 originalPosition = vPos;

		if (buttonIsOpen)
		{
			if (vPos.y > originalPosition.y - 300.f) // 문이 아직 최대 높이에 도달하지 않은 경우
			{
				vPos.y -= 300.f * fDT; // 일정한 속도로 올림
			}
		}
		else
		{
			if (vPos.y < originalPosition.y) // 문이 원래 위치에 도달하지 않은 경우
			{
				vPos.y += 300.f * fDT; // 일정한 속도로 내림
			}
		}


		SetPos(vPos);
	}
}

void Door::Render(HDC _dc)
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

void Door::OnCollisionEnter(CCollider* _pOther)
{

}

void Door::OnCollision(CCollider* _pOther)
{

}



void Door::OnCollisionExit(CCollider* _pOther)
{

}

