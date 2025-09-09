#include "pch.h"
#include "FakeWallLeftRight.h"
#include "CTimeManager.h"
#include "CCollider.h"


FakeWallLeftRight::FakeWallLeftRight()
{
	CreateCollider();
	// 발판 충돌 사이즈 값
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
/// FakeWallLeftRight 클래스와 FakeWallUpDown 클래스는 굳이 두개로 나눌 필요가 없었다!! 심지언 이건 다른 이름의 WALL이다!!!!!!!
/// 하지만 이미 만들어놨고 지금 남은 시간이 없기에 적어두고 나중에 보고자 한다.!!!!!!!!!!!!!
/// 
/// 
/// 