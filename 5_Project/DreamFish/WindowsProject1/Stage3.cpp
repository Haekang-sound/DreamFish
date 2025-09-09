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

void Stage3::Enter()
{
	// Object �߰�		
	CBackGround* pBack = new CBackGround;			///�̰� �ǹ��ϴ� �ٰ� ����?
	pBack->SetPos(Vecor2(0.f, 0.f));
	pBack->SetTexture(L"Stage3_Left", L"texture\\3stageLeft.bmp");
	pBack->SetSize(510, 875);
	//pBack->SetScale(Vecor2(100.f, 100.f));
	AddObject(pBack, GROUP_TYPE::DEFALUT);

	CBackGround* pBack2 = new CBackGround;			///�̰� �ǹ��ϴ� �ٰ� ����?
	pBack2->SetPos(Vecor2(510.f, 0.f));
	pBack2->SetTexture(L"Stage3_Right", L"texture\\3stageRight.bmp");
	pBack2->SetSize(2590, 875);
	//pBack->SetScale(Vecor2(100.f, 100.f));
	AddObject(pBack2, GROUP_TYPE::DEFALUT);

	//�����߰�
	CObject* fish = new CFish;					///���콺�� �̵��� ������ ������ �����.
	fish->SetPos(Vecor2(1000.f, 400.f));
	fish->SetScale(Vecor2(100.f, 100.f));
	AddObject(fish, GROUP_TYPE::FISH);

	//PLAYER �߰�
	CPlayer* pObj = new CPlayer;				///WASD�� �̵��� ������ �÷��̾ �����
	pObj->SetName(L"PLAYER");
	pObj->SetPos(Vecor2(3000.f, 750.f));
	pObj->SetScale(Vecor2(100.f, 100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);

	//CPlayer*
	if (!pObj->IsDead()) 
	{											///�÷��̾��� ��,���� �浹�� ������ �ϳ��� �ݶ��̴��� �����.
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

	for (int i = 0; i < 3; i++)
	{
		CWall* WallL = nullptr;
		WallL = new CWall;
		WallL->SetName(L"Wall");					///���ʺ�
		WallL->SetPos(Vecor2(0.f, 300.f * i + 150.f));			// ���� ������
		WallL->SetScale(Vecor2(50.f, 300.f));		// ������ũ�⸦ ������ �� �ִ�.
		WallL->GetCollider()->SetScale(Vecor2(50.f, 300.f));	//���� �浹 ������ ��
		AddObject(WallL, GROUP_TYPE::WALL);
	}

	///��¥ ���ʺ� ������浹
	FakeWallLeftRight* FakeWall_L = nullptr;
	FakeWall_L = new FakeWallLeftRight;
	FakeWall_L->SetName(L"FakeLeft");					///���ʺ�
	FakeWall_L->SetPos(Vecor2(0.f, 600.f));			// ���� ������
//	FakeWall_L->SetScale(Vecor2(50.f, 2000.f));		// ������ũ�⸦ ������ �� �ִ�.
	FakeWall_L->GetCollider()->SetScale(Vecor2(50.f, 2000.f));	//���� �浹 ������ ��
	AddObject(FakeWall_L, GROUP_TYPE::FAKE);

	for (int i = 0; i < 3; i++)
	{
		CWall* WallR1 = nullptr;
		WallR1 = new CWall;
		WallR1->SetName(L"Wall");					///������ ��1
		WallR1->SetPos(Vecor2(3100.f, 300.f * i + 150.f));			// ���� ������
		WallR1->SetScale(Vecor2(50.f, 300.f));		// ������ũ�⸦ ������ �� �ִ�.
		WallR1->GetCollider()->SetScale(Vecor2(50.f, 300.f));	// �浹 ������ ��
		AddObject(WallR1, GROUP_TYPE::WALL);
	}

	///��¥ �����ʺ� ������浹
	FakeWallLeftRight* FakeWall_R = nullptr;
	FakeWall_R = new FakeWallLeftRight;
	FakeWall_R->SetName(L"FakeRight");					/// ������ ��
	FakeWall_R->SetPos(Vecor2(3100.f, 600.f));			// ���� ������
//	FakeWall_R->SetScale(Vecor2(50.f, 2000.f));		// ������ũ�⸦ ������ �� �ִ�.
	FakeWall_R->GetCollider()->SetScale(Vecor2(50.f, 2000.f));	//���� �浹 ������ ��
	AddObject(FakeWall_R, GROUP_TYPE::FAKE);

	for (int i = 0; i < 9; i++)
	{
		Floor* Floor3 = nullptr;
		Floor3 = new Floor;
		Floor3->SetName(L"Floor1");					///���� ��->�ٴ�
		Floor3->SetPos(Vecor2(350.f * i + 150.f, 0.f));			// ���� ������
		Floor3->SetScale(Vecor2(350.f, 50.f));		// ������ũ�⸦ ������ �� �ִ�.
		Floor3->GetCollider()->SetScale(Vecor2(350.f, 50.f));	// �浹 ������ ��
		AddObject(Floor3, GROUP_TYPE::WALL);
	}

	///��¥õ��
	FakeWallUpDown* FakeFloor2 = nullptr;
	FakeFloor2 = new FakeWallUpDown;
	FakeFloor2->SetName(L"FakeUP");
	FakeFloor2->SetPos(Vecor2(1200.f, 0.f)); ///õ���� ����
	//FakeFloor2->SetScale(Vecor2(4000.f, 50.f));
	FakeFloor2->GetCollider()->SetScale(Vecor2(4000.f, 50.f));	//���� �浹 ������ ��
	AddObject(FakeFloor2, GROUP_TYPE::FAKE);

	/// �� �� 
	for (int i = 0; i < 9; i++)
	{
		Floor* Floor2 = nullptr;
		Floor2 = new Floor;
		Floor2->SetName(L"FLOOR1");
		Floor2->SetPos(Vecor2(350.f * i + 150.f, 875.f)); // �ٴ��� ����
		Floor2->SetScale(Vecor2(350.f, 50.f));
		Floor2->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//���� �浹 ������ ��
		AddObject(Floor2, GROUP_TYPE::FLOOR);
	}

	FakeWallUpDown* FakeFloor1 = nullptr;
	FakeFloor1 = new FakeWallUpDown;
	FakeFloor1->SetName(L"FakeDown");
	FakeFloor1->SetPos(Vecor2(1200.f, 875.f)); ///�ٴ��� ����
//	FakeFloor1->SetScale(Vecor2(4000.f, 50.f));
	FakeFloor1->GetCollider()->SetScale(Vecor2(4000.f, 50.f));	//���� �浹 ������ ��
	AddObject(FakeFloor1, GROUP_TYPE::FAKE);


	///------------ ��ٸ� 2��------------- 
	CLadder* Ladder1 = nullptr;
	Ladder1 = new CLadder;
	Ladder1->SetName(L"Ladder1");
	Ladder1->SetPos(Vecor2(2300.f, 615.f));	 // ��ٸ��� ������
	Ladder1->SetScale(Vecor2(5.f, 450.f));	 // ������ũ��
	Ladder1->GetCollider()->SetScale(Vecor2(5.f, 450.f));	// �浹 ������ ��
	AddObject(Ladder1, GROUP_TYPE::LADDER);

	CLadder* Ladder2 = nullptr;
	Ladder2 = new CLadder;
	Ladder2->SetName(L"Ladder1");
	Ladder2->SetPos(Vecor2(1400.f, 615.f));	 // ��ٸ��� ������
	Ladder2->SetScale(Vecor2(5.f, 450.f));	 // ������ũ��
	Ladder2->GetCollider()->SetScale(Vecor2(5.f, 450.f));	// �浹 ������ ��
	AddObject(Ladder2, GROUP_TYPE::LADDER);

///---------------2������----------------
	Floor* Floor3 = nullptr;
	Floor3 = new Floor;
	Floor3->SetName(L"FLOOR2");
	Floor3->SetPos(Vecor2(1400.f, 415.f)); //�ٴ��� ����
	Floor3->SetScale(Vecor2(350.f, 50.f));
	Floor3->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//���� �浹 ������ ��
	AddObject(Floor3, GROUP_TYPE::FLOOR);

	Floor* Floor4 = nullptr;
	Floor4 = new Floor;
	Floor4->SetName(L"FLOOR2");
	Floor4->SetPos(Vecor2(1750.f, 415.f)); //�ٴ��� ����
	Floor4->SetScale(Vecor2(350.f, 50.f));
	Floor4->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//���� �浹 ������ ��
	AddObject(Floor4, GROUP_TYPE::FLOOR);

	Floor* Floor5 = nullptr;
	Floor5 = new Floor;
	Floor5->SetName(L"FLOOR2");
	Floor5->SetPos(Vecor2(2100.f, 415.f)); //�ٴ��� ����
	Floor5->SetScale(Vecor2(350.f, 50.f));
	Floor5->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//���� �浹 ������ ��
	AddObject(Floor5, GROUP_TYPE::FLOOR);

	Floor* Floor6 = nullptr;
	Floor6 = new Floor;
	Floor6->SetName(L"FLOOR2");
	Floor6->SetPos(Vecor2(2450.f, 415.f)); //�ٴ��� ����
	Floor6->SetScale(Vecor2(350.f, 50.f));
	Floor6->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//���� �浹 ������ ��

	AddObject(Floor6, GROUP_TYPE::FLOOR);

///-------------------------------������Ʈ



	/// ���� (ū ��) ��ġ
	CRock* Rock1 = nullptr;
	Rock1 = new CRock;
	Rock1->SetName(L"Rock");
	Rock1->SetPos(Vecor2(1650.f, 100.f)); // ������ ��ġ
	Rock1->SetScale(Vecor2(100.f, 270.f));
	Rock1->GetCollider()->SetScale(Vecor2(100.f, 270.f));	// �浹 ������ ��
	AddObject(Rock1, GROUP_TYPE::ROCK);

	/// ���� ��ư
	DoorButton* doorButton1 = nullptr;
	doorButton1 = new DoorButton;
	doorButton1->SetName(L"DoorButton");
	doorButton1->SetPos(Vecor2(1150.f, 841.f));
	doorButton1->SetScale(Vecor2(50.f, 20.f));
	doorButton1->GetCollider()->SetScale(Vecor2(50.f, 20.f));
	AddObject(doorButton1, GROUP_TYPE::DOORBUTTON);

///----------------------------------------���� ������ ��
	CWall* WallL1 = nullptr;
	WallL1 = new CWall;
	WallL1->SetName(L"Wall");					
	WallL1->SetPos(Vecor2(510.f, 200.f));			// ���� ������
	WallL1->SetScale(Vecor2(50.f, 300.f));		// ������ũ�⸦ ������ �� �ִ�.
	WallL1->GetCollider()->SetScale(Vecor2(50.f, 300.f));	//���� �浹 ������ ��
	AddObject(WallL1, GROUP_TYPE::WALL);

	CWall* WallL2 = nullptr;
	WallL2 = new CWall;
	WallL2->SetName(L"Wall");
	WallL2->SetPos(Vecor2(510.f, 500.f));			// ���� ������
	WallL2->SetScale(Vecor2(50.f, 300.f));		// ������ũ�⸦ ������ �� �ִ�.
	WallL2->GetCollider()->SetScale(Vecor2(50.f, 300.f));	//���� �浹 ������ ��
	AddObject(WallL2, GROUP_TYPE::WALL);

	/// �� ��
	Door* door1 = nullptr;
	door1 = new Door;
	door1->SetName(L"Door");
	door1->SetPos(Vecor2(510.f, 750.f));
	door1->SetScale(Vecor2(20.f, 200.f));
	door1->GetCollider()->SetScale(Vecor2(20.f, 200.f));
	AddObject(door1, GROUP_TYPE::DOOR);

	/// stage4 �̵�
	GoToNextScene* GoToNextScene3 = nullptr;
	GoToNextScene3 = new GoToNextScene;
	GoToNextScene3->SetName(L"GoToNextScene");					///���� ������ �������� ������..����
	GoToNextScene3->SetPos(Vecor2(100.f, 651.f));			// ���� ������
	GoToNextScene3->SetScale(Vecor2(50.f, 400.f));		// ������ũ�⸦ ������ �� �ִ�.
	GoToNextScene3->GetCollider()->SetScale(Vecor2(50.f, 400.f));	// �浹 ������ ��
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

	// �浹 üũ �� ���� �����Ѵ�.
	CCollisionManager::GetInstance()->Reset();
}
