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
	GetCollider()->SetOffsetPos(Vecor2(0.f, 0.f));
	// �ǰ� ������ ������ �� �ִ�.
	GetCollider()->SetScale(Vecor2(45.f, 65.f));

}

PlayerWidth::~PlayerWidth()
{

}
void PlayerWidth::Update()
{
	Vecor2 vPos = player->GetPos();
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
}

void PlayerWidth::OnCollisionExit(CCollider* _pOther)		//��Ҵٰ� �������� ��
{
}
