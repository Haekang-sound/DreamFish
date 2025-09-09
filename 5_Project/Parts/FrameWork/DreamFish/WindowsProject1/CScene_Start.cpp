#include "pch.h"
#include "CScene_Start.h"

#include "cObject.h"

#include "CPlayer.h"
#include "CFoothold.h"
#include "CFish.h"

#include "CCore.h"
#include "CPathMgr.h"
#include "CTexture.h"

#include "CCollisionMgr.h"

CScene_Start::CScene_Start()
{

}

CScene_Start::~CScene_Start()
{

}

void CScene_Start::Enter()
{
	// Object 추가
	cObject* pObj = new CPlayer;	
	pObj->SetPos(Vec2(640.f, 384.f));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);

	cObject* fish = new CFish;
	fish->SetPos(Vec2(0.f, 384.f));
	fish->SetScale(Vec2(100.f, 100.f));
	AddObject(fish, GROUP_TYPE::DEFALUT);

	// 발판 배치
	CFoothold* pFoothold = nullptr; 
	for (int i = 0; i < 5; ++i)
	{
		// 발판 ( Foothold ) 추가
		pFoothold = new CFoothold;
		pFoothold->SetPos(Vec2(50.f + (float)i*500, 50.f)); // 변수화 17. 52:22
		pFoothold->SetScale(Vec2(200.f, 50.f));
		AddObject(pFoothold, GROUP_TYPE::FOOTHOLD);
	}
	Vec2 vResolution = CCore::GetInst()->GetResolution();
	CCamera::GetInst()->SetLookAt(vResolution / 2.f);
	CCamera::GetInst()->SetTarget(pObj);
	// 충돌 지정
	// 플레이어와 발판 그룹 간의 충돌 체크
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::FOOTHOLD);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::DEFALUT, GROUP_TYPE::FOOTHOLD);

}

void CScene_Start::Exit()
{
	// 충돌 체크 한 것을 해제한다.
	CCollisionMgr::GetInst()->Reset();
}