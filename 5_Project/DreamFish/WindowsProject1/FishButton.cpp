#include "pch.h"
#include "FishButton.h"
#include "CTimeManager.h"
#include "CCollider.h"

#include "CAnimator.h"


bool FishButton::isOpen = false; /// �ʱⰪ ����!
void FishButton::Update()
{
}

void FishButton::Render(HDC _dc)
{

	Vecor2 vPos = CCamera::GetInstance()->GetRenderPos(GetPos());
	SetRenderPos(vPos);

	// �ִϸ��̼����ڸ� ä��� ���� �����
	CAnimator* pAni = new CAnimator;

	pAni->m_frameCount = 0;
	pAni->frameCount = 0;


	// �ִϸ��̼����ڸ� ä��� ���� �����
	Vecor2 vScale = { 1.f, 1.f };


	// �ִϸ��̼� ����

	pAni->MakeMap(_dc, vPos, vScale, 0, GROUP_TYPE::FISHBUTTON);

	// ������Ʈ (�浹ü, etc

	delete pAni;
}

FishButton::FishButton()
{
	CreateCollider();
	// ���� �浹 ������ ��
	GetCollider()->SetScale(Vecor2(50.f, 200.f));
	isOpen = false;
}

FishButton::~FishButton()
{

}

void FishButton::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"FISH")
	{
		isOpen = true;
	}
}
void FishButton::OnCollision(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"FISH")
	{
		isOpen = true;
	}
}

void FishButton::OnCollisionExit(CCollider* _pOther)
{

}

