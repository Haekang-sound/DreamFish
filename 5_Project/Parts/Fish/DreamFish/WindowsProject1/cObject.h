#pragma once
#include "CCamera.h"

class CCollider;

class cObject
{
private:
	Vec2 m_vPos;
	Vec2 m_vScale;
	Vec2 renderPos;
	CCollider* m_pCollider;


public:
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }
	
	Vec2 GetPos() { return m_vPos; }
	Vec2 GetScale() { return m_vScale; }

	void SetRenderPos(Vec2 _renderpos) { renderPos = _renderpos; }
	Vec2 GetRender() {
		return renderPos;
	}
	CCollider* GetCollider() { return m_pCollider; }

	void CreateCollider();

	void CreateFishCollider();

public:
	virtual void update() = 0;
	virtual void finalupdate() final; // 여기까지가 마지막이란 뜻 더 이상 할수 없음
	virtual void render(HDC _dc);

	void ComPonentRender(HDC _dc);

public:
	cObject();
	virtual ~cObject();
};

