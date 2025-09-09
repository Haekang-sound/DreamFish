#pragma once
#include "CCamera.h"

class CCollider;

class CObject
{
private:
	wstring m_strName;

	Vecor2 m_vPos;
	Vecor2 m_vScale;
	Vecor2 renderPos;
	bool m_bAlive;
	

public:
	bool m_onGround;
	bool IsTouch;

	void SetPos(Vecor2 _vPos);
	void SetScale(Vecor2 _vScale) { m_vScale = _vScale; }
	void PastSetPos(Vecor2 _vpos);

	Vecor2 p_vPos;	//���� x, y���� �ް�;���
	Vecor2 GetPos() { return m_vPos; }
	Vecor2 GetScale() { return m_vScale; }

	CCollider* m_pCollider;
	CCollider* GetCollider() { return m_pCollider; }

	/// <summary>
	/// �����簡 �߰���. �̸��޾Ƽ� �浹üũ�ؾ��ؼ�...
	/// </summary>
	/// <param name="_strName"></param>
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }
	bool IsDead() { return !m_bAlive; }
	bool IsGround() { return m_onGround; }

	void SetRenderPos(Vecor2 _renderpos) { renderPos = _renderpos; }
	Vecor2 GetRender() {
		return renderPos;
	}
	void CreateCollider();
	void CreateFishCollider();

	virtual void OnCollision(CCollider* _pOther) {}
	virtual void OnCollisionEnter(CCollider* _pOther) {}
	virtual void OnCollisionExit(CCollider* _pOther) {}

private:
	bool SetDead() { return m_bAlive = false; }
public:
	virtual void Update() = 0;
	virtual void FinalUpdate() final; // ��������� �������̶� �� �� �̻� �Ҽ� ����
	virtual void Render(HDC _dc);

	void ComPonentRender(HDC _dc);

	void ComPonentFishRender(HDC _dc);

public:
	CObject();
	virtual ~CObject();

	friend class CEventManager;
};

