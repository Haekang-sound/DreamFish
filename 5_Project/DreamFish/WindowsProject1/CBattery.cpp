#include "pch.h"
#include "CBattery.h"
#include "CTimeManager.h"
#include "CCollider.h"
#include "CAnimator.h"

bool CBattery::isHave = false; /// �ʱⰪ ����!
void CBattery::Update()
{

}

void CBattery::Render(HDC _dc)
{


	Vecor2 vPos = CCamera::GetInstance()->GetRenderPos(GetPos());
	SetRenderPos(vPos);

	// �ִϸ��̼����ڸ� ä��� ���� �����
	CAnimator* pAni = new CAnimator;

	pAni->m_frameCount = 0;
	pAni->frameCount = 0;


	// �ִϸ��̼����ڸ� ä��� ���� �����
	Vecor2 vScale = { 1.f, 1.f };


	// �ִϸ��̼� ����
	
	pAni->MakeMap(_dc, vPos, vScale, 0, GROUP_TYPE::BATTERAY);

	// ������Ʈ (�浹ü, etc

	delete pAni;
}

CBattery::CBattery()
{
	CreateCollider();
	// ���� �浹 ������ ��
	GetCollider()->SetScale(Vecor2(100.f, 100.f));
	isHave = false;
}

CBattery::~CBattery()
{

}

void CBattery::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	if(pOtherObj->GetPos().x!=0.f)
	{
		if (pOtherObj->GetName() == L"PLAYER")
		{
			isHave = true; /// ���͸� ��������
		}
	}
}

void CBattery::OnCollision(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"PLAYER")
	{
		isHave = true; /// ���͸� ��������
	}
}

void CBattery::OnCollisionExit(CCollider* _pOther)
{

}
