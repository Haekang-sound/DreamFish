#include "pch.h"
#include "DoorKey.h"
#include "CTimeManager.h"
#include "CCollider.h"
#include "CAnimator.h"

bool DoorKey::isOpen = false; /// 초기값 설정!
void DoorKey::Update()
{

}

void DoorKey::Render(HDC _dc)
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

	pAni->MakeMap(_dc, vPos, vScale, 0, GROUP_TYPE::DOORKEY);

	// 컴포넌트 (충돌체, etc

	delete pAni;
}

DoorKey::DoorKey()
{
	CreateCollider();
	// 발판 충돌 사이즈 값
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

