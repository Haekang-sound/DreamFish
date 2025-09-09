#include "pch.h"
#include "Stage3.h"

#include "CObject.h"

#include "CBackGround.h"
#include "CPlayer.h"
#include "PlayerWidth.h"

#include "CRock.h"
#include "Floor.h"
#include "CLadder.h"
#include "CWall.h"
#include "CRock.h"
#include "CFish.h"
#include "Door.h"
#include "DoorButton.h"
#include "FishDoor.h"
#include "FishButton.h"
#include "Shark.h"
#include "SeaUr.h"		//성게임

#include "FakeWallLeftRight.h"
#include "FakeWallUpDown.h"

#include "GoToNextScene.h"

#include "CKeyManager.h"
#include "CGameProcess.h"
#include "CPathManager.h"
#include "CTexture.h"
#include "CCollider.h"

#include "CCollisionManager.h"
#include "CSceneManager.h"
#include "CCamera.h"
#include "CTimeManager.h"

#include "CButtonQuit.h"
#include "CButtonStart.h"
#include "CButtonTitle.h"


Stage3::Stage3()
{

}

Stage3::~Stage3()
{

}

void Stage3::Update()
{
	CScene::Update();

	if (KEY_TAP(KEY::ENTER))
	{
		CSceneManager::GetInstance()->ChangeScene(SCENE_TYPE::STAGE_03);
	}
	if (KEY_AWAY(KEY::ESC))
	{
		pause = !pause; // 일시정지 상태를 토글
	}

	if (pause)
	{
		// 게임 종료 Object 추가
		CButtonQuit* quit = nullptr;
		quit = new CButtonQuit;
		quit->SetPos(Vecor2(300.f, 200.f));
		quit->SetScale(Vecor2(200.f, 50.f));
		AddObject(quit, GROUP_TYPE::GAMEQUIT);



		// 타이틀 화면 Object 추가
		CButtonTitle* title = nullptr;
		title = new CButtonTitle;
		title->SetPos(Vecor2(200.f, 100.f));
		title->SetScale(Vecor2(200.f, 50.f));
		AddObject(title, GROUP_TYPE::GAMETITLE);
	}
	else if (!pause)
	{
		// 게임 종료 버튼 삭제
		DeleteGroup(GROUP_TYPE::GAMEQUIT);
		DeleteGroup(GROUP_TYPE::GAMETITLE);
	}
}

void Stage3::Enter()
{
	// Object 추가		
	CBackGround* pBack = new CBackGround;			///이게 의미하는 바가 뭐지?
	pBack->SetPos(Vecor2(0.f, 0.f));
	pBack->SetTexture(L"Stage3_Left", L"texture\\3stageLeft.bmp");
	pBack->SetSize(510, 875);
	//pBack->SetScale(Vecor2(100.f, 100.f));
	AddObject(pBack, GROUP_TYPE::DEFALUT);

	CBackGround* pBack2 = new CBackGround;			///이게 의미하는 바가 뭐지?
	pBack2->SetPos(Vecor2(510.f, 0.f));
	pBack2->SetTexture(L"Stage3_Right", L"texture\\3stageRight.bmp");
	pBack2->SetSize(2590, 875);
	//pBack->SetScale(Vecor2(100.f, 100.f));
	AddObject(pBack2, GROUP_TYPE::DEFALUT);

	//생선추가
	CObject* fish = new CFish;					///마우스로 이동이 가능한 생선을 만든다.
	fish->SetPos(Vecor2(1000.f, 400.f));
	fish->SetScale(Vecor2(100.f, 100.f));
	AddObject(fish, GROUP_TYPE::FISH);

	//PLAYER 추가
	CPlayer* pObj = new CPlayer;				///WASD로 이동이 가능한 플레이어를 만든다
	pObj->SetName(L"PLAYER");
	pObj->SetPos(Vecor2(3000.f, 750.f));
	pObj->SetScale(Vecor2(100.f, 100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);

	//CPlayer*
	if (!pObj->IsDead()) 
	{											///플레이어의 좌,우의 충돌을 도와줄 하나의 콜라이더를 만든다.
		PlayerWidth* pWidth = new PlayerWidth;
		pWidth->SetName(L"PLAYERWidth");
		pWidth->SetPos(Vecor2(150.f, 150.f));
		pWidth->SetScale(Vecor2(100.f, 100.f));
		pWidth->SetPlayer(pObj);
		AddObject(pWidth, GROUP_TYPE::PLAYER);
	}

	//카메라
	Vecor2 vResolution = CGameProcess::GetInstance()->GetResolution();		///플레이어와 물고기 사이에 위치하는 카메라이다.
	CCamera::GetInstance()->SetLookAt(vResolution / 2.f);
	CCamera::GetInstance()->SetTarget(pObj, fish);

	for (int i = 0; i < 3; i++)
	{
		CWall* WallL = nullptr;
		WallL = new CWall;
		WallL->SetName(L"Wall");					///왼쪽벽
		WallL->SetPos(Vecor2(0.f, 300.f * i + 150.f));			// 벽의 포지션
		WallL->SetScale(Vecor2(50.f, 300.f));		// 스케일크기를 조절할 수 있다.
		WallL->GetCollider()->SetScale(Vecor2(50.f, 300.f));	//발판 충돌 사이즈 값
		AddObject(WallL, GROUP_TYPE::WALL);
	}

	///가짜 왼쪽벽 물고기충돌
	FakeWallLeftRight* FakeWall_L = nullptr;
	FakeWall_L = new FakeWallLeftRight;
	FakeWall_L->SetName(L"FakeLeft");					///왼쪽벽
	FakeWall_L->SetPos(Vecor2(0.f, 600.f));			// 벽의 포지션
//	FakeWall_L->SetScale(Vecor2(50.f, 2000.f));		// 스케일크기를 조절할 수 있다.
	FakeWall_L->GetCollider()->SetScale(Vecor2(50.f, 2000.f));	//발판 충돌 사이즈 값
	AddObject(FakeWall_L, GROUP_TYPE::FAKE);

	for (int i = 0; i < 3; i++)
	{
		CWall* WallR1 = nullptr;
		WallR1 = new CWall;
		WallR1->SetName(L"Wall");					///오른쪽 벽1
		WallR1->SetPos(Vecor2(3100.f, 300.f * i + 150.f));			// 벽의 포지션
		WallR1->SetScale(Vecor2(50.f, 300.f));		// 스케일크기를 조절할 수 있다.
		WallR1->GetCollider()->SetScale(Vecor2(50.f, 300.f));	// 충돌 사이즈 값
		AddObject(WallR1, GROUP_TYPE::WALL);
	}

	///가짜 오른쪽벽 물고기충돌
	FakeWallLeftRight* FakeWall_R = nullptr;
	FakeWall_R = new FakeWallLeftRight;
	FakeWall_R->SetName(L"FakeRight");					/// 오른쪽 벽
	FakeWall_R->SetPos(Vecor2(3100.f, 600.f));			// 벽의 포지션
//	FakeWall_R->SetScale(Vecor2(50.f, 2000.f));		// 스케일크기를 조절할 수 있다.
	FakeWall_R->GetCollider()->SetScale(Vecor2(50.f, 2000.f));	//발판 충돌 사이즈 값
	AddObject(FakeWall_R, GROUP_TYPE::FAKE);

	for (int i = 0; i < 9; i++)
	{
		Floor* Floor3 = nullptr;
		Floor3 = new Floor;
		Floor3->SetName(L"Floor1");					///위쪽 벽->바닥
		Floor3->SetPos(Vecor2(350.f * i + 150.f, 0.f));			// 벽의 포지션
		Floor3->SetScale(Vecor2(350.f, 50.f));		// 스케일크기를 조절할 수 있다.
		Floor3->GetCollider()->SetScale(Vecor2(350.f, 50.f));	// 충돌 사이즈 값
		AddObject(Floor3, GROUP_TYPE::WALL);
	}

	///가짜천장
	FakeWallUpDown* FakeFloor2 = nullptr;
	FakeFloor2 = new FakeWallUpDown;
	FakeFloor2->SetName(L"FakeUP");
	FakeFloor2->SetPos(Vecor2(1200.f, 0.f)); ///천장의 중점
	//FakeFloor2->SetScale(Vecor2(4000.f, 50.f));
	FakeFloor2->GetCollider()->SetScale(Vecor2(4000.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(FakeFloor2, GROUP_TYPE::FAKE);

	/// 맨 밑 
	for (int i = 0; i < 9; i++)
	{
		Floor* Floor2 = nullptr;
		Floor2 = new Floor;
		Floor2->SetName(L"FLOOR1");
		Floor2->SetPos(Vecor2(350.f * i + 150.f, 875.f)); // 바닥의 중점
		Floor2->SetScale(Vecor2(350.f, 50.f));
		Floor2->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//발판 충돌 사이즈 값
		AddObject(Floor2, GROUP_TYPE::FLOOR);
	}

	FakeWallUpDown* FakeFloor1 = nullptr;
	FakeFloor1 = new FakeWallUpDown;
	FakeFloor1->SetName(L"FakeDown");
	FakeFloor1->SetPos(Vecor2(1200.f, 875.f)); ///바닥의 중점
//	FakeFloor1->SetScale(Vecor2(4000.f, 50.f));
	FakeFloor1->GetCollider()->SetScale(Vecor2(4000.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(FakeFloor1, GROUP_TYPE::FAKE);


	///------------ 사다리 2개------------- 
	CLadder* Ladder1 = nullptr;
	Ladder1 = new CLadder;
	Ladder1->SetName(L"Ladder1");
	Ladder1->SetPos(Vecor2(2300.f, 615.f));	 // 사다리의 포지션
	Ladder1->SetScale(Vecor2(5.f, 450.f));	 // 스케일크기
	Ladder1->GetCollider()->SetScale(Vecor2(5.f, 450.f));	// 충돌 사이즈 값
	AddObject(Ladder1, GROUP_TYPE::LADDER);

	CLadder* Ladder2 = nullptr;
	Ladder2 = new CLadder;
	Ladder2->SetName(L"Ladder1");
	Ladder2->SetPos(Vecor2(1400.f, 615.f));	 // 사다리의 포지션
	Ladder2->SetScale(Vecor2(5.f, 450.f));	 // 스케일크기
	Ladder2->GetCollider()->SetScale(Vecor2(5.f, 450.f));	// 충돌 사이즈 값
	AddObject(Ladder2, GROUP_TYPE::LADDER);

///---------------2층발판----------------
	Floor* Floor3 = nullptr;
	Floor3 = new Floor;
	Floor3->SetName(L"FLOOR2");
	Floor3->SetPos(Vecor2(1400.f, 415.f)); //바닥의 중점
	Floor3->SetScale(Vecor2(350.f, 50.f));
	Floor3->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(Floor3, GROUP_TYPE::FLOOR);

	Floor* Floor4 = nullptr;
	Floor4 = new Floor;
	Floor4->SetName(L"FLOOR2");
	Floor4->SetPos(Vecor2(1750.f, 415.f)); //바닥의 중점
	Floor4->SetScale(Vecor2(350.f, 50.f));
	Floor4->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(Floor4, GROUP_TYPE::FLOOR);

	Floor* Floor5 = nullptr;
	Floor5 = new Floor;
	Floor5->SetName(L"FLOOR2");
	Floor5->SetPos(Vecor2(2100.f, 415.f)); //바닥의 중점
	Floor5->SetScale(Vecor2(350.f, 50.f));
	Floor5->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(Floor5, GROUP_TYPE::FLOOR);

	Floor* Floor6 = nullptr;
	Floor6 = new Floor;
	Floor6->SetName(L"FLOOR2");
	Floor6->SetPos(Vecor2(2450.f, 415.f)); //바닥의 중점
	Floor6->SetScale(Vecor2(350.f, 50.f));
	Floor6->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//발판 충돌 사이즈 값

	AddObject(Floor6, GROUP_TYPE::FLOOR);

///-------------------------------오브젝트



	/// 바위 (큰 돌) 배치
	CRock* Rock1 = nullptr;
	Rock1 = new CRock;
	Rock1->SetName(L"Rock");
	Rock1->SetPos(Vecor2(1650.f, 100.f)); // 바위의 위치
	Rock1->SetScale(Vecor2(100.f, 270.f));
	Rock1->GetCollider()->SetScale(Vecor2(100.f, 270.f));	// 충돌 사이즈 값
	AddObject(Rock1, GROUP_TYPE::ROCK);

	/// 도어 버튼
	DoorButton* doorButton1 = nullptr;
	doorButton1 = new DoorButton;
	doorButton1->SetName(L"DoorButton");
	doorButton1->SetPos(Vecor2(1150.f, 841.f));
	doorButton1->SetScale(Vecor2(50.f, 20.f));
	doorButton1->GetCollider()->SetScale(Vecor2(50.f, 20.f));
	AddObject(doorButton1, GROUP_TYPE::DOORBUTTON);

///----------------------------------------문과 문위의 벽
	CWall* WallL1 = nullptr;
	WallL1 = new CWall;
	WallL1->SetName(L"Wall");					
	WallL1->SetPos(Vecor2(510.f, 200.f));			// 벽의 포지션
	WallL1->SetScale(Vecor2(50.f, 300.f));		// 스케일크기를 조절할 수 있다.
	WallL1->GetCollider()->SetScale(Vecor2(50.f, 300.f));	//발판 충돌 사이즈 값
	AddObject(WallL1, GROUP_TYPE::WALL);

	CWall* WallL2 = nullptr;
	WallL2 = new CWall;
	WallL2->SetName(L"Wall");
	WallL2->SetPos(Vecor2(510.f, 500.f));			// 벽의 포지션
	WallL2->SetScale(Vecor2(50.f, 300.f));		// 스케일크기를 조절할 수 있다.
	WallL2->GetCollider()->SetScale(Vecor2(50.f, 300.f));	//발판 충돌 사이즈 값
	AddObject(WallL2, GROUP_TYPE::WALL);

	/// 벽 문
	Door* door1 = nullptr;
	door1 = new Door;
	door1->SetName(L"Door");
	door1->SetPos(Vecor2(510.f, 750.f));
	door1->SetScale(Vecor2(20.f, 200.f));
	door1->GetCollider()->SetScale(Vecor2(20.f, 200.f));
	AddObject(door1, GROUP_TYPE::DOOR);

	/// stage4 이동
	GoToNextScene* GoToNextScene3 = nullptr;
	GoToNextScene3 = new GoToNextScene;
	GoToNextScene3->SetName(L"GoToNextScene");					///다음 씬으로 가기위한 투명한..무언가
	GoToNextScene3->SetPos(Vecor2(100.f, 651.f));			// 벽의 포지션
	GoToNextScene3->SetScale(Vecor2(50.f, 400.f));		// 스케일크기를 조절할 수 있다.
	GoToNextScene3->GetCollider()->SetScale(Vecor2(50.f, 400.f));	// 충돌 사이즈 값
	AddObject(GoToNextScene3, GROUP_TYPE::GOTONEXTSCENE);

	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::ROCK);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::FLOOR);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::LADDER);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::WALL);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::DOOR);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::DOORBUTTON);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::FISH, GROUP_TYPE::WALL);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::FISH, GROUP_TYPE::FAKE);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::ROCK, GROUP_TYPE::FLOOR);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::ROCK, GROUP_TYPE::WALL);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::ROCK, GROUP_TYPE::DOORBUTTON);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::GOTONEXTSCENE);
}

void Stage3::Exit()
{
	DeleteAll();

	// 충돌 체크 한 것을 해제한다.
	CCollisionManager::GetInstance()->Reset();
}
