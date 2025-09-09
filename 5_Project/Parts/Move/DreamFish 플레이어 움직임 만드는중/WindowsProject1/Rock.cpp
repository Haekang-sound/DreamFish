#include "pch.h"
#include "Rock.h"
#include "cTimeMgr.h"
#include "CCollider.h"

Rock::Rock()
{
	CreateCollider();
	// 발판 충돌 사이즈 값
	GetCollider()->SetScale(Vec2(50.f, 50.f));
}

Rock::~Rock()
{

}

void Rock::update()
{

} 

void Rock::OnCollisionEnter(CCollider* _pOther)
{
	cObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"PLAYER")
	{
		Vec2 vPos = GetPos();
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

void Rock::OnCollision(CCollider* _pOther)
{
	cObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"PLAYERWidth")
	{
		Vec2 vPos = GetPos();
		if (vPos.x < pOtherObj->GetPos().x&&vPos.y> pOtherObj->GetPos().y)	///지금 공중에서 밀어도 밀리니까 나중에 좌표값 계산해서 조건을 좀 더 정교하게 세팅하면 된다. 맵찍고나서 하자
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

void Rock::OnCollisionExit(CCollider* _pOther)
{
}