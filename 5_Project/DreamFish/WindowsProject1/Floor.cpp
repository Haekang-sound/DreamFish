#include "pch.h"
#include "Floor.h"

#include "CCollider.h"

#include "CAnimator.h"


Floor::Floor()
{

	CreateCollider();
	// 발판 충돌 사이즈 값
	GetCollider()->SetScale(Vecor2(1200.f, 50.f));
}

Floor::~Floor()
{

}

void Floor::Update()
{

}

void Floor::Render(HDC _dc)
{
	Vecor2 vPos = CCamera::GetInstance()->GetRenderPos(GetPos());
	SetRenderPos(vPos);

	// 애니메이션인자를 채우기 위한 내용들
	Vecor2 vScale = { 1.f, 1.f };
	CAnimator* pAni = new CAnimator;


	// 애니메이션 적용
	pAni->MakeMap(_dc, vPos, vScale, 0, GROUP_TYPE::FLOOR);

	// 컴포넌트 (충돌체, etc

	delete pAni;

}

void Floor::OnCollision(CCollider* _pOther)
{
	// 충돌이 된다.
	CObject* pOtherObj = _pOther->GetObj();
}