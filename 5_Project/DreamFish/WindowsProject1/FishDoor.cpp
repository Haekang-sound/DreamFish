#include "pch.h"
#include "FishDoor.h"
#include "CTimeManager.h"
#include "CCollider.h"

#include "CAnimator.h"

FishDoor::FishDoor()
{
	CreateCollider();
	// ���� �浹 ������ ��
	GetCollider()->SetScale(Vecor2(50.f, 200.f));

}

FishDoor::~FishDoor()
{
}
void FishDoor::Update()
{
	bool& fishbuttonIsOpen = GetFishButtonIsOpen();
	Vecor2 vPos = GetPos();
	static Vecor2 originalPosition = vPos; // ���� ���� ��ġ�� �����ϴ� ����

	if (fishbuttonIsOpen)
	{
		if (vPos.y > originalPosition.y - 300.f) // ���� ���� �ִ� ���̿� �������� ���� ���
		{
			vPos.y -= 300.f * fDT; // ������ �ӵ��� �ø�
		}
	}

	SetPos(vPos);

}

void FishDoor::Render(HDC _dc)
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


void FishDoor::OnCollisionEnter(CCollider* _pOther)
{
}

void FishDoor::OnCollision(CCollider* _pOther)
{
}


void FishDoor::OnCollisionExit(CCollider* _pOther)
{
}

