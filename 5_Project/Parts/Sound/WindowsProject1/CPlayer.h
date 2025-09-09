#pragma once
#include "CObject.h"

class CTexture;


class CPlayer :
    public CObject
{

private:
	CTexture* m_pTex;

	/// �߷��� ����� ����~-------------------
public:
	bool m_isJumping;      // ���� ������ ���θ� ��Ÿ���� �÷���
	bool m_onGround;
	bool m_isTouching;
	bool CanRight;
	bool CanLeft;
	bool m_IsClimbing;
	bool CanClimb;
	bool DontInputS;

	float m_jumpVelocity;  // �����߷�


	///-------------------------------------
public:
	virtual void Update();
	virtual void Render(HDC _dc);
	CCollider* GetCollider() { return m_pCollider; }

	//�÷��̾��� ����/������ �߰��ؾ� �Ѵ�.
	//�߷��̶� ����ϰ� ��� �������� �̵������� �ݴ�� ����.
public:
	float RightRun;
	float LeftRun;

private:
	virtual void OnCollisionEnter(CCollider* _pOther);
	virtual void OnCollision(CCollider* _pOther);
	virtual void OnCollisionExit(CCollider* _pOther);
	CLONE(CPlayer);
public:
	CPlayer();
	~CPlayer();
};

