#include "pch.h"
#include "CFoothold.h"

#include "OtherCollider.h"

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