#pragma once

class CObject;

class CCollider
{
public:
	static UINT g_iNextID;

	CObject* m_pOwner;  // collider를 가지고 있는 오브젝트
	Vecor2 m_vOffsetPos;  // 오브젝트로 부터 상대적인 위치
	Vecor2 m_vFinalPos;   // finalupdate 에서 매 프레임 계산
	Vecor2 m_vScale;		//충돌체의 크기
	
	UINT m_iID;			// 충돌체 고유한 ID 값
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
	// 충돌 시점 함수
	void OnCollision(CCollider* _pOther); // 충돌 중인 경우 호출되는 함수
	void OnCollisionEnter(CCollider* _pOther);	// 충돌 진입 시
	void OnCollisionExit(CCollider* _pOther);   // 충돌 해제 시


	// 복사를 했을 때 a = b가 되는데 이러한 현상을 없애기 위해 대입을 없앤다.
	CCollider& operator = (CCollider& _orgin) = delete;

public:
	CCollider();
	// 복사 생성자
	CCollider(const CCollider& _origin);
	~CCollider();

	friend class CObject;
};