#include "pch.h"
#include "PlayerWidth.h"

#include "CCollider.h"
#include "CKeyMgr.h"
#include "cTimeMgr.h"

#include "CScene.h"
#include "CSceneMgr.h"
#include "CResMgr.h"
#include "CTexture.h"

PlayerWidth::PlayerWidth()
	
{
	CreateCollider();

	// �ǰ� ������ ��ġ�� ���� �� �� �ִ�.
	GetCollider()->SetOffsetPos(Vec2(0.f, 0.f));
	// �ǰ� ������ ������ �� �ִ�.
	GetCollider()->SetScale(Vec2(45.f, 65.f));

}

PlayerWidth::~PlayerWidth()
{

}
void PlayerWidth::update()
{
	Vec2 vPos = player->GetPos();
	SetPos(vPos);

}

void PlayerWidth::render(HDC _dc)
{
	Vec2 vPos = cObject::GetPos();


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
