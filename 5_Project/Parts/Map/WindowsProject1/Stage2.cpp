#include "pch.h"
#include "Stage2.h"

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

Stage2::Stage2()
{

}

Stage2::~Stage2()
{

}

void Stage2::Update()
{
	CScene::Update();

	if (KEY_TAP(KEY::ENTER))
	{
		CSceneManager::GetInstance()->ChangeScene(SCENE_TYPE::STAGE_03);
	}
}

void Stage2::Enter()
{
	// Object 추가		
	CObject* pBack = new CBackGround;			///이게 의미하는 바가 뭐지?
	pBack->SetPos(Vecor2(0.f, 0.f));
	pBack->SetScale(Vecor2(100.f, 100.f));
	AddObject(pBack, GROUP_TYPE::DEFALUT);

	//생선추가
	CObject* fish = new CFish;					///마우스로 이동이 가능한 생선을 만든다.
	fish->SetPos(Vecor2(800.f, 800.f));
	fish->SetScale(Vecor2(100.f, 100.f));
	AddObject(fish, GROUP_TYPE::FISH);

	//PLAYER 추가
	CPlayer* pObj = new CPlayer;				///WASD로 이동이 가능한 플레이어를 만든다
	pObj->SetName(L"PLAYER");
	pObj->SetPos(Vecor2(90.f, 1600.f));
	pObj->SetScale(Vecor2(100.f, 100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);

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

	CWall* WallR1 = nullptr;
	WallR1 = new CWall;
	WallR1->SetName(L"Wall");					///오른쪽 벽1
	WallR1->SetPos(Vecor2(3000.f, 400.f));			// 벽의 포지션
	WallR1->SetScale(Vecor2(50.f, 2550.f));		// 스케일크기를 조절할 수 있다.
	WallR1->GetCollider()->SetScale(Vecor2(50.f, 2550.f));	// 충돌 사이즈 값
	AddObject(WallR1, GROUP_TYPE::WALL);



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
	Floor1->SetName(L"FLOOR2");
	Floor1->SetPos(Vecor2(1500.f, 900.f)); // 바닥의 중점
	Floor1->SetScale(Vecor2(3050.f, 50.f));
	Floor1->GetCollider()->SetScale(Vecor2(3050.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(Floor1, GROUP_TYPE::FLOOR);

	/// 맨 밑 바닥
	Floor* Floor2 = nullptr;
	Floor2 = new Floor;
	Floor2->SetName(L"FLOOR1");
	Floor2->SetPos(Vecor2(1500.f, 1700.f)); // 바닥의 중점
	Floor2->SetScale(Vecor2(3050.f, 50.f));
	Floor2->GetCollider()->SetScale(Vecor2(3050.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(Floor2, GROUP_TYPE::FLOOR);

	/// 사다리1 , 플랫폼 1
	CLadder* Ladder1 = nullptr;
	Ladder1 = new CLadder;
	Ladder1->SetName(L"Ladder1");
	Ladder1->SetPos(Vecor2(850.f, 1440.f));	 // 사다리의 포지션
	Ladder1->SetScale(Vecor2(20.f, 470.f));	 // 스케일크기
	Ladder1->GetCollider()->SetScale(Vecor2(20.f, 470.f));	// 충돌 사이즈 값
	AddObject(Ladder1, GROUP_TYPE::LADDER);

	Floor* Floor3 = nullptr;
	Floor3 = new Floor;
	Floor3->SetName(L"FLOOR2");
	Floor3->SetPos(Vecor2(950.f, 1240.f)); //바닥의 중점
	Floor3->SetScale(Vecor2(250.f, 50.f));
	Floor3->GetCollider()->SetScale(Vecor2(250.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(Floor3, GROUP_TYPE::FLOOR);

	/// 가로막는 성게 오브젝트를 여기다가..!


	/// 사다리2, 플랫폼 2
	Floor* Floor4 = nullptr;
	Floor4 = new Floor;
	Floor4->SetName(L"FLOOR2");
	Floor4->SetPos(Vecor2(1450.f, 1240.f)); //바닥의 중점
	Floor4->SetScale(Vecor2(350.f, 50.f));
	Floor4->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(Floor4, GROUP_TYPE::FLOOR);

	CLadder* Ladder2 = nullptr;
	Ladder2 = new CLadder;
	Ladder2->SetName(L"Ladder1");
	Ladder2->SetPos(Vecor2(1600.f, 1440.f));	 // 사다리의 포지션
	Ladder2->SetScale(Vecor2(20.f, 470.f));	 // 스케일크기
	Ladder2->GetCollider()->SetScale(Vecor2(20.f, 470.f));	// 충돌 사이즈 값
	AddObject(Ladder2, GROUP_TYPE::LADDER);

	/// 계단 플랫폼
	Floor* Floor5 = nullptr;
	Floor5 = new Floor;
	Floor5->SetName(L"FLOOR2");
	Floor5->SetPos(Vecor2(2400.f, 1640.f)); //바닥의 중점
	Floor5->SetScale(Vecor2(350.f, 50.f));
	Floor5->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(Floor5, GROUP_TYPE::FLOOR);

	Floor* Floor6 = nullptr;
	Floor6 = new Floor;
	Floor6->SetName(L"FLOOR2");
	Floor6->SetPos(Vecor2(2600.f, 1540.f)); //바닥의 중점
	Floor6->SetScale(Vecor2(350.f, 50.f));
	Floor6->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(Floor6, GROUP_TYPE::FLOOR);

	Floor* Floor7 = nullptr;
	Floor7 = new Floor;
	Floor7->SetName(L"FLOOR3");
	Floor7->SetPos(Vecor2(2800.f, 1440.f)); //바닥의 중점
	Floor7->SetScale(Vecor2(350.f, 50.f));
	Floor7->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(Floor7, GROUP_TYPE::FLOOR);

	// Floor* Floor8 = nullptr;
	// Floor8 = new Floor;
	// Floor8->SetName(L"FLOOR1");
	// Floor8->SetPos(Vecor2(2800.f, 1300.f)); //바닥의 중점
	// Floor8->SetScale(Vecor2(5.f, 5.f));
	// Floor8->GetCollider()->SetScale(Vecor2(1.f, 1.f));	//발판 충돌 사이즈 값
	// AddObject(Floor8, GROUP_TYPE::FLOOR);

	/// 중간 바닥으로 가는 사다리 플랫폼
	CLadder* Ladder3 = nullptr;
	Ladder3 = new CLadder;
	Ladder3->SetName(L"Ladder1");
	Ladder3->SetPos(Vecor2(2800.f, 1100.f));	 // 사다리의 포지션
	Ladder3->SetScale(Vecor2(20.f, 550.f));	 // 스케일크기
	Ladder3->GetCollider()->SetScale(Vecor2(20.f, 550.f));	// 충돌 사이즈 값
	AddObject(Ladder3, GROUP_TYPE::LADDER);


	/// 사다리 3, 플랫폼 4 (보류)
	Floor* Floor9 = nullptr;
	Floor9 = new Floor;
	Floor9->SetName(L"FLOOR2");
	Floor9->SetPos(Vecor2(850.f, 440.f)); //바닥의 중점
	Floor9->SetScale(Vecor2(450.f, 50.f));
	Floor9->GetCollider()->SetScale(Vecor2(450.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(Floor9, GROUP_TYPE::FLOOR);

	Floor* Floor10 = nullptr;
	Floor10 = new Floor;
	Floor10->SetName(L"FLOOR2");
	Floor10->SetPos(Vecor2(1450.f, 440.f)); //바닥의 중점
	Floor10->SetScale(Vecor2(350.f, 50.f));
	Floor10->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(Floor10, GROUP_TYPE::FLOOR);

	CLadder* Ladder4 = nullptr;
	Ladder4 = new CLadder;
	Ladder4->SetName(L"Ladder1");
	Ladder4->SetPos(Vecor2(1600.f, 640.f));	 // 사다리의 포지션
	Ladder4->SetScale(Vecor2(20.f, 470.f));	 // 스케일크기
	Ladder4->GetCollider()->SetScale(Vecor2(20.f, 470.f));	// 충돌 사이즈 값
	AddObject(Ladder4, GROUP_TYPE::LADDER);

	Floor* Floor11 = nullptr;
	Floor11 = new Floor;
	Floor11->SetName(L"FLOOR3");
	Floor11->SetPos(Vecor2(1600.f, 900.f)); //바닥의 중점
	Floor11->SetScale(Vecor2(100.f, 50.f));
	Floor11->GetCollider()->SetScale(Vecor2(100.f, 50.f));	//발판 충돌 사이즈 값
	AddObject(Floor11, GROUP_TYPE::FLOOR);

	/// 짐덩이 (길막)

	/// 다음 스테이지 ㄴ



	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::ROCK);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::FLOOR);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::LADDER);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::WALL);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::DOOR);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::FISH, GROUP_TYPE::WALL);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::ROCK, GROUP_TYPE::FLOOR);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::ROCK, GROUP_TYPE::WALL);
}


void Stage2::Exit()
{
	DeleteAll();

	// 충돌 체크 한 것을 해제한다.
	CCollisionManager::GetInstance()->Reset();
}

