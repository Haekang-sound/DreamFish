#include "pch.h"
#include "SeaUr.h"
#include "CTimeManager.h"
#include "CCollider.h"
#include "DoorButton.h"
#include "Shark.h"
#include "Stage4.h"


// �ִϸ��̼� �ʿ�
#include "CAnimator.h"
#include "CResManager.h"


Shark::Shark()
    :moveSpeed(300.f), m_pTex(nullptr)
{

    m_pTex = CResManager::GetInstance()->LoadTexture(L"SharkTex", L"texture\\Shark_Animation.bmp");
	CreateCollider();
	GetCollider()->SetScale(Vecor2(0.f, 0.f));
	Vecor2 firstShark = Shark::GetPos();
}

Shark::~Shark()
{

}

void Shark::Update()
{
	bool& haveBattery = HaveBattery();
	Vecor2 vPos = GetPos();
	

	if (!haveBattery)
	{		
		static float distance1 = 200.f + vPos.x;
		static float distance2 = vPos.x - 200.f;

		if (vPos.x >= distance1)
		{
			moveSpeed *= -1;  // �̵� ������ �ݴ�� �����մϴ�.
		}
		else if (vPos.x<=distance2)
		{
			moveSpeed *= -1;
		}

		vPos.x += moveSpeed * fDT;
		SetPos(vPos);
	}
	else
	{
		/// ��� ���� (5000,5000)���� ������
		vPos.x = 5000.f;
		vPos.y = 5000.f;
		SetPos(vPos);
	}
}

void Shark::Render(HDC _dc)
{
	bool& haveBattery = HaveBattery();

	if (!haveBattery)
	{
		static int spriteState = 1;
		if (moveSpeed <  0)
		{
			spriteState = 0;
		}
		else
		{
			spriteState = 1;
		}

		// �ִϸ��̼����ڸ� ä��� ���� �����
		Vecor2 vScale = { 1.f, 1.f };

		Vecor2 vPos = CCamera::GetInstance()->GetRenderPos(GetPos());

		SetRenderPos(vPos);

		CAnimator* pAni = new CAnimator;
		pAni->MakeAnimation(_dc, vPos, vScale, spriteState, GROUP_TYPE::MONSTER);
		delete pAni;
	}


}

void Shark::OnCollisionEnter(CCollider* _pOther)
{

}

void Shark::OnCollision(CCollider* _pOther)
{
	
}

void Shark::OnCollisionExit(CCollider* _pOther)
{

}