#pragma once

class cObject;

class CCollider
{
private:
	static UINT g_iNextID;

	cObject* m_pOwner;  // collider�� ������ �ִ� ������Ʈ
	Vec2 m_vOffsetPos;  // ������Ʈ�� ���� ������� ��ġ
	Vec2 m_vFinalPos;   // finalupdate ���� �� ������ ���
	Vec2 m_vScale;		//�浹ü�� ũ��
	
	UINT m_iID;			// �浹ü ������ ID ��
	UINT m_iCol;


public:
	void SetOffsetPos(Vec2 _vPos) { m_vOffsetPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	Vec2 GetOffsetPos() { return m_vOffsetPos; }
	Vec2 GetScale() { return m_vScale; }

	Vec2 GetFinalPos() { return m_vFinalPos; }
	
	cObject* GetObj() { return m_pOwner; }

	UINT GetID() { return m_iID; }

public:
	void finalupdate();
	void render(HDC _dc);

public:
	// �浹 ���� �Լ�
	void OnCollision(CCollider* _pOther); // �浹 ���� ��� ȣ��Ǵ� �Լ�
	void OnCollisionEnter(CCollider* _pOther);	// �浹 ���� ��
	void OnCollisionExit(CCollider* _pOther);   // �浹 ���� ��


	// ���縦 ���� �� a = b�� �Ǵµ� �̷��� ������ ���ֱ� ���� ������ ���ش�.
	CCollider& operator = (CCollider& _orgin) = delete;

public:
	CCollider();
	// ���� ������
	CCollider(const CCollider& _origin);
	~CCollider();

	friend class cObject;
};