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
#include "SeaUr.h"		//������


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
	// SCEEN Ʃ�丮�󿡼� > START�Ѿ�Բ� �ϱ�?
	CScene::Update();

	if (KEY_TAP(KEY::ENTER))
	{
		CSceneManager::GetInstance()->ChangeScene(SCENE_TYPE::STAGE_01);
	}
	if (KEY_AWAY(KEY::ESC))
	{
		pause = !pause; // �Ͻ����� ���¸� ���
	}

	if (pause)
	{
		// ���� ���� Object �߰�
		CButtonQuit* quit = nullptr;
		quit = new CButtonQuit;
		quit->SetPos(Vecor2(300.f, 200.f));
		quit->SetScale(Vecor2(200.f, 50.f));
		AddObject(quit, GROUP_TYPE::GAMEQUIT);



		// Ÿ��Ʋ ȭ�� Object �߰�
		CButtonTitle* title = nullptr;
		title = new CButtonTitle;
		title->SetPos(Vecor2(200.f, 100.f));
		title->SetScale(Vecor2(200.f, 50.f));
		AddObject(title, GROUP_TYPE::GAMETITLE);
	}
	else if (!pause)
	{
		// ���� ���� ��ư ����
		DeleteGroup(GROUP_TYPE::GAMEQUIT);
		DeleteGroup(GROUP_TYPE::GAMETITLE);
	}

}

void Stage1::Enter()
{
	SetCursorPos(1600, 800);
	
	// Object �߰�		
	CBackGround* pBack = new CBackGround;			///�̰� �ǹ��ϴ� �ٰ� ����?
	pBack->SetPos(Vecor2(0.f, 0.f));
	pBack->SetTexture(L"Stage1_Left", L"texture\\1stageLeft.bmp");
	pBack->SetSize(1725, 1150);
	//pBack->SetScale(Vecor2(100.f, 100.f));
	AddObject(pBack, GROUP_TYPE::DEFALUT);

	CBackGround* pBack2 = new CBackGround;			///�̰� �ǹ��ϴ� �ٰ� ����?
	pBack2->SetPos(Vecor2(1725.f, 0.f));
	pBack2->SetTexture(L"Stage1_Right", L"texture\\1stageRight.bmp");
	pBack2->SetSize(700, 1150);
	//pBack->SetScale(Vecor2(100.f, 100.f));
	AddObject(pBack2, GROUP_TYPE::DEFALUT);

	//�����߰�
	CObject* fish = new CFish;					///���콺�� �̵��� ������ ������ �����.
	fish->SetPos(Vecor2(1600.f, 800.f));
	fish->SetName(L"FISH");
	fish->SetScale(Vecor2(100.f, 100.f));
	AddObject(fish, GROUP_TYPE::FISH);

	//PLAYER �߰�
	CPlayer* pObj = new CPlayer;				///WASD�� �̵��� ������ �÷��̾ �����
	pObj->SetName(L"PLAYER");
	pObj->SetPos(Vecor2(150.f, 150.f));
	//pObj->SetScale(Vecor2(100.f, 100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);

	//CPlayer*
	if (!pObj->IsDead()) {						///�÷��̾��� ��,���� �浹�� ������ �ϳ��� �ݶ��̴��� �����.
		PlayerWidth* pWidth = new PlayerWidth;
		pWidth->SetName(L"PLAYERWidth");
		pWidth->SetPos(Vecor2(150.f, 150.f));
		pWidth->SetScale(Vecor2(100.f, 100.f));
		pWidth->SetPlayer(pObj);
		AddObject(pWidth, GROUP_TYPE::PLAYER);
	}


	//ī�޶�
	Vecor2 vResolution = CGameProcess::GetInstance()->GetResolution();		///�÷��̾�� ����� ���̿� ��ġ�ϴ� ī�޶��̴�.
	CCamera::GetInstance()->SetLookAt(vResolution / 2.f);
	CCamera::GetInstance()->SetTarget(pObj, fish);

	///-------------------------------------------------------------------

		//����ġ
	for(int i = 1; i < 5 ; i++)
	{
		CWall* WallL = nullptr;
		WallL = new CWall;
		WallL->SetName(L"Wall");					///���ʺ�
		WallL->SetPos(Vecor2(-25.f, 300.f * i - 150.f-25.f));			// ���� ������
		WallL->SetScale(Vecor2(50.f, 300.f));		// ������ũ�⸦ ������ �� �ִ�.
		WallL->GetCollider()->SetScale(Vecor2(50.f, 300.f));	//���� �浹 ������ ��
		AddObject(WallL, GROUP_TYPE::WALL);
	}

	///��¥ ���ʺ� ������浹
	FakeWallLeftRight* FakeWall_L = nullptr;
	FakeWall_L = new FakeWallLeftRight;
	FakeWall_L->SetName(L"FakeLeft");					///���ʺ�
	FakeWall_L->SetPos(Vecor2(-25.f, 600.f));			// ���� ������
	//FakeWall_L->SetScale(Vecor2(50.f, 2000.f));		// ������ũ�⸦ ������ �� �ִ�.
	FakeWall_L->GetCollider()->SetScale(Vecor2(50.f, 2000.f));	//���� �浹 ������ ��
	AddObject(FakeWall_L, GROUP_TYPE::FAKE);


	CWall* WallR1 = nullptr;
	WallR1 = new CWall;
	WallR1->SetName(L"Wall");					///������ ��1
	WallR1->SetPos(Vecor2(1600.f+100.f, 100.f +25.f));			// ���� ������
	WallR1->SetScale(Vecor2(50.f, 300.f));		// ������ũ�⸦ ������ �� �ִ�.
	WallR1->GetCollider()->SetScale(Vecor2(50.f, 200.f));	// �浹 ������ ��
	AddObject(WallR1, GROUP_TYPE::WALL);


	for(int i = 0 ; i < 2 ; i++)
	{
		CWall* WallR2 = nullptr;
		WallR2 = new CWall;
		WallR2->SetName(L"Wall");					///������ ��2
		WallR2->SetPos(Vecor2(1600.f + 100.f, 500.f+i*300.f-20.f));			// ���� ������
		WallR2->SetScale(Vecor2(50.f, 300.f));		// ������ũ�⸦ ������ �� �ִ�.
		WallR2->GetCollider()->SetScale(Vecor2(50.f, 300.f));	// �浹 ������ ��
		AddObject(WallR2, GROUP_TYPE::WALL);
	}
	
	///��¥ �����ʺ� ������浹
	FakeWallLeftRight* FakeWall_R = nullptr;
	FakeWall_R = new FakeWallLeftRight;
	FakeWall_R->SetName(L"FakeRight");					///������ ��
	FakeWall_R->SetPos(Vecor2(2000.f, 600.f));			// ���� ������
	//FakeWall_R->SetScale(Vecor2(50.f, 2000.f));		// ������ũ�⸦ ������ �� �ִ�.
	FakeWall_R->GetCollider()->SetScale(Vecor2(50.f, 2000.f));	//���� �浹 ������ ��
	AddObject(FakeWall_R, GROUP_TYPE::FAKE);




	FishDoor* FishDoor1 = nullptr;
	FishDoor1 = new FishDoor;
	FishDoor1->SetName(L"Door");					///��
	FishDoor1->SetPos(Vecor2(1600.f + 100.f, 1025.f));			// ���� ������
	FishDoor1->SetScale(Vecor2(20.f, 200.f));		// ������ũ�⸦ ������ �� �ִ�.
	FishDoor1->GetCollider()->SetScale(Vecor2(20.f, 200.f));	// �浹 ������ ��
	AddObject(FishDoor1, GROUP_TYPE::DOOR);

	//�ٴ��� ����
	for(int i = 0 ; i < 7 ; i++)
	{
		Floor* Floor1 = nullptr;
		Floor1 = new Floor;
		Floor1->SetName(L"FLOOR1");
		Floor1->SetPos(Vecor2(350.f * i +150.f, 1200.f -50.f)); ///�ٴ��� ����
		Floor1->SetScale(Vecor2(350.f, 50.f));
		Floor1->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//���� �浹 ������ ��
		AddObject(Floor1, GROUP_TYPE::FLOOR);
	}
	
	///��¥ �ٴ����� ����
	FakeWallUpDown* FakeFloor1 = nullptr;
	FakeFloor1 = new FakeWallUpDown;
	FakeFloor1->SetName(L"FakeDown");
	FakeFloor1->SetPos(Vecor2(1200.f, 1150.f)); ///�ٴ��� ����
	//FakeFloor1->SetScale(Vecor2(4000.f, 50.f));
	FakeFloor1->GetCollider()->SetScale(Vecor2(4000.f, 50.f));	//���� �浹 ������ ��
	AddObject(FakeFloor1, GROUP_TYPE::FAKE);


	/*------------------ ��� �ٴ� �ƴϳ�??? ---------------------------------------*/
	for(int i = 0 ; i < 5 ; i++)
	{
		Floor* Floor3 = nullptr;
		Floor3 = new Floor;
		Floor3->SetName(L"FLOOR3");					///���� ��
		Floor3->SetPos(Vecor2(350.f * i+150.f, 0.f));			// ���� ������
		Floor3->SetScale(Vecor2(350.f , 50.f));		// ������ũ�⸦ ������ �� �ִ�.
		Floor3->GetCollider()->SetScale(Vecor2(350.f, 50.f));	// �浹 ������ ��
		AddObject(Floor3, GROUP_TYPE::FLOOR);
	}
	/*---------------------------------------------------------------------------*/
	
	///��¥õ��
	FakeWallUpDown* FakeFloor2 = nullptr;
	FakeFloor2= new FakeWallUpDown;
	FakeFloor2->SetName(L"FakeUP");
	FakeFloor2->SetPos(Vecor2(1200.f, 0.f)); ///õ���� ����
	//FakeFloor2->SetScale(Vecor2(4000.f, 50.f));
	FakeFloor2->GetCollider()->SetScale(Vecor2(4000.f, 50.f));	//���� �浹 ������ ��
	AddObject(FakeFloor2, GROUP_TYPE::FAKE);

 	//2�� �ٴ��� ����
	for(float i = 0 ; i < 2 ; i++)
	{
		Floor* Floor2 = nullptr;
		Floor2 = new Floor;
		Floor2->SetName(L"FLOOR2");
		Floor2->SetPos(Vecor2(350.f*i+150.f, 300.f)); // 2�� �ٴ��� ����
		//Floor2->SetScale(Vecor2(350.f, 50.f));
		Floor2->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//���� �浹 ������ ��
		AddObject(Floor2, GROUP_TYPE::FLOOR);
	}

	/// ��ٸ�
	for(int i = 0 ; i < 2 ; i++)
	{
		CLadder* Ladder1 = nullptr;
		Ladder1 = new CLadder;
		Ladder1->SetName(L"Ladder1");
		Ladder1->SetPos(Vecor2(400.f, 500.f+450*i));	 // ��ٸ��� ������
		Ladder1->SetScale(Vecor2(20.f, 450.f));	 // ������ũ��
		Ladder1->GetCollider()->SetScale(Vecor2(20.f, 500.f));	// �浹 ������ ��
		AddObject(Ladder1, GROUP_TYPE::LADDER);
	}


	FishButton* FishButton1 = nullptr;
	FishButton1 = new FishButton;
	FishButton1->SetName(L"FishButton");
	FishButton1->SetPos(Vecor2(1630.f + 100.f, 500.f)); // ����� ��ư�� ��ġ
	FishButton1->SetScale(Vecor2(20.f, 50.f));	//������ũŰ
	FishButton1->GetCollider()->SetScale(Vecor2(20.f, 50.f));	// �浹 ������ ��
	AddObject(FishButton1, GROUP_TYPE::FISHBUTTON);


	GoToNextScene* GoToNextScene1 = nullptr;
	GoToNextScene1 = new GoToNextScene;
	GoToNextScene1->SetName(L"GoToNextScene");					///���� ������ �������� ������..����
	GoToNextScene1->SetPos(Vecor2(350.f * 6.f  +150.f + 150.f, 700.f));			// ���� ������
	GoToNextScene1->SetScale(Vecor2(50.f, 1000.f));		// ������ũ�⸦ ������ �� �ִ�.
	GoToNextScene1->GetCollider()->SetScale(Vecor2(50.f, 1000.f));	// �浹 ������ ��
	AddObject(GoToNextScene1, GROUP_TYPE::GOTONEXTSCENE);


	///-----------------------------------------------------------------------------------------

	// �浹 ����
	// �÷��̾�� ���� �׷� ���� �浹 üũ
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
	// �浹 üũ �� ���� �����Ѵ�.
	CCollisionManager::GetInstance()->Reset();

}