#include "pch.h"
#include "Stage5.h"

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
#include "KeyDoor.h"
#include "DoorKey.h"

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

Stage5::Stage5()
{

}

Stage5::~Stage5()
{

}

void Stage5::Update()
{
	CScene::Update();

	if (KEY_TAP(KEY::ENTER))
	{
		CSceneManager::GetInstance()->ChangeScene(SCENE_TYPE::STAGE_05);
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

void Stage5::Enter()
{
	// Object 추가		
	CBackGround* pBack = new CBackGround;			///이게 의미하는 바가 뭐지?
	pBack->SetPos(Vecor2(0.f, 0.f));
	pBack->SetTexture(L"Stage5", L"texture\\Stage_5.bmp");
	pBack->SetSize(3800, 1175);
	//pBack->SetScale(Vecor2(100.f, 100.f));
	AddObject(pBack, GROUP_TYPE::DEFALUT);

	//생선추가
	CObject* fish = new CFish;					///마우스로 이동이 가능한 생선을 만든다.
	fish->SetName(L"FISH");
	fish->SetPos(Vecor2(950.f, 500.f));
	fish->SetName(L"FISH");
	fish->SetScale(Vecor2(100.f, 100.f));
	AddObject(fish, GROUP_TYPE::FISH);

	//PLAYER 추가
	CPlayer* pObj = new CPlayer;				///WASD로 이동이 가능한 플레이어를 만든다
	pObj->SetName(L"PLAYER");
	pObj->SetPos(Vecor2(3700.f, 1050.f));
	pObj->SetScale(Vecor2(600.f, 100.f));
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

	for (int i = 0; i < 4; i++)
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
	//FakeWall_L->SetScale(Vecor2(50.f, 2000.f));		// 스케일크기를 조절할 수 있다.
	FakeWall_L->GetCollider()->SetScale(Vecor2(50.f, 2000.f));	//발판 충돌 사이즈 값
	AddObject(FakeWall_L, GROUP_TYPE::FAKE);

	for (int i = 0; i < 4; i++)
	{
		CWall* WallR1 = nullptr;
		WallR1 = new CWall;
		WallR1->SetName(L"Wall");					///오른쪽 벽1
		WallR1->SetPos(Vecor2(3800.f, 300.f * i + 150.f));			// 벽의 포지션
		WallR1->SetScale(Vecor2(50.f, 300.f));		// 스케일크기를 조절할 수 있다.
		WallR1->GetCollider()->SetScale(Vecor2(50.f, 300.f));	// 충돌 사이즈 값
		AddObject(WallR1, GROUP_TYPE::WALL);
	}

	///가짜 오른쪽벽 물고기충돌
	FakeWallLeftRight* FakeWall_R = nullptr;
	FakeWall_R = new FakeWallLeftRight;
	FakeWall_R->SetName(L"FakeRight");					/// 오른쪽 벽
	FakeWall_R->SetPos(Vecor2(3800.f, 600.f));			// 벽의 포지션
//	FakeWall_R->SetScale(Vecor2(50.f, 2000.f));		// 스케일크기를 조절할 수 있다.
	FakeWall_R->GetCollider()->SetScale(Vecor2(50.f, 2000.f));	//발판 충돌 사이즈 값
	AddObject(FakeWall_R, GROUP_TYPE::FAKE);

	for (int i = 0; i < 11; i++)
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
	//FakeFloor2->SetScale(Vecor2(6000.f, 50.f));
	FakeFloor2->GetCollider()->SetScale(Vecor2(6000.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(FakeFloor2, GROUP_TYPE::FAKE);

	/// 맨 밑 
	for (int i = 0; i < 11; i++)
	{
		Floor* Floor2 = nullptr;
		Floor2 = new Floor;
		Floor2->SetName(L"FLOOR1");
		Floor2->SetPos(Vecor2(350.f * i + 150.f, 1175.f)); // 바닥의 중점
		Floor2->SetScale(Vecor2(350.f, 50.f));
		Floor2->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//발판 충돌 사이즈 값
		AddObject(Floor2, GROUP_TYPE::FLOOR);
	}

	FakeWallUpDown* FakeFloor1 = nullptr;
	FakeFloor1 = new FakeWallUpDown;
	FakeFloor1->SetName(L"FakeDown");
	FakeFloor1->SetPos(Vecor2(1200.f, 1175.f)); ///바닥의 중점
//	FakeFloor1->SetScale(Vecor2(6000.f, 50.f));
	FakeFloor1->GetCollider()->SetScale(Vecor2(6000.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(FakeFloor1, GROUP_TYPE::FAKE);

	/// 4950.f, 1400.f 플레이어 현 위치
	/// 기믹1 시작
	Floor* floor1 = nullptr; /// 기믹1 아래 발판 1
	floor1 = new Floor;
	floor1->SetName(L"Wall");
	floor1->SetPos(Vecor2(3400.f, 925.f)); // 바닥의 중점
	floor1->SetScale(Vecor2(350.f, 50.f));
	floor1->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(floor1, GROUP_TYPE::WALL);
	

	Floor* floor2 = nullptr; /// 기믹1 위쪽 발판
	floor2 = new Floor;
	floor2->SetName(L"Wall");
	floor2->SetPos(Vecor2(3600.f, 625.f)); // 바닥의 중점
	floor2->SetScale(Vecor2(350.f, 50.f));
	floor2->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(floor2, GROUP_TYPE::WALL);

	Floor* floor3 = nullptr; /// 기믹1 아래 발판 2
	floor3 = new Floor;
	floor3->SetName(L"Wall");
	floor3->SetPos(Vecor2(3050.f, 925.f)); 
	floor3->SetScale(Vecor2(350.f, 50.f));
	floor3->GetCollider()->SetScale(Vecor2(350.f, 50.f));	
	AddObject(floor3, GROUP_TYPE::WALL);

	CWall* wall1 = nullptr; /// 기믹 버튼 벽
	wall1 = new CWall;
	wall1->SetName(L"Wall");					
	wall1->SetPos(Vecor2(2900.f, 750.f));
	wall1->SetScale(Vecor2(50.f, 300.f));
	wall1->GetCollider()->SetScale(Vecor2(50.f, 300.f));	
	AddObject(wall1, GROUP_TYPE::WALL);

	CWall* wall2 = nullptr; /// 기믹 버튼 벽2
	wall2 = new CWall;
	wall2->SetName(L"Wall");
	wall2->SetPos(Vecor2(2900.f, 450.f));
	wall2->SetScale(Vecor2(50.f, 300.f));
	wall2->GetCollider()->SetScale(Vecor2(50.f, 300.f));
	AddObject(wall2, GROUP_TYPE::WALL);
	
	Floor* floor4 = nullptr; /// 기믹1 위쪽 발판 연계 3
	floor4 = new Floor;
	floor4->SetName(L"Wall");
	floor4->SetPos(Vecor2(3050.f, 275.f));
	floor4->SetScale(Vecor2(350.f, 50.f));
	floor4->GetCollider()->SetScale(Vecor2(350.f, 50.f));
	AddObject(floor4, GROUP_TYPE::WALL);

	//FishDoor* fishDoor1 = nullptr; /// 기믹 버튼 클릭시 열리는 문 
	//fishDoor1 = new FishDoor;
	//fishDoor1->SetName(L"Door");
	//fishDoor1->SetPos(Vecor2(4650.f, 1324.f));
	//fishDoor1->SetScale(Vecor2(20.f, 200.f));
	//fishDoor1->GetCollider()->SetScale(Vecor2(20.f, 200.f));
	//AddObject(fishDoor1, GROUP_TYPE::DOOR);
	
	Floor* floor5 = nullptr; /// 기믹1 위쪽 발판 연계 4
	floor5 = new Floor;
	floor5->SetName(L"Wall");
	floor5->SetPos(Vecor2(3400.f, 275.f));
	floor5->SetScale(Vecor2(350.f, 50.f));
	floor5->GetCollider()->SetScale(Vecor2(350.f, 50.f));
	AddObject(floor5, GROUP_TYPE::WALL);

	CLadder* ladder1 = nullptr; /// 기믹1 사다리 1
	ladder1 = new CLadder;
	ladder1->SetName(L"Ladder1");
	ladder1->SetPos(Vecor2(2750.f, 925.f));	 // 사다리의 포지션
	ladder1->SetScale(Vecor2(5.f, 450.f));	 // 스케일크기
	ladder1->GetCollider()->SetScale(Vecor2(5.f, 450.f));	// 충돌 사이즈 값
	AddObject(ladder1, GROUP_TYPE::LADDER);

	CLadder* ladder2 = nullptr; /// 기믹1 사다리 2
	ladder2 = new CLadder;
	ladder2->SetName(L"Ladder1");
	ladder2->SetPos(Vecor2(2100.f, 925.f));	 // 사다리의 포지션
	ladder2->SetScale(Vecor2(5.f, 450.f));	 // 스케일크기
	ladder2->GetCollider()->SetScale(Vecor2(5.f, 450.f));	// 충돌 사이즈 값
	AddObject(ladder2, GROUP_TYPE::LADDER);

	Floor* floor6 = nullptr; /// 기믹1 사다리 후 발판 1
	floor6 = new Floor;
	floor6->SetName(L"FLOOR2");
	floor6->SetPos(Vecor2(2600.f, 725.f));
	floor6->SetScale(Vecor2(350.f, 50.f));
	floor6->GetCollider()->SetScale(Vecor2(350.f, 50.f));
	AddObject(floor6, GROUP_TYPE::FLOOR);

	Floor* floor7 = nullptr; /// 기믹1 사다리 후 발판 2
	floor7 = new Floor;
	floor7->SetName(L"FLOOR2");
	floor7->SetPos(Vecor2(2250.f, 725.f));
	floor7->SetScale(Vecor2(350.f, 50.f));
	floor7->GetCollider()->SetScale(Vecor2(350.f, 50.f));
	AddObject(floor7, GROUP_TYPE::FLOOR);

	SeaUr* seaUr = nullptr; /// 성게가 막고 있어서 사다리 타고 올라갸아한다.
	seaUr = new SeaUr;
	seaUr->SetName(L"SeaUr");
	seaUr->SetPos(Vecor2(2425.f, 1050.f)); //바닥의 중점
	seaUr->SetScale(Vecor2(200.f, 200.f));
	seaUr->GetCollider()->SetScale(Vecor2(200.f, 200.f));	//발판 충돌 사이즈 값
	AddObject(seaUr, GROUP_TYPE::SEAUR);
//-------------------------------------------------------------------------
	FishButton* fishButton12 = nullptr; /// 물고기 버튼 fish #1
	fishButton12 = new FishButton;
	fishButton12->SetName(L"FishButton");
	fishButton12->SetPos(Vecor2(3050.f, 310.f));
	fishButton12->SetScale(Vecor2(50.f, 20.f));
	fishButton12->GetCollider()->SetScale(Vecor2(50.f, 20.f));	
	AddObject(fishButton12, GROUP_TYPE::FISHBUTTON);
	
	/// 기믹 1 끝
	/// 기믹 2 시작
	FishDoor* fishDoor22 = nullptr; /// 기믹2 문 fish #1 
	fishDoor22 = new FishDoor;
	fishDoor22->SetName(L"Door");
	fishDoor22->SetPos(Vecor2(1365.f, 801.f));
	fishDoor22->SetScale(Vecor2(20.f, 200.f));
	fishDoor22->GetCollider()->SetScale(Vecor2(20.f, 200.f));
	AddObject(fishDoor22, GROUP_TYPE::DOOR);
//------------------------------------------------------------------------------	
	CRock* rock1 = nullptr; /// 돌 배치하면서 
	rock1 = new CRock;
	rock1->SetName(L"Rock");
	rock1->SetPos(Vecor2(1900.f, 975.f)); // 바위의 위치
	rock1->SetScale(Vecor2(150.f, 150.f));
	rock1->GetCollider()->SetScale(Vecor2(150.f, 150.f));	// 충돌 사이즈 값
	AddObject(rock1, GROUP_TYPE::ROCK);

	Floor* floor8 = nullptr; /// 기믹2 위쪽 발판 1
	floor8 = new Floor;
	floor8->SetName(L"Wall");
	floor8->SetPos(Vecor2(1150.f, 925.f));
	floor8->SetScale(Vecor2(350.f, 50.f));
	floor8->GetCollider()->SetScale(Vecor2(350.f, 50.f));
	AddObject(floor8, GROUP_TYPE::WALL);

	Floor* floor9 = nullptr; /// 기믹2 위쪽 발판 2
	floor9 = new Floor;
	floor9->SetName(L"Wall");
	floor9->SetPos(Vecor2(1500.f, 925.f));
	floor9->SetScale(Vecor2(350.f, 50.f));
	floor9->GetCollider()->SetScale(Vecor2(350.f, 50.f));
	AddObject(floor9, GROUP_TYPE::WALL);


	//DoorButton* doorButton1 = nullptr; /// 돌을 이용한 버튼 문1과 연결
	//doorButton1 = new DoorButton;
	//doorButton1->SetName(L"DoorButton");
	//doorButton1->SetPos(Vecor2(2850.f, 1415.f));
	//doorButton1->SetScale(Vecor2(50.f, 20.f));
	//doorButton1->GetCollider()->SetScale(Vecor2(50.f, 20.f));
	//AddObject(doorButton1, GROUP_TYPE::DOORBUTTON);

	CWall* wall3 = nullptr; /// 기믹1에서 버튼 1 이랑 연결된 문1 윗부분 벽
	wall3 = new CWall;
	wall3->SetName(L"Wall");
	wall3->SetPos(Vecor2(1365.f, 551.f));
	wall3->SetScale(Vecor2(50.f, 300.f));
	wall3->GetCollider()->SetScale(Vecor2(50.f, 300.f));
	AddObject(wall3, GROUP_TYPE::WALL);

	Floor* floor10 = nullptr; /// 기믹2 위쪽 발판 3
	floor10 = new Floor;
	floor10->SetName(L"Wall");
	floor10->SetPos(Vecor2(1215.f, 376.f));
	floor10->SetScale(Vecor2(350.f, 50.f));
	floor10->GetCollider()->SetScale(Vecor2(350.f, 50.f));
	AddObject(floor10, GROUP_TYPE::WALL);

	CWall* wall4 = nullptr; /// 문 바깥쪽 윗부분 벽
	wall4 = new CWall;
	wall4->SetName(L"Wall");
	wall4->SetPos(Vecor2(1000.f, 500.f));
	wall4->SetScale(Vecor2(50.f, 300.f));
	wall4->GetCollider()->SetScale(Vecor2(50.f, 300.f));
	AddObject(wall4, GROUP_TYPE::WALL);

	CWall* wall5 = nullptr; /// 문 바깥쪽 아래부분 벽
	wall5 = new CWall;
	wall5->SetName(L"Wall");
	wall5->SetPos(Vecor2(1000.f, 800.f));
	wall5->SetScale(Vecor2(50.f, 300.f));
	wall5->GetCollider()->SetScale(Vecor2(50.f, 300.f));
	AddObject(wall5, GROUP_TYPE::WALL);
///---------------------------------------------------------------------
	/// 물고기 버튼
	DoorKey* fishButton2 = nullptr; /// 물고기 버튼 fish #2
	fishButton2 = new DoorKey;
	fishButton2->SetName(L"FishButton");
	fishButton2->SetPos(Vecor2(1200.f, 410.f));
	fishButton2->SetScale(Vecor2(50.f, 20.f));
	fishButton2->GetCollider()->SetScale(Vecor2(50.f, 20.f));
	AddObject(fishButton2, GROUP_TYPE::FISHBUTTON);
	
	/// 물고기 문
	KeyDoor* fishDoor3 = nullptr; /// 기믹 버튼 클릭시 열리는 문  fish #2
	fishDoor3 = new KeyDoor;
	fishDoor3->SetName(L"Door");
	fishDoor3->SetPos(Vecor2(1000.f, 1050.f));
	fishDoor3->SetScale(Vecor2(20.f, 200.f));
	fishDoor3->GetCollider()->SetScale(Vecor2(20.f, 200.f));
	AddObject(fishDoor3, GROUP_TYPE::DOOR);
///----------------------------------------------------------------------
	DoorButton* doorButton2 = nullptr; /// 돌을 이용한 버튼 문2과 연결 rock #1
	doorButton2 = new DoorButton;
	doorButton2->SetName(L"DoorButton");
	doorButton2->SetPos(Vecor2(600.f, 1140.f));
	doorButton2->SetScale(Vecor2(50.f, 20.f));
	doorButton2->GetCollider()->SetScale(Vecor2(50.f, 20.f));
	AddObject(doorButton2, GROUP_TYPE::DOORBUTTON);

	CWall* wall6 = nullptr; /// 돌을 더 이상 사용하지 못하게 벽으로 막는다.
	wall6 = new CWall;
	wall6->SetName(L"Wall");
	wall6->SetPos(Vecor2(400.f, 1000.f));
	wall6->SetScale(Vecor2(50.f, 300.f));
	wall6->GetCollider()->SetScale(Vecor2(50.f, 300.f));
	AddObject(wall6, GROUP_TYPE::WALL);

	Floor* floor11 = nullptr; /// 돌을 더 이상 사용하지 못하게 위의 벽을 넣는다.
	floor11 = new Floor;
	floor11->SetName(L"Wall");
	floor11->SetPos(Vecor2(600.f, 875.f));
	floor11->SetScale(Vecor2(350.f, 50.f));
	floor11->GetCollider()->SetScale(Vecor2(350.f, 50.f));
	AddObject(floor11, GROUP_TYPE::FLOOR);

	CWall* wall7 = nullptr; /// 돌 위로 갈 수 없게 벽을 처서 막는다.
	wall7 = new CWall;
	wall7->SetName(L"Wall");
	wall7->SetPos(Vecor2(750.f, 700.f));
	wall7->SetScale(Vecor2(50.f, 300.f));
	wall7->GetCollider()->SetScale(Vecor2(50.f, 300.f));
	AddObject(wall7, GROUP_TYPE::WALL);

	Floor* floor12 = nullptr; /// 다음 스테이지로 갈 수 있는 발판 1
	floor12 = new Floor;
	floor12->SetName(L"FLOOR2");
	floor12->SetPos(Vecor2(700.f, 525.f));
	floor12->SetScale(Vecor2(350.f, 50.f));
	floor12->GetCollider()->SetScale(Vecor2(350.f, 50.f));
	AddObject(floor12, GROUP_TYPE::FLOOR);

	Floor* floor13 = nullptr; /// 다음 스테이지로 갈 수 있는 발판 2
	floor13 = new Floor;
	floor13->SetName(L"FLOOR2");
	floor13->SetPos(Vecor2(350.f, 525.f));
	floor13->SetScale(Vecor2(350.f, 50.f));
	floor13->GetCollider()->SetScale(Vecor2(350.f, 50.f));
	AddObject(floor13, GROUP_TYPE::FLOOR);

	Door* door1 = nullptr;	/// 돌로 밀면 마지막 문이 열린다. rock #1
	door1 = new Door;
	door1->SetName(L"Door");
	door1->SetPos(Vecor2(425.f, 400.f));
	door1->SetScale(Vecor2(20.f, 200.f));
	door1->GetCollider()->SetScale(Vecor2(20.f, 200.f));
	AddObject(door1, GROUP_TYPE::DOOR);

	CWall* wall8 = nullptr; /// 문이 사라지게끔 문 위에 벽을 친다.
	wall8 = new CWall;
	wall8->SetName(L"Wall");
	wall8->SetPos(Vecor2(425.f, 151.f));
	wall8->SetScale(Vecor2(50.f, 300.f));
	wall8->GetCollider()->SetScale(Vecor2(50.f, 300.f));
	AddObject(wall8, GROUP_TYPE::WALL);

	CLadder* ladder3 = nullptr; /// 엔딩으로 가는 사다리 1
	ladder3 = new CLadder;
	ladder3->SetName(L"Ladder1");
	ladder3->SetPos(Vecor2(875.f, 525.f));	 // 사다리의 포지션
	ladder3->SetScale(Vecor2(5.f, 450.f));	 // 스케일크기
	ladder3->GetCollider()->SetScale(Vecor2(5.f, 450.f));	// 충돌 사이즈 값
	AddObject(ladder3, GROUP_TYPE::LADDER);

	CLadder* ladder4 = nullptr; /// 엔딩으로 가는 사다리 2
	ladder4 = new CLadder;
	ladder4->SetName(L"Ladder1");
	ladder4->SetPos(Vecor2(875.f, 925.f));	 // 사다리의 포지션
	ladder4->SetScale(Vecor2(5.f, 450.f));	 // 스케일크기
	ladder4->GetCollider()->SetScale(Vecor2(5.f, 450.f));	// 충돌 사이즈 값
	AddObject(ladder4, GROUP_TYPE::LADDER);

	/// 엔딩 스테이지로 ㄱㄱ
	GoToNextScene* GoToNextScene5 = nullptr;
	GoToNextScene5 = new GoToNextScene;
	GoToNextScene5->SetName(L"GoToNextScene");					///다음 씬으로 가기위한 투명한..무언가
	GoToNextScene5->SetPos(Vecor2(225.f, 401.f));			// 벽의 포지션
	GoToNextScene5->SetScale(Vecor2(50.f, 200.f));		// 스케일크기를 조절할 수 있다.
	GoToNextScene5->GetCollider()->SetScale(Vecor2(50.f, 200.f));	// 충돌 사이즈 값
	AddObject(GoToNextScene5, GROUP_TYPE::GOTONEXTSCENE);


	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::ROCK);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::FLOOR);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::LADDER);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::WALL);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::DOOR);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::SHARK);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::SEAUR);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::DOORBUTTON);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::GOTONEXTSCENE);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::FISH, GROUP_TYPE::WALL);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::FISH, GROUP_TYPE::FAKE);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::FISH, GROUP_TYPE::FISHBUTTON);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::FISH, GROUP_TYPE::FAKE);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::ROCK, GROUP_TYPE::FLOOR);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::ROCK, GROUP_TYPE::WALL);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::ROCK, GROUP_TYPE::DOORBUTTON);
}

void Stage5::Exit()
{
	DeleteAll();

	// 충돌 체크 한 것을 해제한다.
	CCollisionManager::GetInstance()->Reset();
}

