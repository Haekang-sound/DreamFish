#include "pch.h"
#include "CRock.h"
#include "CTimeManager.h"
#include "CCollider.h"

CRock::CRock()
{
	CreateCollider();
	// ���� �浹 ������ ��
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
		if (vPos.x < pOtherObj->GetPos().x && vPos.y> pOtherObj->GetPos().y)	///���� ���߿��� �о �и��ϱ� ���߿� ��ǥ�� ����ؼ� ������ �� �� �����ϰ� �����ϸ� �ȴ�. ������� ����
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