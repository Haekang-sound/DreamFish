#include "pch.h"
#include "Rock.h"
#include "cTimeMgr.h"
#include "CCollider.h"

Rock::Rock()
{
	CreateCollider();
	// ���� �浹 ������ ��
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
		if (vPos.x < pOtherObj->GetPos().x&&vPos.y> pOtherObj->GetPos().y)	///���� ���߿��� �о �и��ϱ� ���߿� ��ǥ�� ����ؼ� ������ �� �� �����ϰ� �����ϸ� �ȴ�. ������� ����
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