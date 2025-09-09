#include "pch.h"
#include "CPlayer_Left.h"
#include "CPlayer.h"
#include "cObject.h"
#include "CKeyMgr.h"
#include "cTimeMgr.h"

#include "CScene.h"
#include "CSceneMgr.h"

#include "CResMgr.h"
#include "CTexture.h"

#include "CCollider.h"

CPlayer_Left::CPlayer_Left()
	:CPlayer()
{


	CreateCollider();

	// 피격 범위의 위치를 조절 할 수 있다.
	GetCollider()->SetOffsetPos(Vec2(0.f, 0.f));
	// 피격 범위를 조절할 수 있다.
	GetCollider()->SetScale(Vec2(50.f, 65.f));

}

CPlayer_Left::~CPlayer_Left()
{

}

void CPlayer_Left::update()
{
	Vec2 vPos = cObject::GetPos();
	int plzPlayer = m_pCollider->GetiCol();


	// 위로 이동 게임에서는 사용안할 거임
	if (KEY_HOLD(KEY::W))
	{
		vPos.y -= 2000.f * fDT;
	}
	// 왼쪽으로 이동
	if (KEY_HOLD(KEY::A))
	{
		vPos.x -= LeftRun * fDT;
		if (plzPlayer == 2)
			vPos.x += LeftRun * fDT + 5;
		if (m_isJumping)
		{
			if (plzPlayer)
			{
				vPos.x += LeftRun * fDT + 5;
			}
		}
	}
	// 오른쪽으로 이동
	if (KEY_HOLD(KEY::D))
	{
		vPos.x += (RightRun * fDT);
		if (plzPlayer == 2)
			vPos.x -= RightRun * fDT + 5;
		if (m_isJumping)
		{
			if (plzPlayer)
			{
				vPos.x -= RightRun * fDT + 5;
			}
		}
	}

	if (plzPlayer)
	{
		m_isJumping = false;	//무엇인가에 닿았으면 점프가x
		m_jumpVelocity = 0;		///중력의 세기.
	}
	else
	{
		m_isJumping = true;		//닿지 않았으면 점프 중
		m_jumpVelocity += 400.f * fDT;		///중력의 세기.
		vPos.y += m_jumpVelocity * fDT;
	}

	//스페이스바 누르면 점프
	if (KEY_HOLD(KEY::SPACE) && !m_isJumping)
	{
		m_isJumping = true;
		m_jumpVelocity = -210.0f;  /// 점프할 때의 초기 속도 설정
	}
	///중력의 크기와 점프 할 떄의 초기 설정을 고치면 점프 정도가 달라진다.
	if (m_isJumping)
	{
		// 위치 업데이트
		vPos.y += m_jumpVelocity * fDT;

	}

	cObject::SetPos(vPos);
}

void CPlayer_Left::render(HDC _dc)
{
	Vec2 vPos = cObject::GetPos();


	// 컴포넌트 (충돌체, etc
	ComPonentRender(_dc);
}

