#include "pch.h"
#include "FakeWallLeftRight.h"
#include "CTimeManager.h"
#include "CCollider.h"


FakeWallLeftRight::FakeWallLeftRight()
{
	CreateCollider();
	// ���� �浹 ������ ��
	GetCollider()->SetScale(Vecor2(50.f, 200.f));
}

FakeWallLeftRight::~FakeWallLeftRight()
{
}

void FakeWallLeftRight::Update()
{
}

void FakeWallLeftRight::OnCollisionEnter(CCollider* _pOther)
{
}

void FakeWallLeftRight::OnCollision(CCollider* _pOther)
{
}


void FakeWallLeftRight::OnCollisionExit(CCollider* _pOther)
{
}

///
///
/// FakeWallLeftRight Ŭ������ FakeWallUpDown Ŭ������ ���� �ΰ��� ���� �ʿ䰡 ������!! ������ �̰� �ٸ� �̸��� WALL�̴�!!!!!!!
/// ������ �̹� �������� ���� ���� �ð��� ���⿡ ����ΰ� ���߿� ������ �Ѵ�.!!!!!!!!!!!!!
/// 
/// 
/// 