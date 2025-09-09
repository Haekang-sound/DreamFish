#include "pch.h"
#include "FishButton.h"
#include "CTimeManager.h"
#include "CCollider.h"



bool FishButton::isOpen = false; /// �ʱⰪ ����!
void FishButton::Update()
{
}

FishButton::FishButton()
{
	CreateCollider();
	// ���� �浹 ������ ��
	GetCollider()->SetScale(Vecor2(50.f, 200.f));
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

