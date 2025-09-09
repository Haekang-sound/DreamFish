#include "pch.h"
#include "CFoothold.h"

#include "CCollider.h"

CFoothold::CFoothold()
{
	CreateCollider();
	// 발판 사이즈 값
	GetCollider()->SetScale(Vec2(200.f, 50.f));
}

CFoothold::~CFoothold()
{

}

void CFoothold::update()
{

} 

void CFoothold::OnCollision(CCollider* _pOther)
{
	// 충돌이 된다.
	cObject* pOtherObj = _pOther->GetObj();
	
	// if (pOtherObj->GetName() == L"Player")
	// {
	// 
	// }
}