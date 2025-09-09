#include "pch.h"
#include "CMachine.h"

#include "CCollider.h"
#include "CBattery.h"

CMachine::CMachine()
{
	CreateCollider();
	GetCollider()->SetScale(Vecor2(50.f, 200.f));
}

CMachine::~CMachine()
{

}

void CMachine::OnCollisionEnter(CCollider* _pOther)
{

}

void CMachine::OnCollision(CCollider* _pOther)
{

}

void CMachine::OnCollisionExit(CCollider* _pOther)
{

}

void CMachine::Update()
{

}

