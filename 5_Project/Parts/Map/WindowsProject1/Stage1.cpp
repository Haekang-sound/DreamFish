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
		CSceneManager::GetInstance()->ChangeScene(SCENE_TYPE::STAGE_02);
	}



	if (KEY_TAP(KEY::ESC))
	{
		// ���� ���� Object �߰�
		CButtonQuit* quit = nullptr;
		quit = new CButtonQuit;
		quit->SetPos(Vecor2(300.f, 200.f));
		quit->SetScale(Vecor2(200.f, 50.f));
		AddObject(quit, GROUP_TYPE::GAMEQUIT);

// 		// ���� ���� Object �߰�
// 		CButtonStart* Start = nullptr;
// 		Start = new CButtonStart;
// 		Start->SetPos(Vecor2(200.f, 100.f));
// 		Start->SetScale(Vecor2(200.f, 50.f));
// 		AddObject(Start, GROUP_TYPE::GAMESTART);

		// Ÿ��Ʋ ȭ�� Object �߰�
		CButtonTitle* title = nullptr;
		title = new CButtonTitle;
		title->SetPos(Vecor2(200.f, 100.f));
		title->SetScale(Vecor2(200.f, 50.f));
		AddObject(title, GROUP_TYPE::GAMETITLE);
	}

}

void Stage1::Enter()
{

	// Object �߰�		
	CObject* pBack = new CBackGround;			///�̰� �ǹ��ϴ� �ٰ� ����?
	pBack->SetPos(Vecor2(0.f, 0.f));
	pBack->SetScale(Vecor2(100.f, 100.f));
	AddObject(pBack, GROUP_TYPE::DEFALUT);

	//�����߰�
	CObject* fish = new CFish;					///���콺�� �̵��� ������ ������ �����.
	fish->SetPos(Vecor2(1000.f, 400.f));
	fish->SetName(L"FISH");
	fish->SetScale(Vecor2(100.f, 100.f));
	AddObject(fish, GROUP_TYPE::FISH);

	//PLAYER �߰�
	CPlayer* pObj = new CPlayer;				///WASD�� �̵��� ������ �÷��̾ �����
	pObj->SetName(L"PLAYER");
	pObj->SetPos(Vecor2(150.f, 150.f));
	pObj->SetScale(Vecor2(100.f, 100.f));
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
	CWall* WallL = nullptr;
	WallL = new CWall;
	WallL->SetName(L"Wall");					///���ʺ�
	WallL->SetPos(Vecor2(0.f, 400.f));			// ���� ������
	WallL->SetScale(Vecor2(50.f, 800.f));		// ������ũ�⸦ ������ �� �ִ�.
	WallL->GetCollider()->SetScale(Vecor2(50.f, 800.f));	//���� �浹 ������ ��
	AddObject(WallL, GROUP_TYPE::WALL);

	CWall* WallR1 = nullptr;
	WallR1 = new CWall;
	WallR1->SetName(L"Wall");					///������ ��1
	WallR1->SetPos(Vecor2(1600.f, 100.f));			// ���� ������
	WallR1->SetScale(Vecor2(50.f, 200.f));		// ������ũ�⸦ ������ �� �ִ�.
	WallR1->GetCollider()->SetScale(Vecor2(50.f, 200.f));	// �浹 ������ ��
	AddObject(WallR1, GROUP_TYPE::WALL);

	CWall* WallR2 = nullptr;
	WallR2 = new CWall;
	WallR2->SetName(L"Wall");					///������ ��2
	WallR2->SetPos(Vecor2(1600.f, 500.f));			// ���� ������
	WallR2->SetScale(Vecor2(50.f, 300.f));		// ������ũ�⸦ ������ �� �ִ�.
	WallR2->GetCollider()->SetScale(Vecor2(50.f, 300.f));	// �浹 ������ ��
	AddObject(WallR2, GROUP_TYPE::WALL);	
	
	CWall* WallUp = nullptr;
	WallUp = new CWall;
	WallUp->SetName(L"Wall");					///���� ��
	WallUp->SetPos(Vecor2(800.f, 0.f));			// ���� ������
	WallUp->SetScale(Vecor2(1650.f, 50.f));		// ������ũ�⸦ ������ �� �ִ�.
	WallUp->GetCollider()->SetScale(Vecor2(1650.f, 50.f));	// �浹 ������ ��
	AddObject(WallUp, GROUP_TYPE::WALL);

	FishDoor* FishDoor1 = nullptr;
	FishDoor1 = new FishDoor;
	FishDoor1->SetName(L"Door");					///��
	FishDoor1->SetPos(Vecor2(1600.f, 700.f));			// ���� ������
	FishDoor1->SetScale(Vecor2(50.f, 200.f));		// ������ũ�⸦ ������ �� �ִ�.
	FishDoor1->GetCollider()->SetScale(Vecor2(50.f, 200.f));	// �浹 ������ ��
	AddObject(FishDoor1, GROUP_TYPE::DOOR);

	//�ٴ��� ����
	Floor* Floor1 = nullptr;
	Floor1 = new Floor;
	Floor1->SetName(L"FLOOR1");
	Floor1->SetPos(Vecor2(1040.f, 800.f)); ///�ٴ��� ����
	Floor1->SetScale(Vecor2(2130.f, 50.f));
	Floor1->GetCollider()->SetScale(Vecor2(2130.f, 50.f));	//���� �浹 ������ ��
	AddObject(Floor1, GROUP_TYPE::FLOOR);

 	//2�� �ٴ��� ����
 	Floor* Floor2 = nullptr;
 	Floor2 = new Floor;
 	Floor2->SetName(L"FLOOR2");
 	Floor2->SetPos(Vecor2(300.f, 300.f)); // 2�� �ٴ��� ����
 	Floor2->SetScale(Vecor2(600.f, 50.f));
	Floor2->GetCollider()->SetScale(Vecor2(600.f, 50.f));	//���� �浹 ������ ��
 	AddObject(Floor2, GROUP_TYPE::FLOOR);

	CLadder* Ladder1 = nullptr;
	Ladder1 = new CLadder;
	Ladder1->SetName(L"Ladder1");
	Ladder1->SetPos(Vecor2(400.f, 500.f));	 // ��ٸ��� ������
	Ladder1->SetScale(Vecor2(20.f, 500.f));	 // ������ũ��
	Ladder1->GetCollider()->SetScale(Vecor2(20.f, 500.f));	// �浹 ������ ��
	AddObject(Ladder1, GROUP_TYPE::LADDER);


	// ���� ��ġ
	CRock* Rock1 = nullptr;
	Rock1 = new CRock;
	Rock1->SetName(L"Rock");
	Rock1->SetPos(Vecor2(300.f, 200.f)); // ������ ��ġ
	Rock1->SetScale(Vecor2(50.f, 50.f));
	AddObject(Rock1, GROUP_TYPE::ROCK);

	FishButton* FishButton1 = nullptr;
	FishButton1 = new FishButton;
	FishButton1->SetName(L"FishButton");
	FishButton1->SetPos(Vecor2(1630.f, 500.f)); // ����� ��ư�� ��ġ
	FishButton1->SetScale(Vecor2(20.f, 50.f));	//������ũŰ
	FishButton1->GetCollider()->SetScale(Vecor2(20.f, 50.f));	// �浹 ������ ��
	AddObject(FishButton1, GROUP_TYPE::FISHBUTTON);

	Shark* Shark1 = nullptr;
	Shark1 = new Shark;
	Shark1->SetName(L"Shark");
	Shark1->SetPos(Vecor2(100.f, 500.f)); //����� ��ġ
	Shark1->SetScale(Vecor2(300.f, 100.f));	//��� ũŰ
	Shark1->GetCollider()->SetScale(Vecor2(300.f, 50.f));	// ��� �浹 ������ ��
	AddObject(Shark1, GROUP_TYPE::MONSTER);



	GoToNextScene* GoToNextScene1 = nullptr;
	GoToNextScene1 = new GoToNextScene;
	GoToNextScene1->SetName(L"GoToNextScene");					///���� ������ �������� ������..����
	GoToNextScene1->SetPos(Vecor2(2000.f, 700.f));			// ���� ������
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
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::DOORBUTTON);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::GOTONEXTSCENE);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::FISH, GROUP_TYPE::WALL);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::FISH, GROUP_TYPE::FISHBUTTON);
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