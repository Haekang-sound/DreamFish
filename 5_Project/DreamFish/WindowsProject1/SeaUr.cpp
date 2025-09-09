#include "pch.h"
#include "SeaUr.h"
#include "CTimeManager.h"
#include "CCollider.h"
#include "DoorButton.h"

#include "CAnimator.h"


SeaUr::SeaUr()
{
	CreateCollider();
	GetCollider()->SetScale(Vecor2(50.f, 200.f));
}

SeaUr::~SeaUr()
{

}

void SeaUr::Update()
{

}

void SeaUr::Render(HDC _dc)
{
	Vecor2 vPos = CCamera::GetInstance()->GetRenderPos(GetPos());
	SetRenderPos(vPos);

	// �ִϸ��̼����ڸ� ä��� ���� �����
	Vecor2 vScale = { 1.f, 1.f };
	CAnimator* pAni = new CAnimator;


	// �ִϸ��̼� ����
	pAni->MakeMap(_dc, vPos, vScale, 0, GROUP_TYPE::SEAUR);

	// ������Ʈ (�浹ü, etc

	delete pAni;
	
}

void SeaUr::OnCollisionEnter(CCollider* _pOther)
{

}

void SeaUr::OnCollision(CCollider* _pOther)
{

}

void SeaUr::OnCollisionExit(CCollider* _pOther)
{

}

