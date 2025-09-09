#include "pch.h"
#include "CPlayer.h"

#include "CKeyMgr.h"
#include "cTimeMgr.h"

#include "CScene.h"
#include "CSceneMgr.h"

#include "CResMgr.h"
#include "CTexture.h"

#include "CCollider.h"



CPlayer::CPlayer()
	:m_pTex(nullptr), m_isJumping(true), m_jumpVelocity(0.0f), RightRun(200.0f), LeftRun(200.0f), m_onGround(true), m_isTouching(false), CanLeft(true), CanRight(true), CanClimb(false), DontInputS(false)
{
	// Texture �ε��ϱ�
	m_pTex = CResMgr::GetInst()->LoadTexture(L"PlayerTex", L"texture\\image.bmp");

	CreateCollider();

	// �ǰ� ������ ��ġ�� ���� �� �� �ִ�.
	GetCollider()->SetOffsetPos(Vec2(0.f, 0.f));
	// �ǰ� ������ ������ �� �ִ�.
	GetCollider()->SetScale(Vec2(45.f, 70.f));

}

CPlayer::~CPlayer()
{

}

void CPlayer::update()
{
	Vec2 vPos = GetPos();

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
		vPos.x -= LeftRun * fDT;

	}
	// ���������� �̵�
	if (KEY_HOLD(KEY::D) && CanRight)
	{
		vPos.x += (RightRun * fDT);

	}

	if ((m_isJumping == true || !m_onGround))
	{

		m_jumpVelocity += 1000.f * fDT;		///�߷��� ����.
		vPos.y += m_jumpVelocity * fDT;		///��ġ ������Ʈ

	}

	//�����̽��� ������ ����
	if (KEY_HOLD(KEY::SPACE) && !m_isJumping)
	{
		m_jumpVelocity = -510.0f;  /// ������ ���� �ʱ� �ӵ� ����
		m_isJumping = true;
	}
	///�߷��� ũ��� ���� �� ���� �ʱ� ������ ��ġ�� ���� ������ �޶�����.


	SetPos(vPos);
}

void CPlayer::render(HDC _dc)
{
	// unsiged int ���ϴ� ���� �̹����� ������ �ֱ� ������ ����� ����. UINT �� ������ ���� �Ǵ� ���� UINT�� �ִ밪�� ��µȴ�.
	int iWidth = (int)m_pTex->Width();
	int iHeight = (int)m_pTex->Height();

	Vec2 vPos = GetPos();

	TransparentBlt(_dc, int(vPos.x - (float)(iWidth / 2)),
		int(vPos.y - (float)(iHeight / 2)),
		iWidth, iHeight, m_pTex->GetDC(), 0, 0, iWidth, iHeight,
		RGB(255, 0, 255));

	// ������Ʈ (�浹ü, etc
	//ComPonentRender(_dc);
}


void CPlayer::OnCollisionEnter(CCollider* _pOther)		//����� ��
{
	cObject* pOtherObj = _pOther->GetObj();
	Vec2 vPos = GetPos();
	if (pOtherObj->GetName() == L"FLOOR1")
	{
		if (vPos.y < pOtherObj->GetPos().y)
			m_onGround = true;

		m_isJumping = false;	//�����ΰ��� ������� ������x
		m_jumpVelocity = 0;		///�߷��� ����.
		DontInputS = true;		//��ٸ� Ÿ�� �ؿ� ���հ�
	}
	if (pOtherObj->GetName() == L"FLOOR2")
	{
		if (vPos.y < pOtherObj->GetPos().y)
			m_onGround = true;

		m_isJumping = false;	//�����ΰ��� ������� ������x
		m_jumpVelocity = 0;		///�߷��� ����.
	}
	if (pOtherObj->GetName() == L"Wall1")
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
	if (pOtherObj->GetName() == L"Rock1")
	{
		m_onGround = true;
		m_isJumping = false;	//�����ΰ��� ������� ������x
		m_jumpVelocity = 0;		///�߷��� ����.
	}
	if (pOtherObj->GetName() == L"Ladder1")
	{

		CanClimb = true;
	}
}

void CPlayer::OnCollision(CCollider* _pOther)			//������ ��, ����ִ� ��
{
	cObject* pOtherObj = _pOther->GetObj();
	Vec2 vPos = GetPos();
	if (pOtherObj->GetName() == L"FLOOR1")
	{
			m_onGround = true;
			DontInputS = true;		//��ٸ� Ÿ�� �ؿ� ���հ�

	}
	if (pOtherObj->GetName() == L"FLOOR2")
	{
		if (vPos.y+((float)GetCollider()->GetScale().y/2-5) < pOtherObj->GetPos().y- pOtherObj-> GetScale().y/2)
			m_onGround = true;
	}
	if (pOtherObj->GetName() == L"Wall1")
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
	if (pOtherObj->GetName() == L"Rock1")
	{
		m_onGround = true;
		m_isJumping = false;	//�����ΰ��� ������� ������x
		m_jumpVelocity = 0;		///�߷��� ����.
	}
	if (pOtherObj->GetName() == L"Ladder1")
	{
		CanClimb = true;
	}
}

void CPlayer::OnCollisionExit(CCollider* _pOther)		//��Ҵٰ� �������� ��
{
	cObject* pOtherObj = _pOther->GetObj();
	Vec2 vPos = GetPos();
	if (pOtherObj->GetName() == L"FLOOR1"|| pOtherObj->GetName() == L"FLOOR2")
	{
		m_onGround = false;
		DontInputS = false;		//��ٸ� Ÿ�� �ؿ� ���հ�

	}
	if (pOtherObj->GetName() == L"Wall1")
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
	if (pOtherObj->GetName() == L"Rock1")
	{
		m_onGround = false;

	}
	if (pOtherObj->GetName() == L"Ladder1")
	{
		m_onGround = false;
		CanClimb = false;
	}
}