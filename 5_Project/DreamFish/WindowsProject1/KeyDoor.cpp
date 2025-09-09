#include "pch.h"
#include "KeyDoor.h"
#include "CTimeManager.h"
#include "CCollider.h"
#include "DoorKey.h"
#include "CScene.h"
#include "CSceneManager.h"
KeyDoor::KeyDoor()
{
	CreateCollider();
	GetCollider()->SetScale(Vecor2(50.f, 200.f));
}

KeyDoor::~KeyDoor()
{
}

void KeyDoor::Update()
{
	CScene* pCurScene = CSceneManager::GetInstance()->GetCurScene();	///현재의 씬정보를 얻어오기위한..
	if (pCurScene && pCurScene->GetName() == L"Stage4") ///현재의 씬정보를 체크한다.
	{

	bool& buttonIsOpen2 = GetButtonIsOpen2(); /// DoorButton의 isOpen 값을 참조 이후 쓰면된다.ㅇ*
	Vecor2 vPos = GetPos();
	static Vecor2 originalPosition = vPos; // 문의 원래 위치를 저장하는 변수

	if (buttonIsOpen2) 
	{
		if (vPos.y > originalPosition.y - 300.f) // 문이 아직 최대 높이에 도달하지 않은 경우
		{
			vPos.y -= 300.f * fDT; // 일정한 속도로 올림
		}
	}

	SetPos(vPos);
	}
	if (pCurScene && pCurScene->GetName() == L"Stage5") ///현재의 씬정보를 체크한다.
	{
		bool& buttonIsOpen2 = GetButtonIsOpen2(); /// DoorButton의 isOpen 값을 참조 이후 쓰면된다.ㅇ*
		Vecor2 vPos = GetPos();
		static Vecor2 originalPosition = vPos; // 문의 원래 위치를 저장하는 변수

		if (buttonIsOpen2)
		{
			if (vPos.y > originalPosition.y - 300.f) // 문이 아직 최대 높이에 도달하지 않은 경우
			{
				vPos.y -= 300.f * fDT; // 일정한 속도로 올림
			}
		}

		SetPos(vPos);
	}


}

void KeyDoor::OnCollisionEnter(CCollider* _pOther)
{

}

void KeyDoor::OnCollision(CCollider* _pOther)
{

}


void KeyDoor::OnCollisionExit(CCollider* _pOther)
{

}

