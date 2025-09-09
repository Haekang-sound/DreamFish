#pragma once
#include "cObject.h"

class CTexture;

class CBattery :
    public CObject
{
private:
	virtual void OnCollisionEnter(CCollider* _pOther);
	virtual void OnCollision(CCollider* _pOther);
	virtual void OnCollisionExit(CCollider* _pOther);
	/// <summary>
	/// ������_������ �Լ��� ���Ͽ�
	/// �ʱⰪ ���� cpp���� ������ �ʱⰪ�� �������ش�
	static bool isHave;									/// ȹ�� �ϸ� ���͸��� Ȱ��ȭ �ɼ� �ֵ��� �ϱ�.
public:
	virtual void Update();
	virtual void Render(HDC _dc);
	static bool& GetisHave() { return isHave; }		///*** �÷��̾ �������� ������ ������ �ӽ��� �ߵ��ϱ� ���� �����ڸ� ��ȯ�ϴ� ������ �Լ� �߰� >>>shark.h�� ������
public:
	
	CBattery();
	~CBattery();
};

