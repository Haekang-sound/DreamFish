#pragma once

class CObject;

class CCollider
{
public:
	static UINT g_iNextID;

	CObject* m_pOwner;  // collider�� ������ �ִ� ������Ʈ
	Vecor2 m_vOffsetPos;  // ������Ʈ�� ���� ������� ��ġ
	Vecor2 m_vFinalPos;   // finalupdate ���� �� ������ ���
	Vecor2 m_vScale;		//�浹ü�� ũ��
	
	UINT m_iID;			// �浹ü ������ ID ��
	int m_iCol;


public:
	void SetOffsetPos(Vecor2 _vPos) { m_vOffsetPos = _vPos; }
	void SetScale(Vecor2 _vScale) { m_vScale = _vScale; }
	void SetOwner(CObject* _object) { m_pOwner = _object; }

	Vecor2 GetOffsetPos() { return m_vOffsetPos; }
	Vecor2 GetScale() { return m_vScale; }

	Vecor2 GetFinalPos() { return m_vFinalPos; }

	int GetiCol() { return m_iCol; }

	CObject* GetObj() { return m_pOwner; }

	UINT GetID() { return m_iID; }
	UINT GetCol() { return m_iCol; }

public:
	virtual void FinalUpdate();
	virtual void Render(HDC _dc);

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

	friend class CObject;
};