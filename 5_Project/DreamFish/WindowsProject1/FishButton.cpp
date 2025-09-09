#include "pch.h"
#include "FishButton.h"
#include "CTimeManager.h"
#include "CCollider.h"

#include "CAnimator.h"


bool FishButton::isOpen = false; /// 초기값 설정!
void FishButton::Update()
{
}

void FishButton::Render(HDC _dc)
{

	Vecor2 vPos = CCamera::GetInstance()->GetRenderPos(GetPos());
	SetRenderPos(vPos);

	// 애니메이션인자를 채우기 위한 내용들
	CAnimator* pAni = new CAnimator;

	pAni->m_frameCount = 0;
	pAni->frameCount = 0;


	// 애니메이션인자를 채우기 위한 내용들
	Vecor2 vScale = { 1.f, 1.f };


	// 애니메이션 적용

	pAni->MakeMap(_dc, vPos, vScale, 0, GROUP_TYPE::FISHBUTTON);

	// 컴포넌트 (충돌체, etc

	delete pAni;
}

FishButton::FishButton()
{
	CreateCollider();
	// 발판 충돌 사이즈 값
	GetCollider()->SetScale(Vecor2(50.f, 200.f));
	isOpen = false;
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

