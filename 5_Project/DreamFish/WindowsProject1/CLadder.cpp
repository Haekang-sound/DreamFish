#include "pch.h"
#include "CLadder.h"
#include "CTimeManager.h"
#include "CCollider.h"

#include "CAnimator.h"


CLadder::CLadder()
{
	CreateCollider();

}

CLadder::~CLadder()
{
}

void CLadder::Update()
{
}

void CLadder::Render(HDC _dc)
{
	Vecor2 vPos = CCamera::GetInstance()->GetRenderPos(GetPos());
	SetRenderPos(vPos);

	// �ִϸ��̼����ڸ� ä��� ���� �����
	Vecor2 vScale = { 1.f, 1.f };
	CAnimator* pAni = new CAnimator;


	// �ִϸ��̼� ����
	pAni->MakeMap(_dc, vPos, vScale, 0, GROUP_TYPE::LADDER);

	// ������Ʈ (�浹ü, etc

	delete pAni;
}

void CLadder::OnCollisionEnter(CCollider* _pOther)
{
}

void CLadder::OnCollision(CCollider* _pOther)
{
}


void CLadder::OnCollisionExit(CCollider* _pOther)
{
}

