#include "pch.h"
#include "CFoothold.h"

#include "OtherCollider.h"

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