#include "pch.h"
#include "SeaUr.h"
#include "CTimeManager.h"
#include "CCollider.h"
#include "DoorButton.h"


SeaUr::SeaUr()
{
	CreateCollider();
	GetCollider()->SetScale(Vecor2(50.f, 200.f));
}

SeaUr::~SeaUr()
{

}

void SeaUr::Update()
{

}

void SeaUr::OnCollisionEnter(CCollider* _pOther)
{

}

void SeaUr::OnCollision(CCollider* _pOther)
{

}

void SeaUr::OnCollisionExit(CCollider* _pOther)
{

}

