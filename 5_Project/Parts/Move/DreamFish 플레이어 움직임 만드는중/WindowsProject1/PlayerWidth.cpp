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

	// 피격 범위의 위치를 조절 할 수 있다.
	GetCollider()->SetOffsetPos(Vec2(0.f, 0.f));
	// 피격 범위를 조절할 수 있다.
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


	// 컴포넌트 (충돌체, etc
	ComPonentRender(_dc);
}

void PlayerWidth::OnCollisionEnter(CCollider* _pOther)		//닿았을 때
{ 
}

void PlayerWidth::OnCollision(CCollider* _pOther)			//겹쳤을 때
{
}

void PlayerWidth::OnCollisionExit(CCollider* _pOther)		//닿았다가 떨어졌을 때
{
}
