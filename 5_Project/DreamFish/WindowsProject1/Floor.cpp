#include "pch.h"
#include "Floor.h"

#include "CCollider.h"

#include "CAnimator.h"


Floor::Floor()
{

	CreateCollider();
	// ���� �浹 ������ ��
	GetCollider()->SetScale(Vecor2(1200.f, 50.f));
}

Floor::~Floor()
{

}

void Floor::Update()
{

}

void Floor::Render(HDC _dc)
{
	Vecor2 vPos = CCamera::GetInstance()->GetRenderPos(GetPos());
	SetRenderPos(vPos);

	// �ִϸ��̼����ڸ� ä��� ���� �����
	Vecor2 vScale = { 1.f, 1.f };
	CAnimator* pAni = new CAnimator;


	// �ִϸ��̼� ����
	pAni->MakeMap(_dc, vPos, vScale, 0, GROUP_TYPE::FLOOR);

	// ������Ʈ (�浹ü, etc

	delete pAni;

}

void Floor::OnCollision(CCollider* _pOther)
{
	// �浹�� �ȴ�.
	CObject* pOtherObj = _pOther->GetObj();
}