#pragma once
#include "CCamera.h"

class CCollider;

class cObject
{
private:
	Vec2 m_vPos;
	Vec2 m_vScale;
	Vec2 p_vPos;	//과거 x, y값을 받고싶었음

	CCollider* m_pCollider;


public:
	void SetPos(Vec2 _vPos);
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }
	void PastSetPos(Vec2 _vpos);


	Vec2 GetPos() { return m_vPos; }
	Vec2 GetScale() { return m_vScale; }

	CCollider* GetCollider() { return m_pCollider; }

	void CreateCollider();

	virtual void OnCollision(CCollider* _pOther) {}
	virtual void OnCollisionEnter(CCollider* _pOther) {}
	virtual void OnCollisionExit(CCollider* _pOther) {}

public:
	virtual void update() = 0;
	virtual void finalupdate() final; // 여기까지가 마지막이란 뜻 더 이상 할수 없음
	virtual void render(HDC _dc);

	void ComPonentRender(HDC _dc);

public:
	cObject();
	virtual ~cObject();
};

