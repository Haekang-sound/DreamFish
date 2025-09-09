#include "pch.h"
#include "DoorButton.h"
#include "CTimeManager.h"
#include "CCollider.h"

#include "CAnimator.h"





bool DoorButton::isOpen = false; /// �ʱⰪ ����!
void DoorButton::Update()
{
}

void DoorButton::Render(HDC _dc)
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

	pAni->MakeMap(_dc, vPos, vScale, 0, GROUP_TYPE::DOORBUTTON);

	// ������Ʈ (�浹ü, etc

	delete pAni;
}

DoorButton::DoorButton()
{
	CreateCollider();
	// ���� �浹 ������ ��
	GetCollider()->SetScale(Vecor2(50.f, 200.f));
	isOpen = false;
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

