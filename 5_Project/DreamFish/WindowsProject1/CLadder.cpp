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

	// 애니메이션인자를 채우기 위한 내용들
	Vecor2 vScale = { 1.f, 1.f };
	CAnimator* pAni = new CAnimator;


	// 애니메이션 적용
	pAni->MakeMap(_dc, vPos, vScale, 0, GROUP_TYPE::LADDER);

	// 컴포넌트 (충돌체, etc

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

