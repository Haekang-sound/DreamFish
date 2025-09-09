#include "pch.h"
#include "Wall.h"
#include "cTimeMgr.h"
#include "CCollider.h"

Wall::Wall()
{
	CreateCollider();
	// 발판 충돌 사이즈 값
	GetCollider()->SetScale(Vec2(50.f, 200.f));
}

Wall::~Wall()
{
}

void Wall::update()
{
}

void Wall::OnCollisionEnter(CCollider* _pOther)
{
}

void Wall::OnCollision(CCollider* _pOther)
{
}


void Wall::OnCollisionExit(CCollider* _pOther)
{
}

