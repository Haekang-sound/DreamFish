#include "pch.h"
#include "CWall.h"
#include "CTimeManager.h"
#include "CCollider.h"


#include "CAnimator.h"


CWall::CWall()
{
	CreateCollider();
	// 발판 충돌 사이즈 값
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

	// 애니메이션인자를 채우기 위한 내용들
	Vecor2 vScale = { 1.f, 1.f };
	CAnimator* pAni = new CAnimator;


	// 애니메이션 적용
	pAni->MakeMap(_dc, vPos, vScale, 0, GROUP_TYPE::WALL);

	// 컴포넌트 (충돌체, etc

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

