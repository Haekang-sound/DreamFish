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
	// 발판 충돌 사이즈 값
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
		CScene* pCurScene = CSceneManager::GetInstance()->GetCurScene();	///현재의 씬정보를 얻어오기위한..
		if (pCurScene && pCurScene->GetName() == L"Start TOOL")				///현재의 씬정보를 체크한다.
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
		if (vPos.x < pOtherObj->GetPos().x )	///지금 공중에서 밀어도 밀리니까 나중에 좌표값 계산해서 조건을 좀 더 정교하게 세팅하면 된다. 맵찍고나서 하자
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