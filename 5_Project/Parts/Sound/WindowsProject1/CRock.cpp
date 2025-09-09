#include "pch.h"
#include "CRock.h"
#include "CTimeManager.h"
#include "CCollider.h"

CRock::CRock()
{
	CreateCollider();
	// 발판 충돌 사이즈 값
	GetCollider()->SetScale(Vecor2(50.f, 50.f));
}

CRock::~CRock()
{

}

void CRock::Update()
{

}

void CRock::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"PLAYER")
	{
		Vecor2 vPos = GetPos();
		if (vPos.x < pOtherObj->GetPos().x)
		{
			vPos.x -= 200.0f * fDT;
		}
		if (vPos.x > pOtherObj->GetPos().x)
		{
			vPos.x += 200.0f * fDT;
		}
		SetPos(vPos);
	}
}

void CRock::OnCollision(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"PLAYERWidth")
	{
		Vecor2 vPos = GetPos();
		if (vPos.x < pOtherObj->GetPos().x && vPos.y> pOtherObj->GetPos().y)	///지금 공중에서 밀어도 밀리니까 나중에 좌표값 계산해서 조건을 좀 더 정교하게 세팅하면 된다. 맵찍고나서 하자
		{
			vPos.x -= 200.0f * fDT;
		}
		if (vPos.x > pOtherObj->GetPos().x && vPos.y > pOtherObj->GetPos().y)
		{
			vPos.x += 200.0f * fDT;
		}
		SetPos(vPos);
	}
}

void CRock::OnCollisionExit(CCollider* _pOther)
{
}