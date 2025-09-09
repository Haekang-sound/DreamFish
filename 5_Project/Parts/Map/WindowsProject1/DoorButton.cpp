#include "pch.h"
#include "DoorButton.h"
#include "CTimeManager.h"
#include "CCollider.h"



bool DoorButton::isOpen = false; /// �ʱⰪ ����!
void DoorButton::Update()
{
}

DoorButton::DoorButton()
{
	CreateCollider();
	// ���� �浹 ������ ��
	GetCollider()->SetScale(Vecor2(50.f, 200.f));
}

DoorButton::~DoorButton()
{
}
void DoorButton::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"PLAYER")
	{
		isOpen = true;
	}
	if (pOtherObj->GetName() == L"Rock")
	{
		isOpen = true;
	}
}
void DoorButton::OnCollision(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"PLAYER")
	{
		isOpen = true;
	}
	if (pOtherObj->GetName() == L"Rock")
	{
		isOpen = true;

	}
}

void DoorButton::OnCollisionExit(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"PLAYER")
	{
		isOpen = false;

	}
	if (pOtherObj->GetName() == L"Rock")
	{
		isOpen = false;

	}
}

