#pragma once
#include "CObject.h"



class DoorButton :
    public CObject
{

private:
	virtual void OnCollisionEnter(CCollider* _pOther);
	virtual void OnCollision(CCollider* _pOther);
	virtual void OnCollisionExit(CCollider* _pOther);
	/// <summary>
	/// ������_������ �Լ��� ���Ͽ�
	/// �ʱⰪ ���� cpp���� ������ �ʱⰪ�� �������ش�
	static bool isOpen;									///��ư�� ������ ���� �����Բ� �ϱ�����
public:
	virtual void Update();
	virtual void Render(HDC _dc);
	static bool& GetisOpen() { return isOpen; }			///***��ư�� ������ ���� �����Բ� �ϱ����� �����ڸ� ��ȯ�ϴ� ������ �Լ� �߰� >>>Door.h�� ������
public:
	DoorButton();
	~DoorButton();
};

