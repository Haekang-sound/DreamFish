#include "pch.h"
#include "CWall.h"
#include "CTimeManager.h"
#include "CCollider.h"

CWall::CWall()
{
	CreateCollider();
	// ���� �浹 ������ ��
	GetCollider()->SetScale(Vecor2(50.f, 200.f));
}

CWall::~CWall()
{
}

void CWall::Update()
{
}

void CWall::OnCollisionEnter(CCollider* _pOther)
{
}

void CWall::OnCollision(CCollider* _pOther)
{
}


void CWall::OnCollisionExit(CCollider* _pOther)
{
}

