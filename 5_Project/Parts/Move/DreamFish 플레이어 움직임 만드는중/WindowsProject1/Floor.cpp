#include "pch.h"
#include "Floor.h"

#include "CCollider.h"

Floor::Floor()
{
	
	CreateCollider();
	// 발판 충돌 사이즈 값
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
	// 충돌이 된다.
	cObject* pOtherObj = _pOther->GetObj();
}