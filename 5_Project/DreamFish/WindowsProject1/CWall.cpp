#include "pch.h"
#include "CWall.h"
#include "CTimeManager.h"
#include "CCollider.h"


#include "CAnimator.h"


CWall::CWall()
{
	CreateCollider();
	// ���� �浹 ������ ��
	GetCollider()->SetScale(Vecor2(50.f, 200.f));
}

CWall::~CWall()
{
}

void CWall::Update()
{
}

void CWall::Render(HDC _dc)
{
	Vecor2 vPos = CCamera::GetInstance()->GetRenderPos(GetPos());
	SetRenderPos(vPos);

	// �ִϸ��̼����ڸ� ä��� ���� �����
	Vecor2 vScale = { 1.f, 1.f };
	CAnimator* pAni = new CAnimator;


	// �ִϸ��̼� ����
	pAni->MakeMap(_dc, vPos, vScale, 0, GROUP_TYPE::WALL);

	// ������Ʈ (�浹ü, etc

	delete pAni;
}

void CWall::OnCollisionEnter(CCollider* _pOther)
{
}

void CWall::OnCollision(CCollider* _pOther)
{
}


void CWall::OnCollisionExit(CCollider* _pOther)
{
}

