#pragma once
#include "CPlayer.h"
class PlayerWidth :
	public CPlayer
{
private:
	CPlayer* player;

private:
	virtual void OnCollisionEnter(CCollider* _pOther);
	virtual void OnCollision(CCollider* _pOther);
	virtual void OnCollisionExit(CCollider* _pOther);
public:
	PlayerWidth();
	~PlayerWidth();

	virtual void update();
	virtual void render(HDC _dc);
	CCollider* GetCollider() { return m_pCollider; }

	void SetPlayer(CPlayer* _player) { player = _player; }
};


