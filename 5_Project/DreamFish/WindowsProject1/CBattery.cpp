#include "pch.h"
#include "CBattery.h"
#include "CTimeManager.h"
#include "CCollider.h"
#include "CAnimator.h"

bool CBattery::isHave = false; /// 초기값 설정!
void CBattery::Update()
{

}

void CBattery::Render(HDC _dc)
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
	
	pAni->MakeMap(_dc, vPos, vScale, 0, GROUP_TYPE::BATTERAY);

	// 컴포넌트 (충돌체, etc

	delete pAni;
}

CBattery::CBattery()
{
	CreateCollider();
	// 발판 충돌 사이즈 값
	GetCollider()->SetScale(Vecor2(100.f, 100.f));
	isHave = false;
}

CBattery::~CBattery()
{

}

void CBattery::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	if(pOtherObj->GetPos().x!=0.f)
	{
		if (pOtherObj->GetName() == L"PLAYER")
		{
			isHave = true; /// 배터리 소유상태
		}
	}
}

void CBattery::OnCollision(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"PLAYER")
	{
		isHave = true; /// 배터리 소유상태
	}
}

void CBattery::OnCollisionExit(CCollider* _pOther)
{

}
