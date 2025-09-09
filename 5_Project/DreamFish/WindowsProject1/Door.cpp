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
	bool& buttonIsOpen = GetButtonIsOpen(); /// DoorButton�� isOpen ���� ���� ���� ����ȴ�.��*
	CScene* pCurScene = CSceneManager::GetInstance()->GetCurScene();	///������ �������� ����������..
	Vecor2 vPos = GetPos();

	if (pCurScene && pCurScene->GetName() == L"Stage3") ///������ �������� üũ�Ѵ�.
	{
		static Vecor2 originalPosition = vPos;

		if (buttonIsOpen)
		{
			if (vPos.y > originalPosition.y - 300.f) // ���� ���� �ִ� ���̿� �������� ���� ���
			{
				vPos.y -= 300.f * fDT; // ������ �ӵ��� �ø�
			}
		}
		else
		{
			if (vPos.y < originalPosition.y) // ���� ���� ��ġ�� �������� ���� ���
			{
				vPos.y += 300.f * fDT; // ������ �ӵ��� ����
			}
		}


		SetPos(vPos);
	}

	if (pCurScene && pCurScene->GetName() == L"Stage5") ///������ �������� üũ�Ѵ�.
	{
		static Vecor2 originalPosition = vPos;

		if (buttonIsOpen)
		{
			if (vPos.y > originalPosition.y - 300.f) // ���� ���� �ִ� ���̿� �������� ���� ���
			{
				vPos.y -= 300.f * fDT; // ������ �ӵ��� �ø�
			}
		}
		else
		{
			if (vPos.y < originalPosition.y) // ���� ���� ��ġ�� �������� ���� ���
			{
				vPos.y += 300.f * fDT; // ������ �ӵ��� ����
			}
		}


		SetPos(vPos);
	}
}

void Door::Render(HDC _dc)
{
	Vecor2 vPos = CCamera::GetInstance()->GetRenderPos(GetPos());
	SetRenderPos(vPos);

	// �ִϸ��̼����ڸ� ä��� ���� �����
	Vecor2 vScale = { 1.f, 1.f };
	CAnimator* pAni = new CAnimator;


	// �ִϸ��̼� ����
	pAni->MakeMap(_dc, vPos, vScale, 0, GROUP_TYPE::DOOR);

	// ������Ʈ (�浹ü, etc

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

