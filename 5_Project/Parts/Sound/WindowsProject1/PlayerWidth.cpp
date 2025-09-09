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
/// 플레이어에게 콜라이더를 두번 씌워서 상하, 좌우 충돌 체크를 나눌수 있음.
/// 
/// </summary>
PlayerWidth::PlayerWidth()

{
	CreateCollider();

	// 피격 범위의 위치를 조절 할 수 있다.
	GetCollider()->SetOffsetPos(Vecor2(0.f, 0.f));
	// 피격 범위를 조절할 수 있다.
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
