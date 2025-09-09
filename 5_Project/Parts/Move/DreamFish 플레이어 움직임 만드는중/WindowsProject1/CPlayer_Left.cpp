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

	// �ǰ� ������ ��ġ�� ���� �� �� �ִ�.
	GetCollider()->SetOffsetPos(Vec2(0.f, 0.f));
	// �ǰ� ������ ������ �� �ִ�.
	GetCollider()->SetScale(Vec2(50.f, 65.f));

}

CPlayer_Left::~CPlayer_Left()
{

}

void CPlayer_Left::update()
{
	Vec2 vPos = cObject::GetPos();
	int plzPlayer = m_pCollider->GetiCol();


	// ���� �̵� ���ӿ����� ������ ����
	if (KEY_HOLD(KEY::W))
	{
		vPos.y -= 2000.f * fDT;
	}
	// �������� �̵�
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
	// ���������� �̵�
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
		m_isJumping = false;	//�����ΰ��� ������� ������x
		m_jumpVelocity = 0;		///�߷��� ����.
	}
	else
	{
		m_isJumping = true;		//���� �ʾ����� ���� ��
		m_jumpVelocity += 400.f * fDT;		///�߷��� ����.
		vPos.y += m_jumpVelocity * fDT;
	}

	//�����̽��� ������ ����
	if (KEY_HOLD(KEY::SPACE) && !m_isJumping)
	{
		m_isJumping = true;
		m_jumpVelocity = -210.0f;  /// ������ ���� �ʱ� �ӵ� ����
	}
	///�߷��� ũ��� ���� �� ���� �ʱ� ������ ��ġ�� ���� ������ �޶�����.
	if (m_isJumping)
	{
		// ��ġ ������Ʈ
		vPos.y += m_jumpVelocity * fDT;

	}

	cObject::SetPos(vPos);
}

void CPlayer_Left::render(HDC _dc)
{
	Vec2 vPos = cObject::GetPos();


	// ������Ʈ (�浹ü, etc
	ComPonentRender(_dc);
}

