#include "pch.h"
#include "Floor.h"

#include "CCollider.h"

Floor::Floor()
{

	CreateCollider();
	// ���� �浹 ������ ��
	GetCollider()->SetScale(Vecor2(1200.f, 50.f));
}

Floor::~Floor()
{

}

void Floor::Update()
{

}

void Floor::OnCollision(CCollider* _pOther)
{
	// �浹�� �ȴ�.
	CObject* pOtherObj = _pOther->GetObj();
}