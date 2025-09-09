#include "pch.h"
#include "SeaUr.h"
#include "CTimeManager.h"
#include "CCollider.h"
#include "DoorButton.h"
#include "Shark.h"


Shark::Shark()
    :moveSpeed(100.f)
{
	CreateCollider();
	GetCollider()->SetScale(Vecor2(0.f, 0.f));
	Vecor2 firstShark = Shark::GetPos();
}

Shark::~Shark()
{

}

void Shark::Update()
{
    Vecor2 vPos = GetPos();
    float distance = abs(firstShark.x - vPos.x);

    if (distance >= GetCollider()->GetScale().x)
    {
        moveSpeed *= -1;  // 이동 방향을 반대로 변경합니다.
    }

    vPos.x += moveSpeed * fDT;
    SetPos(vPos);
}

void Shark::OnCollisionEnter(CCollider* _pOther)
{

}

void Shark::OnCollision(CCollider* _pOther)
{

}

void Shark::OnCollisionExit(CCollider* _pOther)
{

}