#include "pch.h"
#include "Stage1.h"

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
#include "CSoundManager.h"
#include "CCamera.h"
#include "CTimeManager.h"

#include "CButtonQuit.h"
#include "CButtonStart.h"
#include "CButtonTitle.h"

Stage1::Stage1()
{
	
}

Stage1::~Stage1()
{
	
}

void Stage1::Update()
{
	// SCEEN 튜토리얼에서 > START넘어가게끔 하기?
	CScene::Update();

	if (KEY_TAP(KEY::ENTER))
	{
		CSceneManager::GetInstance()->ChangeScene(SCENE_TYPE::STAGE_01);
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

void Stage1::Enter()
{
	SetCursorPos(1600, 800);
	
	// Object 추가		
	CBackGround* pBack = new CBackGround;			///이게 의미하는 바가 뭐지?
	pBack->SetPos(Vecor2(0.f, 0.f));
	pBack->SetTexture(L"Stage1_Left", L"texture\\1stageLeft.bmp");
	pBack->SetSize(1725, 1150);
	//pBack->SetScale(Vecor2(100.f, 100.f));
	AddObject(pBack, GROUP_TYPE::DEFALUT);

	CBackGround* pBack2 = new CBackGround;			///이게 의미하는 바가 뭐지?
	pBack2->SetPos(Vecor2(1725.f, 0.f));
	pBack2->SetTexture(L"Stage1_Right", L"texture\\1stageRight.bmp");
	pBack2->SetSize(700, 1150);
	//pBack->SetScale(Vecor2(100.f, 100.f));
	AddObject(pBack2, GROUP_TYPE::DEFALUT);

	//생선추가
	CObject* fish = new CFish;					///마우스로 이동이 가능한 생선을 만든다.
	fish->SetPos(Vecor2(1600.f, 800.f));
	fish->SetName(L"FISH");
	fish->SetScale(Vecor2(100.f, 100.f));
	AddObject(fish, GROUP_TYPE::FISH);

	//PLAYER 추가
	CPlayer* pObj = new CPlayer;				///WASD로 이동이 가능한 플레이어를 만든다
	pObj->SetName(L"PLAYER");
	pObj->SetPos(Vecor2(150.f, 150.f));
	//pObj->SetScale(Vecor2(100.f, 100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);

	//CPlayer*
	if (!pObj->IsDead()) {						///플레이어의 좌,우의 충돌을 도와줄 하나의 콜라이더를 만든다.
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

	///-------------------------------------------------------------------

		//벽배치
	for(int i = 1; i < 5 ; i++)
	{
		CWall* WallL = nullptr;
		WallL = new CWall;
		WallL->SetName(L"Wall");					///왼쪽벽
		WallL->SetPos(Vecor2(-25.f, 300.f * i - 150.f-25.f));			// 벽의 포지션
		WallL->SetScale(Vecor2(50.f, 300.f));		// 스케일크기를 조절할 수 있다.
		WallL->GetCollider()->SetScale(Vecor2(50.f, 300.f));	//발판 충돌 사이즈 값
		AddObject(WallL, GROUP_TYPE::WALL);
	}

	///가짜 왼쪽벽 물고기충돌
	FakeWallLeftRight* FakeWall_L = nullptr;
	FakeWall_L = new FakeWallLeftRight;
	FakeWall_L->SetName(L"FakeLeft");					///왼쪽벽
	FakeWall_L->SetPos(Vecor2(-25.f, 600.f));			// 벽의 포지션
	//FakeWall_L->SetScale(Vecor2(50.f, 2000.f));		// 스케일크기를 조절할 수 있다.
	FakeWall_L->GetCollider()->SetScale(Vecor2(50.f, 2000.f));	//발판 충돌 사이즈 값
	AddObject(FakeWall_L, GROUP_TYPE::FAKE);


	CWall* WallR1 = nullptr;
	WallR1 = new CWall;
	WallR1->SetName(L"Wall");					///오른쪽 벽1
	WallR1->SetPos(Vecor2(1600.f+100.f, 100.f +25.f));			// 벽의 포지션
	WallR1->SetScale(Vecor2(50.f, 300.f));		// 스케일크기를 조절할 수 있다.
	WallR1->GetCollider()->SetScale(Vecor2(50.f, 200.f));	// 충돌 사이즈 값
	AddObject(WallR1, GROUP_TYPE::WALL);


	for(int i = 0 ; i < 2 ; i++)
	{
		CWall* WallR2 = nullptr;
		WallR2 = new CWall;
		WallR2->SetName(L"Wall");					///오른쪽 벽2
		WallR2->SetPos(Vecor2(1600.f + 100.f, 500.f+i*300.f-20.f));			// 벽의 포지션
		WallR2->SetScale(Vecor2(50.f, 300.f));		// 스케일크기를 조절할 수 있다.
		WallR2->GetCollider()->SetScale(Vecor2(50.f, 300.f));	// 충돌 사이즈 값
		AddObject(WallR2, GROUP_TYPE::WALL);
	}
	
	///가짜 오른쪽벽 물고기충돌
	FakeWallLeftRight* FakeWall_R = nullptr;
	FakeWall_R = new FakeWallLeftRight;
	FakeWall_R->SetName(L"FakeRight");					///오른쪽 벽
	FakeWall_R->SetPos(Vecor2(2000.f, 600.f));			// 벽의 포지션
	//FakeWall_R->SetScale(Vecor2(50.f, 2000.f));		// 스케일크기를 조절할 수 있다.
	FakeWall_R->GetCollider()->SetScale(Vecor2(50.f, 2000.f));	//발판 충돌 사이즈 값
	AddObject(FakeWall_R, GROUP_TYPE::FAKE);




	FishDoor* FishDoor1 = nullptr;
	FishDoor1 = new FishDoor;
	FishDoor1->SetName(L"Door");					///문
	FishDoor1->SetPos(Vecor2(1600.f + 100.f, 1025.f));			// 벽의 포지션
	FishDoor1->SetScale(Vecor2(20.f, 200.f));		// 스케일크기를 조절할 수 있다.
	FishDoor1->GetCollider()->SetScale(Vecor2(20.f, 200.f));	// 충돌 사이즈 값
	AddObject(FishDoor1, GROUP_TYPE::DOOR);

	//바닥을 구현
	for(int i = 0 ; i < 7 ; i++)
	{
		Floor* Floor1 = nullptr;
		Floor1 = new Floor;
		Floor1->SetName(L"FLOOR1");
		Floor1->SetPos(Vecor2(350.f * i +150.f, 1200.f -50.f)); ///바닥의 중점
		Floor1->SetScale(Vecor2(350.f, 50.f));
		Floor1->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//발판 충돌 사이즈 값
		AddObject(Floor1, GROUP_TYPE::FLOOR);
	}
	
	///가짜 바닥판을 구현
	FakeWallUpDown* FakeFloor1 = nullptr;
	FakeFloor1 = new FakeWallUpDown;
	FakeFloor1->SetName(L"FakeDown");
	FakeFloor1->SetPos(Vecor2(1200.f, 1150.f)); ///바닥의 중점
	//FakeFloor1->SetScale(Vecor2(4000.f, 50.f));
	FakeFloor1->GetCollider()->SetScale(Vecor2(4000.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(FakeFloor1, GROUP_TYPE::FAKE);


	/*------------------ 얘는 바닥 아니냐??? ---------------------------------------*/
	for(int i = 0 ; i < 5 ; i++)
	{
		Floor* Floor3 = nullptr;
		Floor3 = new Floor;
		Floor3->SetName(L"FLOOR3");					///위쪽 벽
		Floor3->SetPos(Vecor2(350.f * i+150.f, 0.f));			// 벽의 포지션
		Floor3->SetScale(Vecor2(350.f , 50.f));		// 스케일크기를 조절할 수 있다.
		Floor3->GetCollider()->SetScale(Vecor2(350.f, 50.f));	// 충돌 사이즈 값
		AddObject(Floor3, GROUP_TYPE::FLOOR);
	}
	/*---------------------------------------------------------------------------*/
	
	///가짜천장
	FakeWallUpDown* FakeFloor2 = nullptr;
	FakeFloor2= new FakeWallUpDown;
	FakeFloor2->SetName(L"FakeUP");
	FakeFloor2->SetPos(Vecor2(1200.f, 0.f)); ///천장의 중점
	//FakeFloor2->SetScale(Vecor2(4000.f, 50.f));
	FakeFloor2->GetCollider()->SetScale(Vecor2(4000.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(FakeFloor2, GROUP_TYPE::FAKE);

 	//2층 바닥을 구현
	for(float i = 0 ; i < 2 ; i++)
	{
		Floor* Floor2 = nullptr;
		Floor2 = new Floor;
		Floor2->SetName(L"FLOOR2");
		Floor2->SetPos(Vecor2(350.f*i+150.f, 300.f)); // 2층 바닥의 중점
		//Floor2->SetScale(Vecor2(350.f, 50.f));
		Floor2->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//발판 충돌 사이즈 값
		AddObject(Floor2, GROUP_TYPE::FLOOR);
	}

	/// 사다리
	for(int i = 0 ; i < 2 ; i++)
	{
		CLadder* Ladder1 = nullptr;
		Ladder1 = new CLadder;
		Ladder1->SetName(L"Ladder1");
		Ladder1->SetPos(Vecor2(400.f, 500.f+450*i));	 // 사다리의 포지션
		Ladder1->SetScale(Vecor2(20.f, 450.f));	 // 스케일크기
		Ladder1->GetCollider()->SetScale(Vecor2(20.f, 500.f));	// 충돌 사이즈 값
		AddObject(Ladder1, GROUP_TYPE::LADDER);
	}


	FishButton* FishButton1 = nullptr;
	FishButton1 = new FishButton;
	FishButton1->SetName(L"FishButton");
	FishButton1->SetPos(Vecor2(1630.f + 100.f, 500.f)); // 물고기 버튼의 위치
	FishButton1->SetScale(Vecor2(20.f, 50.f));	//스케일크키
	FishButton1->GetCollider()->SetScale(Vecor2(20.f, 50.f));	// 충돌 사이즈 값
	AddObject(FishButton1, GROUP_TYPE::FISHBUTTON);


	GoToNextScene* GoToNextScene1 = nullptr;
	GoToNextScene1 = new GoToNextScene;
	GoToNextScene1->SetName(L"GoToNextScene");					///다음 씬으로 가기위한 투명한..무언가
	GoToNextScene1->SetPos(Vecor2(350.f * 6.f  +150.f + 150.f, 700.f));			// 벽의 포지션
	GoToNextScene1->SetScale(Vecor2(50.f, 1000.f));		// 스케일크기를 조절할 수 있다.
	GoToNextScene1->GetCollider()->SetScale(Vecor2(50.f, 1000.f));	// 충돌 사이즈 값
	AddObject(GoToNextScene1, GROUP_TYPE::GOTONEXTSCENE);


	///-----------------------------------------------------------------------------------------

	// 충돌 지정
	// 플레이어와 발판 그룹 간의 충돌 체크
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
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::FISH, GROUP_TYPE::DOOR);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::FISH, GROUP_TYPE::FISHBUTTON);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::FISH, GROUP_TYPE::FAKE);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::ROCK, GROUP_TYPE::FLOOR);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::ROCK, GROUP_TYPE::WALL);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::ROCK, GROUP_TYPE::DOORBUTTON);

}

void Stage1::Exit()
{
	DeleteAll();
	// 충돌 체크 한 것을 해제한다.
	CCollisionManager::GetInstance()->Reset();

}