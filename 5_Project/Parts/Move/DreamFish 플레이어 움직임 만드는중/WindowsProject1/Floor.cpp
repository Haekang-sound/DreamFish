#include "pch.h"
#include "Floor.h"

#include "CCollider.h"

Floor::Floor()
{
	
	CreateCollider();
	// ���� �浹 ������ ��
	GetCollider()->SetScale(Vec2(1200.f, 50.f));
}

Floor::~Floor()
{

}

void Floor::update()
{

}

void Floor::OnCollision(CCollider* _pOther)
{
	// �浹�� �ȴ�.
	cObject* pOtherObj = _pOther->GetObj();
}