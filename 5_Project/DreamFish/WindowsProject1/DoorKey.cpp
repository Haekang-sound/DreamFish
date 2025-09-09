#include "pch.h"
#include "DoorKey.h"
#include "CTimeManager.h"
#include "CCollider.h"
#include "CAnimator.h"

bool DoorKey::isOpen = false; /// �ʱⰪ ����!
void DoorKey::Update()
{

}

void DoorKey::Render(HDC _dc)
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

	pAni->MakeMap(_dc, vPos, vScale, 0, GROUP_TYPE::DOORKEY);

	// ������Ʈ (�浹ü, etc

	delete pAni;
}

DoorKey::DoorKey()
{
	CreateCollider();
	// ���� �浹 ������ ��
	GetCollider()->SetScale(Vecor2(50.f, 200.f));
	isOpen = false;
}

DoorKey::~DoorKey()
{

}

void DoorKey::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"PLAYER")
	{
		isOpen = true;
	}
	if (pOtherObj->GetName() == L"FISH")
	{
		isOpen = true;
	}

}

void DoorKey::OnCollision(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"PLAYER")
	{
		isOpen = true;
	}
}

void DoorKey::OnCollisionExit(CCollider* _pOther)
{

}

