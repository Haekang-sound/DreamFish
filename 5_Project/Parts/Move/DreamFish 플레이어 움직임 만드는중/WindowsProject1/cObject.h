#pragma once

class CCollider;

class cObject
{
private:
	wstring m_strName;

	Vec2 m_vPos;
	Vec2 m_vScale;


	bool m_bAlive;
public:
	bool IsTouch;
	void SetPos(Vec2 _vPos);
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }
	void PastSetPos(Vec2 _vpos);

public:
	Vec2 p_vPos;	//���� x, y���� �ް�;���
	Vec2 GetPos() { return m_vPos; }
	Vec2 GetScale() { return m_vScale; }

	CCollider* m_pCollider;
	CCollider* GetCollider() { return m_pCollider; }

	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }



	bool IsDead() { return !m_bAlive;}

	void CreateCollider();

	virtual void OnCollision(CCollider* _pOther) {}
	virtual void OnCollisionEnter(CCollider* _pOther) {}
	virtual void OnCollisionExit(CCollider* _pOther) {}

private:
	bool SetDead() { return m_bAlive = false; }

public:
	virtual void update() = 0;
	virtual void finalupdate() final; // ��������� �������̶� �� �� �̻� �Ҽ� ����
	virtual void render(HDC _dc);

	void ComPonentRender(HDC _dc);

public:
	cObject();
	virtual ~cObject();
	
	friend class CEventMgr;
};

