#include "pch.h"
#include "FakeWallUpDown.h"
#include "CTimeManager.h"
#include "CCollider.h"


FakeWallUpDown::FakeWallUpDown()
{
	CreateCollider();
	// ���� �浹 ������ ��
	GetCollider()->SetScale(Vecor2(50.f, 200.f));
}

FakeWallUpDown::~FakeWallUpDown()
{
}

void FakeWallUpDown::Update()
{
}

void FakeWallUpDown::OnCollisionEnter(CCollider* _pOther)
{
}

void FakeWallUpDown::OnCollision(CCollider* _pOther)
{
}


void FakeWallUpDown::OnCollisionExit(CCollider* _pOther)
{
}

