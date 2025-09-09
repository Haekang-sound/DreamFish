#include "pch.h"
#include "CPlayer.h"

#include "CKeyManager.h"
#include "CTimeManager.h"

#include "CScene.h"
#include "CSceneManager.h"

#include "CResManager.h"
#include "CTexture.h"

#include "COtherCollider.h"
#include "CGameProcess.h"

// 애니메이션 필요
#include "CAnimator.h"


CPlayer::CPlayer()
	:m_pTex(nullptr), m_isJumping(true), m_jumpVelocity(0.0f), RightRun(200.0f), LeftRun(200.0f), m_isTouching(false), CanLeft(true), CanRight(true), CanClimb(false), DontInputS(false)
{
	// Texture 로딩하기
	m_pTex = CResManager::GetInstance()->LoadTexture(L"PlayerTex", L"texture\\image.bmp");

	CreateCollider();

	// 피격 범위의 위치를 조절 할 수 있다.
	GetCollider()->SetOffsetPos(Vecor2(0.f, 0.f));
	// 피격 범위를 조절할 수 있다.
	GetCollider()->SetScale(Vecor2(45.f, 70.f));

}

CPlayer::~CPlayer()
{

}

void CPlayer::Update()
{
	Vecor2 vPos = GetPos();

	// 위로 이동 게임에서는 사용안할 거임
	if (KEY_HOLD(KEY::W) && CanClimb && !m_isJumping)
	{
		m_onGround = true;
		m_jumpVelocity = 0;		///중력의 세기.
		vPos.y -= 200.f * fDT;
	}
	if (KEY_HOLD(KEY::S) && CanClimb && !DontInputS)
	{
		m_onGround = true;
		m_jumpVelocity = 0;		///중력의 세기.
		vPos.y += 200.f * fDT;
	}
	// 왼쪽으로 이동
	if (KEY_HOLD(KEY::A) && CanLeft)
	{
		vPos.x -= LeftRun * fDT;

	}
	// 오른쪽으로 이동
	if (KEY_HOLD(KEY::D) && CanRight)
	{
		vPos.x += (RightRun * fDT);

	}

	if ((m_isJumping == true || !m_onGround))
	{

		m_jumpVelocity += 1000.f * fDT;		///중력의 세기.
		vPos.y += m_jumpVelocity * fDT;		///위치 업데이트

	}

	//스페이스바 누르면 점프
	if (KEY_HOLD(KEY::SPACE) && !m_isJumping && m_onGround)
	{
		m_jumpVelocity = -510.0f;  /// 점프할 때의 초기 속도 설정
		m_isJumping = true;
	}
	///중력의 크기와 점프 할 떄의 초기 설정을 고치면 점프 정도가 달라진다.


	SetPos(vPos);
}

void CPlayer::Render(HDC _dc)
{
	// unsiged int 안하는 이유 이미지는 음수도 있기 때문에 상관이 없다. UINT 는 음수로 가게 되는 순간 UINT의 최대값이 출력된다.
	int iWidth = (int)m_pTex->Width();
	int iHeight = (int)m_pTex->Height();




	int spriteState = 0;

	if (KEY_HOLD(KEY::A))
	{
		spriteState = 2;

	}
	// 오른쪽으로 이동
	else if (KEY_HOLD(KEY::D))
	{
		spriteState = 3;

	}

	Vecor2 vPos = CCamera::GetInstance()->GetRenderPos(GetPos());
	SetRenderPos(vPos);

	// 애니메이션인자를 채우기 위한 내용들
	Vecor2 vScale = { 1.f, 1.f };
	CAnimator* pAni = new CAnimator;

	// 애니메이션 적용
	pAni->MakeAnimation(_dc, vPos, vScale, spriteState, GROUP_TYPE::PLAYER);

	// 컴포넌트 (충돌체, etc
	ComPonentRender(_dc);

	delete pAni;

}


void CPlayer::OnCollisionEnter(CCollider* _pOther)		//닿았을 때
{
	CObject* pOtherObj = _pOther->GetObj();
	Vecor2 vPos = GetPos();
	if (pOtherObj->GetName() == L"FLOOR1")
	{
		if (vPos.y < pOtherObj->GetPos().y)
			m_onGround = true;

		m_isJumping = false;	//무엇인가에 닿았으면 점프가x
		m_jumpVelocity = 0;		///중력의 세기.
		DontInputS = true;		//사다리 타고 밑에 못뚫게
	}
	if (pOtherObj->GetName() == L"FLOOR2")
	{
		if (vPos.y + ((float)GetCollider()->GetScale().y / 2 - 5) < pOtherObj->GetPos().y - pOtherObj->GetScale().y / 2)
			m_onGround = true;

		m_isJumping = false;	//무엇인가에 닿았으면 점프가x
		m_jumpVelocity = 0;		///중력의 세기.
	}

	if (pOtherObj->GetName() == L"FLOOR3")				///특수한 메이플 스토리 바닥 이 바닥은 사다리가 걸쳐있어서는 안된다.
	{
		if (vPos.y + ((float)GetCollider()->GetScale().y / 2 - 5) < pOtherObj->GetPos().y - pOtherObj->GetScale().y / 2)
			m_onGround = true;

		m_isJumping = false;	//무엇인가에 닿았으면 점프가x
		m_jumpVelocity = 0;		///중력의 세기.
		DontInputS = true;		//사다리 타고 밑에 못뚫게

	}

	if (pOtherObj->GetName() == L"Wall")
	{
		m_isTouching = true;
		if (vPos.x < pOtherObj->GetPos().x)
		{
			CanRight = false;
		}
		if (vPos.x > pOtherObj->GetPos().x)
		{
			CanLeft = false;
		}
	}

	if (pOtherObj->GetName() == L"Door")
	{
		m_isTouching = true;
		if (vPos.x < pOtherObj->GetPos().x)
		{
			CanRight = false;
		}
		if (vPos.x > pOtherObj->GetPos().x)
		{
			CanLeft = false;
		}
	}

	if (pOtherObj->GetName() == L"Rock")
	{
		m_onGround = true;
		m_isJumping = false;	//무엇인가에 닿았으면 점프가x
		m_jumpVelocity = 0;		///중력의 세기.
	}
	if (pOtherObj->GetName() == L"Ladder1")
	{

		CanClimb = true;
	}
}

void CPlayer::OnCollision(CCollider* _pOther)			//겹쳤을 때, 닿고있는 중
{
	CObject* pOtherObj = _pOther->GetObj();
	Vecor2 vPos = GetPos();
	if (pOtherObj->GetName() == L"FLOOR1")				///가장 기본이 되는 바닥, 이 바닥은 제일 밑에 있어야만 한다. 이는 변해서는 안된다.
	{
		m_onGround = true;
		DontInputS = true;		//사다리 타고 밑에 못뚫게

	}
	if (pOtherObj->GetName() == L"FLOOR2")				///메이플스토리 바닥, 이 바닥은 확실히 올라서지 못한다면 떨어진다.
	{
		if (vPos.y + ((float)GetCollider()->GetScale().y / 2 - 5) < pOtherObj->GetPos().y - pOtherObj->GetScale().y / 2)
			m_onGround = true;
	}
	if (pOtherObj->GetName() == L"FLOOR3")				///특수한 메이플 스토리 바닥 이 바닥은 사다리가 걸쳐있어서는 안된다.
	{
		if (vPos.y + ((float)GetCollider()->GetScale().y / 2 - 5) < pOtherObj->GetPos().y - pOtherObj->GetScale().y / 2)
		m_onGround = true;
		DontInputS = true;		//사다리 타고 밑에 못뚫게

	}
	if (pOtherObj->GetName() == L"Wall")
	{

		m_isTouching = true;
		if (vPos.x < pOtherObj->GetPos().x)
		{
			CanRight = false;
		}
		if (vPos.x > pOtherObj->GetPos().x)
		{
			CanLeft = false;
		}
	}

	if (pOtherObj->GetName() == L"Door")
	{

		m_isTouching = true;
		if (vPos.x < pOtherObj->GetPos().x)
		{
			CanRight = false;
		}
		if (vPos.x > pOtherObj->GetPos().x)
		{
			CanLeft = false;
		}
	}

	if (pOtherObj->GetName() == L"Rock")
	{
		m_onGround = true;
		m_isJumping = false;	//무엇인가에 닿았으면 점프가x
		m_jumpVelocity = 0;		///중력의 세기.
	}
	if (pOtherObj->GetName() == L"Ladder1")
	{
		CanClimb = true;
	}
}

void CPlayer::OnCollisionExit(CCollider* _pOther)		//닿았다가 떨어졌을 때
{
	CObject* pOtherObj = _pOther->GetObj();
	Vecor2 vPos = GetPos();
	if (pOtherObj->GetName() == L"FLOOR1" || pOtherObj->GetName() == L"FLOOR2")
	{
		m_onGround = false;
		DontInputS = false;		//사다리 타고 밑에 못뚫게

	}
	if (pOtherObj->GetName() == L"FLOOR3")				///특수한 메이플 스토리 바닥 이 바닥은 사다리가 걸쳐있어서는 안된다.
	{
		if (vPos.y + ((float)GetCollider()->GetScale().y / 2 - 5) < pOtherObj->GetPos().y - pOtherObj->GetScale().y / 2)
		m_onGround = false;
		DontInputS = false;		//사다리 타고 밑에 못뚫게

	}
	if (pOtherObj->GetName() == L"Wall")
	{
		m_isTouching = true;
		if (vPos.x < pOtherObj->GetPos().x)
		{
			CanRight = true;

		}
		if (vPos.x > pOtherObj->GetPos().x)
		{
			CanLeft = true;
		}
	}

	if (pOtherObj->GetName() == L"Door")
	{
		m_isTouching = true;
		if (vPos.x < pOtherObj->GetPos().x)
		{
			CanRight = true;

		}
		if (vPos.x > pOtherObj->GetPos().x)
		{
			CanLeft = true;
		}
	}

	if (pOtherObj->GetName() == L"Rock")
	{

		m_onGround = false;

	}
	if (pOtherObj->GetName() == L"Ladder1")
	{
		m_onGround = false;
		CanClimb = false;
	}
}
