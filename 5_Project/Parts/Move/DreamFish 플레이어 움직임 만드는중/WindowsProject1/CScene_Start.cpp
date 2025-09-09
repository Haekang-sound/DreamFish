#include "pch.h"
#include "CScene_Start.h"

#include "cObject.h"

#include "CPlayer.h"
#include "PlayerWidth.h"

#include "Rock.h"
#include "Floor.h"
#include "Ladder.h"
#include "Wall.h"
#include "Rock.h"

#include "CCore.h"
#include "CPathMgr.h"
#include "CTexture.h"
#include "CCollider.h"
#include "CCollisionMgr.h"
#include "CKeyMgr.h"
#include "CSceneMgr.h"

CScene_Start::CScene_Start()
{

}

CScene_Start::~CScene_Start()
{

}

void CScene_Start::update()
{
	CScene::update();

	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::TOOL);
	}
}

void CScene_Start::Enter()
{
	//벽배치
	Ladder* Ladder1 = nullptr;
	Ladder1 = new Ladder;
	Ladder1->SetName(L"Ladder1");
	Ladder1->SetPos(Vec2(500.f, 450.f));	 // 사다리의 포지션
	Ladder1->SetScale(Vec2(50.f, 400.f));	 // 스케일크기
	Ladder1->GetCollider()->SetScale(Vec2(50.f, 400.f));	//발판 충돌 사이즈 값
	AddObject(Ladder1, GROUP_TYPE::LADDER);

	//PLAYER 추가
	CPlayer* pObj = new CPlayer;
	pObj->SetName(L"PLAYER");
	pObj->SetPos(Vec2(640.f, 384.f));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);

	//CPlayer*
	if (!pObj->IsDead()) {
		PlayerWidth* pWidth = new PlayerWidth;
		pWidth->SetName(L"PLAYERWidth");
		pWidth->SetPos(Vec2(640.f, 384.f));
		pWidth->SetScale(Vec2(100.f, 100.f));
		pWidth->SetPlayer(pObj);
		AddObject(pWidth, GROUP_TYPE::PLAYER);
	}

	// 바위 배치
	Rock* Rock1 = nullptr;
	Rock1 = new Rock;
	Rock1->SetName(L"Rock1");
	Rock1->SetPos(Vec2(300.f, 550.f)); // 변수화 17. 52:22
	Rock1->SetScale(Vec2(50.f, 50.f));
	AddObject(Rock1, GROUP_TYPE::ROCK);


	//바닥을 구현
	Floor* Floor1 = nullptr;
	Floor1 = new Floor;
	Floor1->SetName(L"FLOOR1");
	Floor1->SetPos(Vec2(500.f, 600.f)); // 변수화 17. 52:22
	Floor1->SetScale(Vec2(1200.f, 50.f));
	AddObject(Floor1, GROUP_TYPE::FLOOR);

	//2층 바닥을 구현
	Floor* Floor2 = nullptr;
	Floor2 = new Floor;
	Floor2->SetName(L"FLOOR2");
	Floor2->SetPos(Vec2(500.f, 300.f)); // 변수화 17. 52:22
	Floor2->SetScale(Vec2(1200.f, 50.f));
	AddObject(Floor2, GROUP_TYPE::FLOOR);

	//벽배치
	Wall* Wall1 = nullptr;
	Wall1 = new Wall;
	Wall1->SetName(L"Wall1");
	Wall1->SetPos(Vec2(1000.f, 475.f));	 // 벽의 포지션
	Wall1->SetScale(Vec2(50.f, 200.f));	 // 스케일크기
	AddObject(Wall1, GROUP_TYPE::WALL);


	// 충돌 지정
	// 플레이어와 발판 그룹 간의 충돌 체크
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::ROCK);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::FLOOR);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::LADDER);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::WALL);


}

void CScene_Start::Exit()
{
	DeleteAll();

	// 충돌 체크 한 것을 해제한다.
	CCollisionMgr::GetInst()->Reset();
}