#include "pch.h"
#include "CFoothold.h"

#include "CCollider.h"

CFoothold::CFoothold()
{
	CreateCollider();
	// ���� ������ ��
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
	// �浹�� �ȴ�.
	cObject* pOtherObj = _pOther->GetObj();
	
	// if (pOtherObj->GetName() == L"Player")
	// {
	// 
	// }
}