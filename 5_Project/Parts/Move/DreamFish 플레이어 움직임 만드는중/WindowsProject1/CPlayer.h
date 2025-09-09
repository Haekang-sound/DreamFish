#pragma once
#include "cObject.h"

class CTexture;


class CPlayer :
	public cObject
{

private:
	CTexture* m_pTex;

	/// 중력을 만들어 보자~-------------------
public:
	bool m_isJumping;      // 점프 중인지 여부를 나타내는 플래그
	bool m_onGround;
	bool m_isTouching;
	bool CanRight;
	bool CanLeft;
	bool m_IsClimbing;
	bool CanClimb;
	bool DontInputS;

	float m_jumpVelocity;  // 유사중력


	///-------------------------------------
public:
	virtual void update();
	virtual void render(HDC _dc);
	CCollider* GetCollider() { return m_pCollider; }

	//플레이어의 가속/감속을 추가해야 한다.
	//중력이랑 비슷하게 대신 마찰력을 이동방향의 반대로 넣자.
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

