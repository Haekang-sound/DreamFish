#include "pch.h"
#include "Stage6.h"

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

void Stage6::Update()
{
	CScene::Update();

	if (KEY_TAP(KEY::ENTER))
	{
		CSceneManager::GetInstance()->ChangeScene(SCENE_TYPE::STAGE_06);
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

void Stage6::Enter()
{
	// Object 추가		
	CBackGround* pBack = new CBackGround;			///이게 의미하는 바가 뭐지?
	pBack->SetPos(Vecor2(0.f, 0.f));
	pBack->SetTexture(L"Stage6_Up", L"texture\\Stage_6_Up.bmp");
	pBack->SetSize(3100, 900);
	//pBack->SetScale(Vecor2(100.f, 100.f));
	AddObject(pBack, GROUP_TYPE::DEFALUT);

	CBackGround* pBack2 = new CBackGround;			///이게 의미하는 바가 뭐지?
	pBack2->SetPos(Vecor2(0.f, 900.f));
	pBack2->SetTexture(L"Stage6_Down", L"texture\\Stage_6_Down.bmp");
	pBack2->SetSize(3100, 575);
	//pBack->SetScale(Vecor2(100.f, 100.f));
	AddObject(pBack2, GROUP_TYPE::DEFALUT);

	//생선추가
	CObject* fish = new CFish;					///마우스로 이동이 가능한 생선을 만든다.
	fish->SetPos(Vecor2(100.f, 400.f));
	fish->SetScale(Vecor2(100.f, 100.f));
	AddObject(fish, GROUP_TYPE::FISH);

	//PLAYER 추가
	CPlayer* pObj = new CPlayer;				///WASD로 이동이 가능한 플레이어를 만든다
	pObj->SetName(L"PLAYER");
	pObj->SetPos(Vecor2(2800.f, 1300.f));
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

	for (int i = 0; i < 5; i++)
	{
		CWall* WallL = nullptr;
		WallL = new CWall;
		WallL->SetName(L"Wall");					///왼쪽벽
		WallL->SetPos(Vecor2(0.f, 300.f * i + 150.f));			// 벽의 포지션
		WallL->SetScale(Vecor2(50.f, 300.f));		// 스케일크기를 조절할 수 있다.
		WallL->GetCollider()->SetScale(Vecor2(50.f, 300.f));	//발판 충돌 사이즈 값
		AddObject(WallL, GROUP_TYPE::WALL);
	}

	/// 가짜 왼쪽벽 물고기충돌
	FakeWallLeftRight* FakeWall_L = nullptr;
	FakeWall_L = new FakeWallLeftRight;
	FakeWall_L->SetName(L"FakeLeft");					///왼쪽벽
	FakeWall_L->SetPos(Vecor2(-25.f, 600.f));			// 벽의 포지션
//	FakeWall_L->SetScale(Vecor2(50.f, 2000.f));		// 스케일크기를 조절할 수 있다.
	FakeWall_L->GetCollider()->SetScale(Vecor2(50.f, 2000.f));	//발판 충돌 사이즈 값
	AddObject(FakeWall_L, GROUP_TYPE::FAKE);


	for (int i = 0; i < 5; i++)
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
	//FakeWall_R->SetScale(Vecor2(50.f, 2000.f));		// 스케일크기를 조절할 수 있다.
	FakeWall_R->GetCollider()->SetScale(Vecor2(50.f, 2000.f));	//발판 충돌 사이즈 값
	AddObject(FakeWall_R, GROUP_TYPE::FAKE);

	/// 맨 밑 
	for (int i = 0; i < 9; i++)
	{
		Floor* Floor2 = nullptr;
		Floor2 = new Floor;
		Floor2->SetName(L"FLOOR1");
		Floor2->SetPos(Vecor2(350.f * i + 150.f, 1475.f)); // 바닥의 중점
		Floor2->SetScale(Vecor2(350.f, 50.f));
		Floor2->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//발판 충돌 사이즈 값
		AddObject(Floor2, GROUP_TYPE::FLOOR);
	}

	FakeWallUpDown* FakeFloor1 = nullptr;
	FakeFloor1 = new FakeWallUpDown;
	FakeFloor1->SetName(L"FakeDown");
	FakeFloor1->SetPos(Vecor2(1200.f, 1475.f)); ///바닥의 중점
	//FakeFloor1->SetScale(Vecor2(4000.f, 50.f));
	FakeFloor1->GetCollider()->SetScale(Vecor2(4000.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(FakeFloor1, GROUP_TYPE::FAKE);

	/// 엔딩 계단 
	Floor* Floor2 = nullptr;
	Floor2 = new Floor;
	Floor2->SetName(L"FLOOR2");					///							계단
	Floor2->SetPos(Vecor2(2500.f, 1400.f)); // 바닥의 중점
	Floor2->SetScale(Vecor2(350.f, 50.f));
	Floor2->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(Floor2, GROUP_TYPE::FLOOR);

	Floor* Floor3 = nullptr;
	Floor3 = new Floor;
	Floor3->SetName(L"FLOOR2");					///							계단
	Floor3->SetPos(Vecor2(2300.f, 1300.f)); // 바닥의 중점
	Floor3->SetScale(Vecor2(350.f, 50.f));
	Floor3->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(Floor3, GROUP_TYPE::FLOOR);

	Floor* Floor4 = nullptr;
	Floor4 = new Floor;
	Floor4->SetName(L"FLOOR2");					///							계단
	Floor4->SetPos(Vecor2(2100.f, 1200.f)); // 바닥의 중점
	Floor4->SetScale(Vecor2(350.f, 50.f));
	Floor4->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(Floor4, GROUP_TYPE::FLOOR);

	Floor* Floor5 = nullptr;
	Floor5 = new Floor;
	Floor5->SetName(L"FLOOR2");					///							계단
	Floor5->SetPos(Vecor2(1900.f, 1100.f)); // 바닥의 중점
	Floor5->SetScale(Vecor2(350.f, 50.f));
	Floor5->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(Floor5, GROUP_TYPE::FLOOR);

	Floor* Floor6 = nullptr;
	Floor6 = new Floor;
	Floor6->SetName(L"FLOOR2");					///							계단
	Floor6->SetPos(Vecor2(1700.f, 1000.f)); // 바닥의 중점
	Floor6->SetScale(Vecor2(350.f, 50.f));
	Floor6->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(Floor6, GROUP_TYPE::FLOOR);

	Floor* Floor7 = nullptr;
	Floor7 = new Floor;
	Floor7->SetName(L"FLOOR2");					///							계단
	Floor7->SetPos(Vecor2(1500.f, 900.f)); // 바닥의 중점
	Floor7->SetScale(Vecor2(350.f, 50.f));
	Floor7->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(Floor7, GROUP_TYPE::FLOOR);

	Floor* Floor8 = nullptr;
	Floor8 = new Floor;
	Floor8->SetName(L"FLOOR2");					///							계단 + 길
	Floor8->SetPos(Vecor2(1150.f, 900.f)); // 바닥의 중점
	Floor8->SetScale(Vecor2(350.f, 50.f));
	Floor8->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(Floor8, GROUP_TYPE::FLOOR);

	Floor* Floor9 = nullptr;
	Floor9 = new Floor;
	Floor9->SetName(L"FLOOR2");					///							계단 + 길
	Floor9->SetPos(Vecor2(800.f, 900.f)); // 바닥의 중점
	Floor9->SetScale(Vecor2(350.f, 50.f));
	Floor9->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(Floor9, GROUP_TYPE::FLOOR);

	Floor* Floor10 = nullptr;
	Floor10 = new Floor;
	Floor10->SetName(L"FLOOR2");					///							계단 + 길
	Floor10->SetPos(Vecor2(450.f, 900.f)); // 바닥의 중점
	Floor10->SetScale(Vecor2(350.f, 50.f)); 
	Floor10->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(Floor10, GROUP_TYPE::FLOOR);

	CWall* wall1 = nullptr;					/// 엔딩 벽
	wall1 = new CWall;
	wall1->SetName(L"Wall");
	wall1->SetPos(Vecor2(300.f, 725.f));
	wall1->SetScale(Vecor2(50.f, 300.f));
	wall1->GetCollider()->SetScale(Vecor2(50.f, 300.f));
	AddObject(wall1, GROUP_TYPE::WALL);

	CWall* wall2 = nullptr;					/// 엔딩 벽 2
	wall2 = new CWall;
	wall2->SetName(L"Wall");
	wall2->SetPos(Vecor2(300.f, 425.f));
	wall2->SetScale(Vecor2(50.f, 300.f));
	wall2->GetCollider()->SetScale(Vecor2(50.f, 300.f));
	AddObject(wall2, GROUP_TYPE::WALL);

	CWall* wall3 = nullptr;					/// 엔딩 벽 3
	wall3 = new CWall;
	wall3->SetName(L"Wall");
	wall3->SetPos(Vecor2(300.f, 125.f));
	wall3->SetScale(Vecor2(50.f, 300.f));
	wall3->GetCollider()->SetScale(Vecor2(50.f, 300.f));
	AddObject(wall3, GROUP_TYPE::WALL);

	CLadder* Ladder1 = nullptr;				/// 엔딩
	Ladder1 = new CLadder;
	Ladder1->SetName(L"Ladder1");
	Ladder1->SetPos(Vecor2(600.f, 650.f));	 // 사다리의 포지션
	Ladder1->SetScale(Vecor2(5.f, 450.f));	 // 스케일크기
	Ladder1->GetCollider()->SetScale(Vecor2(5.f, 450.f));	// 충돌 사이즈 값
	AddObject(Ladder1, GROUP_TYPE::LADDER);

	/// 다음 스테이지 
	GoToNextScene* GoToNextScene1 = nullptr;
	GoToNextScene1 = new GoToNextScene;
	GoToNextScene1->SetName(L"GoToNextScene");					///다음 씬으로 가기위한 투명한..무언가
	GoToNextScene1->SetPos(Vecor2(600.f, 250.f));			// 벽의 포지션
	GoToNextScene1->SetScale(Vecor2(200.f, 50.f));		// 스케일크기를 조절할 수 있다.
	GoToNextScene1->GetCollider()->SetScale(Vecor2(200.f, 50.f));	// 충돌 사이즈 값
	AddObject(GoToNextScene1, GROUP_TYPE::GOTONEXTSCENE);

	CLadder* Ladder2 = nullptr;				/// 엔딩
	Ladder2 = new CLadder;
	Ladder2->SetName(L"Ladder1");
	Ladder2->SetPos(Vecor2(600.f, 200.f));	 // 사다리의 포지션
	Ladder2->SetScale(Vecor2(5.f, 450.f));	 // 스케일크기
	Ladder2->GetCollider()->SetScale(Vecor2(5.f, 450.f));	// 충돌 사이즈 값
	AddObject(Ladder2, GROUP_TYPE::LADDER);

	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::ROCK);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::FLOOR);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::LADDER);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::WALL);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::DOOR);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::DOORBUTTON);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::FISH, GROUP_TYPE::WALL);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::ROCK, GROUP_TYPE::FLOOR);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::ROCK, GROUP_TYPE::WALL);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::ROCK, GROUP_TYPE::DOORBUTTON);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::GOTONEXTSCENE);
}

void Stage6::Exit()
{
	DeleteAll();

	// 충돌 체크 한 것을 해제한다.
	CCollisionManager::GetInstance()->Reset();
}

Stage6::Stage6()
{

}

Stage6::~Stage6()
{

}
