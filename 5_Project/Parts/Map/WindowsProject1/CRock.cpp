#include "pch.h"
#include "CRock.h"
#include "CTimeManager.h"
#include "CKeyManager.h"
#include "CCollider.h"
#include "CScene.h"
#include "CSceneManager.h"


CRock::CRock()
:isTouchWall(false)
{
	m_onGround = false;

	CreateCollider();
	// ���� �浹 ������ ��
	GetCollider()->SetScale(Vecor2(50.f, 50.f));
}

CRock::~CRock()
{

}

void CRock::Update()
{


	Vecor2 vPos = GetPos();
	if (!m_onGround)
	{
		vPos.y += 1000.f * fDT;
	}

	if (KEY_HOLD(KEY::G))
	{
		CScene* pCurScene = CSceneManager::GetInstance()->GetCurScene();	///������ �������� ����������..
		if (pCurScene && pCurScene->GetName() == L"Start TOOL")				///������ �������� üũ�Ѵ�.
		{
			vPos.x = 300.f;
			vPos.y = 200.f;
		}
	}




	SetPos(vPos);
}

void CRock::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();

	if (pOtherObj->GetName() == L"Wall")
	{
		isTouchWall = true;
		Vecor2 vPos = GetPos();
		if (vPos.x < pOtherObj->GetPos().x && vPos.y> pOtherObj->GetPos().y)
		{
			vPos.x -= 200.0f * fDT;
		}
		if (vPos.x > pOtherObj->GetPos().x && vPos.y > pOtherObj->GetPos().y)
		{
			vPos.x += 200.0f * fDT;
		}
		SetPos(vPos);

	}
	if (pOtherObj->GetName() == L"PLAYER")
	{

		Vecor2 vPos = GetPos();
		if (vPos.x < pOtherObj->GetPos().x && vPos.y> pOtherObj->GetPos().y)
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

void CRock::OnCollision(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();

	if (pOtherObj->GetName() == L"Wall")
	{
		isTouchWall = true;
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
	if (pOtherObj->GetName() == L"PLAYERWidth" && pOtherObj->IsGround())
	{

		Vecor2 vPos = GetPos();
		if (vPos.x < pOtherObj->GetPos().x )	///���� ���߿��� �о �и��ϱ� ���߿� ��ǥ�� ����ؼ� ������ �� �� �����ϰ� �����ϸ� �ȴ�. ������� ����
		{
			vPos.x -= 200.0f * fDT;
		}
		if (vPos.x > pOtherObj->GetPos().x )
		{
			vPos.x += 200.0f * fDT;
		}
		SetPos(vPos);
	}
	if (pOtherObj->GetName() == L"FLOOR1")
	{
		m_onGround = true;
	}
	if (pOtherObj->GetName() == L"FLOOR2")
	{
		m_onGround = true;
	}
	if (pOtherObj->GetName() == L"FLOOR3")
	{
		m_onGround = true;
	}
}

void CRock::OnCollisionExit(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"FLOOR1")
	{
		m_onGround = false;
	}
	if (pOtherObj->GetName() == L"FLOOR2")
	{
		m_onGround = false;
	}
	if (pOtherObj->GetName() == L"FLOOR3")
	{
		m_onGround = false;
	}

}