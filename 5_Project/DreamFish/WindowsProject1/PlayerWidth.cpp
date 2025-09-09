#include "pch.h"
#include "PlayerWidth.h"

#include "CCollider.h"
#include "CKeyManager.h"
#include "CTimeManager.h"

#include "CScene.h"
#include "CSceneManager.h"
#include "CResManager.h"
#include "CTexture.h"


/// <summary>
/// 
/// �÷��̾�� �ݶ��̴��� �ι� ������ ����, �¿� �浹 üũ�� ������ ����.
/// 
/// </summary>
PlayerWidth::PlayerWidth()

{
	CreateCollider();

	// �ǰ� ������ ��ġ�� ���� �� �� �ִ�.
	GetCollider()->SetOffsetPos(Vecor2(0.f, 40.f));
	// �ǰ� ������ ������ �� �ִ�.
	GetCollider()->SetScale(Vecor2(35.f, 30.f));

}

PlayerWidth::~PlayerWidth()
{

}
void PlayerWidth::Update()
{
	Vecor2 vPos = player->GetPos();
	m_onGround = player->IsGround();
	SetPos(vPos);

}

void PlayerWidth::Render(HDC _dc)
{
	Vecor2 vPos = CObject::GetPos();


	// ������Ʈ (�浹ü, etc
	ComPonentRender(_dc);
}

void PlayerWidth::OnCollisionEnter(CCollider* _pOther)		//����� ��
{
}

void PlayerWidth::OnCollision(CCollider* _pOther)			//������ ��
{
	CObject* pOtherObj = _pOther->GetObj();
	Vecor2 vPos = GetPos();
	if (pOtherObj->GetName() == L"Wall")
	{
		player->m_isTouching = true;
		if (vPos.x < pOtherObj->GetPos().x)
		{
			player->CanRight = false;
		}
		if (vPos.x > pOtherObj->GetPos().x)
		{
			player->CanLeft = false;
		}
	}
	if (pOtherObj->GetName() == L"Rock" && m_onGround)
	{
		player->m_isTouching = true;
		if (vPos.x < pOtherObj->GetPos().x)
		{
			player->CanRight = false;
		}
		if (vPos.x > pOtherObj->GetPos().x)
		{
			player->CanLeft = false;
		}
	}
}

void PlayerWidth::OnCollisionExit(CCollider* _pOther)		//��Ҵٰ� �������� ��
{
	CObject* pOtherObj = _pOther->GetObj();
	Vecor2 vPos = GetPos();
	if (pOtherObj->GetName() == L"Rock")
	{
		player->m_isTouching = false;
		player->CanRight = true;
		player->CanLeft = true;
	}
	if (pOtherObj->GetName() == L"Wall")
	{
		player->m_isTouching = false;
		player->CanRight = true;
		player->CanLeft = true;
	}
	
}