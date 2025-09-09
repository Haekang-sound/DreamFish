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
	CScene* pCurScene = CSceneManager::GetInstance()->GetCurScene();	///������ �������� ����������..
	if (pCurScene && pCurScene->GetName() == L"Stage4") ///������ �������� üũ�Ѵ�.
	{

	bool& buttonIsOpen2 = GetButtonIsOpen2(); /// DoorButton�� isOpen ���� ���� ���� ����ȴ�.��*
	Vecor2 vPos = GetPos();
	static Vecor2 originalPosition = vPos; // ���� ���� ��ġ�� �����ϴ� ����

	if (buttonIsOpen2) 
	{
		if (vPos.y > originalPosition.y - 300.f) // ���� ���� �ִ� ���̿� �������� ���� ���
		{
			vPos.y -= 300.f * fDT; // ������ �ӵ��� �ø�
		}
	}

	SetPos(vPos);
	}
	if (pCurScene && pCurScene->GetName() == L"Stage5") ///������ �������� üũ�Ѵ�.
	{
		bool& buttonIsOpen2 = GetButtonIsOpen2(); /// DoorButton�� isOpen ���� ���� ���� ����ȴ�.��*
		Vecor2 vPos = GetPos();
		static Vecor2 originalPosition = vPos; // ���� ���� ��ġ�� �����ϴ� ����

		if (buttonIsOpen2)
		{
			if (vPos.y > originalPosition.y - 300.f) // ���� ���� �ִ� ���̿� �������� ���� ���
			{
				vPos.y -= 300.f * fDT; // ������ �ӵ��� �ø�
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

