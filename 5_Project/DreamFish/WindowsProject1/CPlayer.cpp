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

// �ִϸ��̼� �ʿ�
#include "CAnimator.h"


CPlayer::CPlayer()
	:m_pTex(nullptr), m_isJumping(true), m_jumpVelocity(0.0f), RightRun(170.f), LeftRun(170.f),
	m_isTouching(false), CanLeft(true), CanRight(true), CanClimb(false), DontInputS(false), touchMonster(false), isSafe_L(true), isSafe_R(true),
	Ohegang(0)
{
	// Texture �ε��ϱ�
	m_pTex = CResManager::GetInstance()->LoadTexture(L"PlayerTex", L"texture\\Girl_Animation_fixed_03.bmp");

	CreateCollider();

	// �ǰ� ������ ��ġ�� ���� �� �� �ִ�.
	GetCollider()->SetOffsetPos(Vecor2(0.f, 40.f));
	// �ǰ� ������ ������ �� �ִ�.
	GetCollider()->SetScale(Vecor2(20.f, 70.f));

}

CPlayer::~CPlayer()
{
	touchMonster = false;
}

void CPlayer::Update()
{
	Vecor2 vPos = GetPos();
	Vecor2 mousept = CKeyManager::GetInstance()->GetMousePos();
	// ���� �̵� ���ӿ����� ������ ����
	if (KEY_HOLD(KEY::W) && CanClimb && !m_isJumping)
	{
		m_onGround = true;
		m_jumpVelocity = 0;		///�߷��� ����.
		vPos.y -= 200.f * fDT;
	}
	if (KEY_HOLD(KEY::S) && CanClimb && !DontInputS)
	{
		m_onGround = true;
		m_jumpVelocity = 0;		///�߷��� ����.
		vPos.y += 200.f * fDT;
	}
	// �������� �̵�
	if (KEY_HOLD(KEY::A) && CanLeft)
	{
		vPos.x -= (LeftRun  * fDT);
		vPos.x -= (LeftRun * fDT);

	}
	// ���������� �̵�
	if (KEY_HOLD(KEY::D) && CanRight)
	{
		vPos.x += (RightRun  * fDT);
		vPos.x += (RightRun * fDT);

	}

	if ((m_isJumping == true || !m_onGround))
	{

		m_jumpVelocity += 1000.f * fDT;		///�߷��� ����.
		vPos.y += m_jumpVelocity * fDT;		///��ġ ������Ʈ

	}

	//�����̽��� ������ ����
	if (KEY_HOLD(KEY::SPACE) && !m_isJumping && m_onGround)
	{
		m_jumpVelocity = -610.0f;  /// ������ ���� �ʱ� �ӵ� ����
		m_isJumping = true;
	}
	///�߷��� ũ��� ���� �� ���� �ʱ� ������ ��ġ�� ���� ������ �޶�����.

	if (touchMonster)
	{
		m_jumpVelocity = -510.0f;  /// ������ ���� �ʱ� �ӵ� ����
		m_isJumping = true;
	}
	if (!isSafe_R)
	{
		vPos.x += (RightRun*4 * fDT);
		if (m_onGround)
			isSafe_R = true;
	}
	if (!isSafe_L)
	{
		vPos.x -= (LeftRun*4 * fDT);
		if (m_onGround)
			isSafe_L = true;
	}

	SetPos(vPos);
}

void CPlayer::Render(HDC _dc)
{
	// unsiged int ���ϴ� ���� �̹����� ������ �ֱ� ������ ����� ����. UINT �� ������ ���� �Ǵ� ���� UINT�� �ִ밪�� ��µȴ�.
	int iWidth = (int)m_pTex->Width();
	int iHeight = (int)m_pTex->Height();




	static int spriteState = 1;


	if (Ohegang!=0)
	{
		if (Ohegang==1)
			spriteState = 1;
		if (Ohegang==2)
			spriteState = 0;
	}

	if (KEY_HOLD(KEY::A) )
	{
		spriteState = 2;

	}
	if (KEY_AWAY(KEY::A) )
	{
		spriteState = 0;

	}
	// ���������� �̵�
	if (KEY_HOLD(KEY::D) )
	{
		spriteState = 3;

	}
	if (KEY_AWAY(KEY::D) )
	{
		spriteState = 1;

	}
	
	if (KEY_HOLD(KEY::S) && CanClimb || KEY_HOLD(KEY::W) && CanClimb)
	{
		spriteState = 4;
	}
	if (KEY_AWAY(KEY::S) && CanClimb || KEY_AWAY(KEY::W) && CanClimb)
	{
		spriteState = 5;
	}



	Vecor2 vPos = CCamera::GetInstance()->GetRenderPos(GetPos());
	SetRenderPos(vPos);

	// �ִϸ��̼����ڸ� ä��� ���� �����
	Vecor2 vScale = { 1.f, 1.f };
	CAnimator* pAni = new CAnimator;

	pAni->m_frameCount = 3;
	pAni->frameCount = 0;

	// �ִϸ��̼� ����
	pAni->MakeAnimation(_dc, vPos, vScale, spriteState, GROUP_TYPE::PLAYER);

	// ������Ʈ (�浹ü, etc
	ComPonentRender(_dc);

	delete pAni;

}


void CPlayer::OnCollisionEnter(CCollider* _pOther)		//����� ��
{
	CObject* pOtherObj = _pOther->GetObj();
	Vecor2 vPos = GetPos();
	if (pOtherObj->GetName() == L"FLOOR1")
	{
		if (vPos.y < pOtherObj->GetPos().y)
			m_onGround = true;
		Ohegang = 0;
		m_isJumping = false;	//�����ΰ��� ������� ������x
		m_jumpVelocity = 0;		///�߷��� ����.
		DontInputS = true;		//��ٸ� Ÿ�� �ؿ� ���հ�
	}
	if (pOtherObj->GetName() == L"FLOOR2")
	{
		if (vPos.y + 38.f + ((float)GetCollider()->GetScale().y / 2 - 10) < pOtherObj->GetPos().y - pOtherObj->GetScale().y / 2)
		{
			m_onGround = true;
			Ohegang = 0;
			m_isJumping = false;	//�����ΰ��� ������� ������x
			m_jumpVelocity = 0;		///�߷��� ����.
		}
	}

	if (pOtherObj->GetName() == L"FLOOR3")				///Ư���� ������ ���丮 �ٴ� �� �ٴ��� ��ٸ��� �����־�� �ȵȴ�.
	{
		if (vPos.y + 38.f + ((float)GetCollider()->GetScale().y / 2 - 10) < pOtherObj->GetPos().y - pOtherObj->GetScale().y / 2)
		{
			m_onGround = true;
			Ohegang = 0;
			m_isJumping = false;	//�����ΰ��� ������� ������x
			m_jumpVelocity = 0;		///�߷��� ����.
			DontInputS = true;		//��ٸ� Ÿ�� �ؿ� ���հ�
		}
	}

	if (pOtherObj->GetName() == L"Wall")
	{
		m_isTouching = true;
		if (vPos.x < pOtherObj->GetPos().x)
		{
			CanRight = false;
			RightRun = 0;
		}
		if (vPos.x > pOtherObj->GetPos().x)
		{
			CanLeft = false;
			LeftRun = 0;
		}
	}

	if (pOtherObj->GetName() == L"Door")
	{
		m_isTouching = true;
		if (vPos.x < pOtherObj->GetPos().x)
		{
			CanRight = false;
			RightRun = 0;

		}
		if (vPos.x > pOtherObj->GetPos().x)
		{
			CanLeft = false;
			LeftRun = 0;

		}
	}

	if (pOtherObj->GetName() == L"Rock")
	{
		m_onGround = true;
		m_isJumping = false;	//�����ΰ��� ������� ������x
		m_jumpVelocity = 0;		///�߷��� ����.
	}
	if (pOtherObj->GetName() == L"Ladder1")
	{

		CanClimb = true;
	}

	if (pOtherObj->GetName() == L"Shark")
	{
		touchMonster = true;
		if (vPos.x < pOtherObj->GetPos().x)
		{
			isSafe_L = false;
			Ohegang = 1;
		}
		if (vPos.x > pOtherObj->GetPos().x)
		{
			isSafe_R = false;
			Ohegang = 2;
		}
	}


	if (pOtherObj->GetName() == L"SeaUr")
	{
		if (vPos.x < pOtherObj->GetPos().x)
		{
			isSafe_L = false;
			Ohegang = 1;
		}
		if (vPos.x > pOtherObj->GetPos().x)
		{
			isSafe_R = false;
			Ohegang = 2;
		}
	}
}

void CPlayer::OnCollision(CCollider* _pOther)			//������ ��, ����ִ� ��
{
	CObject* pOtherObj = _pOther->GetObj();
	Vecor2 vPos = GetPos();
	if (pOtherObj->GetName() == L"FLOOR1")				///���� �⺻�� �Ǵ� �ٴ�, �� �ٴ��� ���� �ؿ� �־�߸� �Ѵ�. �̴� ���ؼ��� �ȵȴ�.
	{
		m_onGround = true;
		DontInputS = true;		//��ٸ� Ÿ�� �ؿ� ���հ�

	}
	if (pOtherObj->GetName() == L"FLOOR2")				///�����ý��丮 �ٴ�, �� �ٴ��� Ȯ���� �ö��� ���Ѵٸ� ��������.
	{
		if (vPos.y+ 38.f + ((float)GetCollider()->GetScale().y / 2 - 10) < pOtherObj->GetPos().y - pOtherObj->GetScale().y / 2)
			m_onGround = true;
	}
	if (pOtherObj->GetName() == L"FLOOR3")				///Ư���� ������ ���丮 �ٴ� �� �ٴ��� ��ٸ��� �����־�� �ȵȴ�.
	{
		if (vPos.y + 38.f + ((float)GetCollider()->GetScale().y / 2 - 10) < pOtherObj->GetPos().y - pOtherObj->GetScale().y / 2)
		m_onGround = true;
		DontInputS = true;		//��ٸ� Ÿ�� �ؿ� ���հ�

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
		m_isJumping = false;	//�����ΰ��� ������� ������x
		m_jumpVelocity = 0;		///�߷��� ����.

	}
	if (pOtherObj->GetName() == L"Ladder1")
	{
		CanClimb = true;
	}
	if (pOtherObj->GetName() == L"SeaUr")
	{
		touchMonster = true;
		if (vPos.x < pOtherObj->GetPos().x)
		{
			isSafe_L = false;
			Ohegang = 1;
		}
		if (vPos.x > pOtherObj->GetPos().x)
		{
			isSafe_R = false;
			Ohegang = 2;
		}
	}
}

void CPlayer::OnCollisionExit(CCollider* _pOther)		//��Ҵٰ� �������� ��
{
	CObject* pOtherObj = _pOther->GetObj();
	Vecor2 vPos = GetPos();
	if (pOtherObj->GetName() == L"FLOOR1" || pOtherObj->GetName() == L"FLOOR2")
	{
		m_onGround = false;
		DontInputS = false;		//��ٸ� Ÿ�� �ؿ� ���հ�

	}
	if (pOtherObj->GetName() == L"FLOOR3")				///Ư���� ������ ���丮 �ٴ� �� �ٴ��� ��ٸ��� �����־�� �ȵȴ�.
	{
		if (vPos.y + ((float)GetCollider()->GetScale().y / 2 - 5) < pOtherObj->GetPos().y - pOtherObj->GetScale().y / 2)
		m_onGround = false;
		DontInputS = false;		//��ٸ� Ÿ�� �ؿ� ���հ�

	}
	if (pOtherObj->GetName() == L"Wall")
	{
		m_isTouching = true;
		if (vPos.x < pOtherObj->GetPos().x)
		{
			CanRight = true;
			RightRun = 200.f;
			LeftRun = 200.f;
		}
		if (vPos.x > pOtherObj->GetPos().x)
		{
			CanLeft = true;
			RightRun = 200.f;
			LeftRun = 200.f;
		}
	}

	if (pOtherObj->GetName() == L"Door")
	{
		m_isTouching = true;
		if (vPos.x < pOtherObj->GetPos().x)
		{
			CanRight = true;
			RightRun = 200.f;
			LeftRun = 200.f;
		}
		if (vPos.x > pOtherObj->GetPos().x)
		{
			CanLeft = true;
			RightRun = 200.f;
			LeftRun = 200.f;
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

	if (pOtherObj->GetName() == L"Shark")
	{
		touchMonster = false;
	
	}

	if (pOtherObj->GetName() == L"SeaUr")
	{
		touchMonster = false;
	}

}
