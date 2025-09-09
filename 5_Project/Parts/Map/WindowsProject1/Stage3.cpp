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
		CSceneManager::GetInstance()->ChangeScene(SCENE_TYPE::STAGE_02);
	}
}

void Stage3::Enter()
{
	// Object 추가		
	CObject* pBack = new CBackGround;			///이게 의미하는 바가 뭐지?
	pBack->SetPos(Vecor2(0.f, 0.f));
	pBack->SetScale(Vecor2(100.f, 100.f));
	AddObject(pBack, GROUP_TYPE::DEFALUT);

	//생선추가
	CObject* fish = new CFish;					///마우스로 이동이 가능한 생선을 만든다.
	fish->SetPos(Vecor2(100.f, 400.f));
	fish->SetScale(Vecor2(100.f, 100.f));
	AddObject(fish, GROUP_TYPE::FISH);

	//PLAYER 추가
	CPlayer* pObj = new CPlayer;				///WASD로 이동이 가능한 플레이어를 만든다
	pObj->SetName(L"PLAYER");
	pObj->SetPos(Vecor2(2800.f, 800.f));
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

	CWall* WallL = nullptr;
	WallL = new CWall;
	WallL->SetName(L"Wall");					///왼쪽벽
	WallL->SetPos(Vecor2(0.f, 400.f));			// 벽의 포지션
	WallL->SetScale(Vecor2(50.f, 2550.f));		// 스케일크기를 조절할 수 있다.
	WallL->GetCollider()->SetScale(Vecor2(50.f, 2550.f));	//발판 충돌 사이즈 값
	AddObject(WallL, GROUP_TYPE::WALL);

	CWall* WallR = nullptr;
	WallR = new CWall;
	WallR->SetName(L"Wall");					///오른쪽 벽1
	WallR->SetPos(Vecor2(3000.f, 400.f));			// 벽의 포지션
	WallR->SetScale(Vecor2(50.f, 2550.f));		// 스케일크기를 조절할 수 있다.
	WallR->GetCollider()->SetScale(Vecor2(50.f, 2550.f));	// 충돌 사이즈 값
	AddObject(WallR, GROUP_TYPE::WALL);

	CWall* WallUp = nullptr;
	WallUp = new CWall;
	WallUp->SetName(L"Wall");					///위쪽 벽
	WallUp->SetPos(Vecor2(800.f, 0.f));			// 벽의 포지션
	WallUp->SetScale(Vecor2(1650.f, 50.f));		// 스케일크기를 조절할 수 있다.
	WallUp->GetCollider()->SetScale(Vecor2(1650.f, 50.f));	// 충돌 사이즈 값
	AddObject(WallUp, GROUP_TYPE::WALL);

	/// 중간 바닥
	Floor* Floor1 = nullptr;
	Floor1 = new Floor;
	Floor1->SetName(L"FLOOR1");
	Floor1->SetPos(Vecor2(1500.f, 900.f)); // 바닥의 중점
	Floor1->SetScale(Vecor2(3050.f, 50.f));
	Floor1->GetCollider()->SetScale(Vecor2(3050.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(Floor1, GROUP_TYPE::FLOOR);

	/// 사다리1 , 플랫폼 1, 사다리 2, 돌
	CLadder* Ladder1 = nullptr;
	Ladder1 = new CLadder;
	Ladder1->SetName(L"Ladder1");
	Ladder1->SetPos(Vecor2(2300.f, 640.f));	 // 사다리의 포지션
	Ladder1->SetScale(Vecor2(60.f, 470.f));	 // 스케일크기
	Ladder1->GetCollider()->SetScale(Vecor2(60.f, 470.f));	// 충돌 사이즈 값
	AddObject(Ladder1, GROUP_TYPE::LADDER);

	Floor* Floor3 = nullptr;
	Floor3 = new Floor;
	Floor3->SetName(L"FLOOR2");
	Floor3->SetPos(Vecor2(1850.f, 440.f)); //바닥의 중점
	Floor3->SetScale(Vecor2(1000.f, 50.f));
	Floor3->GetCollider()->SetScale(Vecor2(1000.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(Floor3, GROUP_TYPE::FLOOR);

	CLadder* Ladder2 = nullptr;
	Ladder2 = new CLadder;
	Ladder2->SetName(L"Ladder1");
	Ladder2->SetPos(Vecor2(1400.f, 640.f));	 // 사다리의 포지션
	Ladder2->SetScale(Vecor2(60.f, 470.f));	 // 스케일크기
	Ladder2->GetCollider()->SetScale(Vecor2(60.f, 470.f));	// 충돌 사이즈 값
	AddObject(Ladder2, GROUP_TYPE::LADDER);

	/// 바위 (큰 돌) 배치
	CRock* Rock1 = nullptr;
	Rock1 = new CRock;
	Rock1->SetName(L"Rock");
	Rock1->SetPos(Vecor2(1650.f, 100.f)); // 바위의 위치
	Rock1->SetScale(Vecor2(170.f, 170.f));
	Rock1->GetCollider()->SetScale(Vecor2(170.f, 170.f));	// 충돌 사이즈 값
	AddObject(Rock1, GROUP_TYPE::ROCK);

	/// 도어 버튼
	DoorButton* doorButton1 = nullptr;
	doorButton1 = new DoorButton;
	doorButton1->SetName(L"DoorButton");
	doorButton1->SetPos(Vecor2(1250.f, 866.f));
	doorButton1->SetScale(Vecor2(50.f, 20.f));
	doorButton1->GetCollider()->SetScale(Vecor2(50.f, 20.f));
	AddObject(doorButton1, GROUP_TYPE::DOORBUTTON);

	/// 벽 문
	CWall* WallL1 = nullptr;
	WallL1 = new CWall;
	WallL1->SetName(L"Wall");					///왼쪽벽
	WallL1->SetPos(Vecor2(510.f, 350.f));			// 벽의 포지션
	WallL1->SetScale(Vecor2(50.f, 700.f));		// 스케일크기를 조절할 수 있다.
	WallL1->GetCollider()->SetScale(Vecor2(50.f, 700.f));	//발판 충돌 사이즈 값
	AddObject(WallL1, GROUP_TYPE::WALL);

	Door* door1 = nullptr;
	door1 = new Door;
	door1->SetName(L"DoorButton");
	door1->SetPos(Vecor2(510.f, 777.f));
	door1->SetScale(Vecor2(50.f, 200.f));
	door1->GetCollider()->SetScale(Vecor2(50.f, 200.f));
	AddObject(door1, GROUP_TYPE::DOOR);

	/// stage4 이동
	GoToNextScene* GoToNextScene3 = nullptr;
	GoToNextScene3 = new GoToNextScene;
	GoToNextScene3->SetName(L"GoToNextScene");					///다음 씬으로 가기위한 투명한..무언가
	GoToNextScene3->SetPos(Vecor2(100.f, 840.f));			// 벽의 포지션
	GoToNextScene3->SetScale(Vecor2(50.f, 1000.f));		// 스케일크기를 조절할 수 있다.
	GoToNextScene3->GetCollider()->SetScale(Vecor2(50.f, 1000.f));	// 충돌 사이즈 값
	AddObject(GoToNextScene3, GROUP_TYPE::GOTONEXTSCENE);

	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::ROCK);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::FLOOR);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::LADDER);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::WALL);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::DOOR);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::FISH, GROUP_TYPE::WALL);
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
