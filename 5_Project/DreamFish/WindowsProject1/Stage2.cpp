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

		CSceneManager::GetInstance()->ChangeScene(SCENE_TYPE::STAGE_02);
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

void Stage2::Enter()
{
	// Object �߰�		
	CBackGround* pBack = new CBackGround;			///�̰� �ǹ��ϴ� �ٰ� ����?
	pBack->SetPos(Vecor2(0.f, 0.f));
	pBack->SetTexture(L"Stage2_Up", L"texture\\2stageUp.bmp");
	pBack->SetSize(3100, 900);
	//pBack->SetScale(Vecor2(100.f, 100.f));
	AddObject(pBack, GROUP_TYPE::DEFALUT);

	CBackGround* pBack2 = new CBackGround;			///�̰� �ǹ��ϴ� �ٰ� ����?
	pBack2->SetPos(Vecor2(0.f, 900.f));
	pBack2->SetTexture(L"Stage2_Down", L"texture\\2stageDown.bmp");
	pBack2->SetSize(3100, 875);
	//pBack->SetScale(Vecor2(100.f, 100.f));
	AddObject(pBack2, GROUP_TYPE::DEFALUT);

	//�����߰�
	CObject* fish = new CFish;					///���콺�� �̵��� ������ ������ �����.
	fish->SetPos(Vecor2(2500.f, 500.f));
	fish->SetScale(Vecor2(100.f, 100.f));
	AddObject(fish, GROUP_TYPE::FISH);

	//PLAYER �߰�
	CPlayer* pObj = new CPlayer;				///WASD�� �̵��� ������ �÷��̾ �����
	pObj->SetName(L"PLAYER");
	pObj->SetPos(Vecor2(90.f, 1600.f));
	pObj->SetScale(Vecor2(100.f, 100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);

	//ī�޶�
	Vecor2 vResolution = CGameProcess::GetInstance()->GetResolution();		///�÷��̾�� ����� ���̿� ��ġ�ϴ� ī�޶��̴�.
	CCamera::GetInstance()->SetLookAt(vResolution / 2.f);
	CCamera::GetInstance()->SetTarget(pObj, fish);

	/// �ʻ��� -----------------------------------------

	for (int i = 0; i < 6; i++)
	{
		CWall* WallL = nullptr;
		WallL = new CWall;
		WallL->SetName(L"Wall");					///���ʺ�
		WallL->SetPos(Vecor2(0.f, 300.f * i+150.f));			// ���� ������
		WallL->SetScale(Vecor2(50.f, 300.f));		// ������ũ�⸦ ������ �� �ִ�.
		WallL->GetCollider()->SetScale(Vecor2(50.f, 300.f));	//���� �浹 ������ ��
		AddObject(WallL, GROUP_TYPE::WALL);
	}

	///��¥ ���ʺ� ������浹
	FakeWallLeftRight* FakeWall_L = nullptr;
	FakeWall_L = new FakeWallLeftRight;
	FakeWall_L->SetName(L"FakeLeft");					///���ʺ�
	FakeWall_L->SetPos(Vecor2(0.f, 600.f));			// ���� ������
	//FakeWall_L->SetScale(Vecor2(50.f, 2500.f));		// ������ũ�⸦ ������ �� �ִ�.
	FakeWall_L->GetCollider()->SetScale(Vecor2(50.f, 2500.f));	//���� �浹 ������ ��
	AddObject(FakeWall_L, GROUP_TYPE::FAKE);

	for (int i = 0; i < 6; i++)
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
	//FakeWall_R->SetScale(Vecor2(50.f, 2500.f));		// ������ũ�⸦ ������ �� �ִ�.
	FakeWall_R->GetCollider()->SetScale(Vecor2(50.f, 2500.f));	//���� �浹 ������ ��
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
		Floor2->SetPos(Vecor2(350.f * i + 150.f, 1775.f)); // �ٴ��� ����
		Floor2->SetScale(Vecor2(350.f, 50.f));
		Floor2->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//���� �浹 ������ ��
		AddObject(Floor2, GROUP_TYPE::FLOOR);
	}

	///��¥ �ٴ����� ����

	FakeWallUpDown* FakeFloor1 = nullptr;
	FakeFloor1 = new FakeWallUpDown;
	FakeFloor1->SetName(L"FakeDown");
	FakeFloor1->SetPos(Vecor2(1200.f, 1775.f)); ///�ٴ��� ����
	//FakeFloor1->SetScale(Vecor2(4000.f, 50.f));
	FakeFloor1->GetCollider()->SetScale(Vecor2(4000.f, 50.f));	//���� �浹 ������ ��
	AddObject(FakeFloor1, GROUP_TYPE::FAKE);

	/// �߰� �ٴ�
	for(int i = 0 ; i < 9 ; i++)
	{
		Floor* Floor1 = nullptr;
		Floor1 = new Floor;
		Floor1->SetName(L"FLOOR2");
		Floor1->SetPos(Vecor2(350.f*i + 150.f, 900.f)); // �ٴ��� ����
		Floor1->SetScale(Vecor2(350.f, 50.f));
		Floor1->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//���� �浹 ������ ��
		AddObject(Floor1, GROUP_TYPE::FLOOR);
	}

	/// ��ٸ�1 , �÷��� 1
	CLadder* Ladder1 = nullptr;
	Ladder1 = new CLadder;
	Ladder1->SetName(L"Ladder1");
	Ladder1->SetPos(Vecor2(850.f, 1500.f));	 // ��ٸ��� ������
	Ladder1->SetScale(Vecor2(5.f, 450.f));	 // ������ũ��
	Ladder1->GetCollider()->SetScale(Vecor2(5.f, 450.f));	// �浹 ������ ��
	AddObject(Ladder1, GROUP_TYPE::LADDER);

	Floor* Floor3 = nullptr;
	Floor3 = new Floor;
	Floor3->SetName(L"FLOOR2");
	Floor3->SetPos(Vecor2(950.f, 1300.f)); //�ٴ��� ����

	Floor3->SetScale(Vecor2(350.f, 50.f));
	Floor3->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//���� �浹 ������ ��
	AddObject(Floor3, GROUP_TYPE::FLOOR);

	/// ���θ��� ���� ������Ʈ�� ����ٰ�..!
	SeaUr* seaUr = nullptr;
	seaUr = new SeaUr;
	seaUr->SetName(L"SeaUr");
	seaUr->SetPos(Vecor2(1420.f, 1650.f)); //�ٴ��� ����
	seaUr->SetScale(Vecor2(200.f, 200.f));
	seaUr->GetCollider()->SetScale(Vecor2(200.f, 200.f));	//���� �浹 ������ ��
	AddObject(seaUr, GROUP_TYPE::SEAUR);

	/// ��ٸ�2, �÷��� 2
	Floor* Floor4 = nullptr;
	Floor4 = new Floor;
	Floor4->SetName(L"FLOOR2");
	Floor4->SetPos(Vecor2(1450.f, 1300.f)); //�ٴ��� ����
	Floor4->SetScale(Vecor2(350.f, 50.f));
	Floor4->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//���� �浹 ������ ��
	AddObject(Floor4, GROUP_TYPE::FLOOR);

	CLadder* Ladder2 = nullptr;
	Ladder2 = new CLadder;
	Ladder2->SetName(L"Ladder1");
	Ladder2->SetPos(Vecor2(1600.f, 1500.f));	 // ��ٸ��� ������
	Ladder2->SetScale(Vecor2(5.f, 450.f));	 // ������ũ��
	Ladder2->GetCollider()->SetScale(Vecor2(5.f, 450.f));	// �浹 ������ ��
	AddObject(Ladder2, GROUP_TYPE::LADDER);

	/// ��� �÷���
	for(int i = 0 ; i < 3 ; i++)
	{
		Floor* Floor5 = nullptr;
		Floor5 = new Floor;
		Floor5->SetName(L"FLOOR2");
		Floor5->SetPos(Vecor2(2200.f + i * 200, 1710.f - i * 100)); //�ٴ��� ����
		Floor5->SetScale(Vecor2(350.f, 50.f));
		Floor5->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//���� �浹 ������ ��
		AddObject(Floor5, GROUP_TYPE::FLOOR);
	}

	///������ ����� FLOOR3ó��������ؼ� ���� ����
	Floor* Floor5 = nullptr;
	Floor5 = new Floor;
	Floor5->SetName(L"FLOOR3");
	Floor5->SetPos(Vecor2(2800.f , 1410.f)); //�ٴ��� ����
	Floor5->SetScale(Vecor2(350.f, 50.f));
	Floor5->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//���� �浹 ������ ��
	AddObject(Floor5, GROUP_TYPE::FLOOR);

	
	/// �߰� �ٴ����� ���� ��ٸ� �÷���
	CLadder* Ladder3 = nullptr;
	Ladder3 = new CLadder;
	Ladder3->SetName(L"Ladder1");
	Ladder3->SetPos(Vecor2(2800.f, 1100.f));	 // ��ٸ��� ������
	Ladder3->SetScale(Vecor2(20.f, 450.f));	 // ������ũ��
	Ladder3->GetCollider()->SetScale(Vecor2(5.f, 450.f));	// �浹 ������ ��
	AddObject(Ladder3, GROUP_TYPE::LADDER);


	/// ��ٸ� 3, �÷��� 4 (����)
	Floor* Floor9 = nullptr;
	Floor9 = new Floor;
	Floor9->SetName(L"FLOOR2");
	Floor9->SetPos(Vecor2(850.f, 440.f)); //�ٴ��� ����
	Floor9->SetScale(Vecor2(350.f, 50.f));
	Floor9->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//���� �浹 ������ ��
	AddObject(Floor9, GROUP_TYPE::FLOOR);

	Floor* Floor10 = nullptr;
	Floor10 = new Floor;
	Floor10->SetName(L"FLOOR2");
	Floor10->SetPos(Vecor2(1450.f, 440.f)); //�ٴ��� ����
	Floor10->SetScale(Vecor2(350.f, 50.f));
	Floor10->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//���� �浹 ������ ��
	AddObject(Floor10, GROUP_TYPE::FLOOR);

	CLadder* Ladder4 = nullptr;
	Ladder4 = new CLadder;
	Ladder4->SetName(L"Ladder1");
	Ladder4->SetPos(Vecor2(1600.f, 640.f));	 // ��ٸ��� ������
	Ladder4->SetScale(Vecor2(20.f, 470.f));	 // ������ũ��
	Ladder4->GetCollider()->SetScale(Vecor2(5.f, 450.f));	// �浹 ������ ��
	AddObject(Ladder4, GROUP_TYPE::LADDER);

	Floor* Floor11 = nullptr;
	Floor11 = new Floor;
	Floor11->SetName(L"FLOOR3");
	Floor11->SetPos(Vecor2(1550.f, 900.f)); //�ٴ��� ����
	Floor11->SetScale(Vecor2(350.f, 50.f));
	Floor11->GetCollider()->SetScale(Vecor2(350.f, 50.f));	//���� �浹 ������ ��
	AddObject(Floor11, GROUP_TYPE::FLOOR);

	/// ���θ��� ����2 ������Ʈ�� ����ٰ�..!
	SeaUr* seaUr2 = nullptr;
	seaUr2 = new SeaUr;
	seaUr2->SetName(L"SeaUr");
	seaUr2->SetPos(Vecor2(940.f, 771.f)); //�ٴ��� ����
	seaUr2->SetScale(Vecor2(250.f, 250.f));
	seaUr2->GetCollider()->SetScale(Vecor2(250.f, 250.f));	//���� �浹 ������ ��
	AddObject(seaUr2, GROUP_TYPE::SEAUR);
	
	


	/// ���� �������� 
	GoToNextScene* GoToNextScene1 = nullptr;
	GoToNextScene1 = new GoToNextScene;
	GoToNextScene1->SetName(L"GoToNextScene");					///���� ������ �������� ������..����
	GoToNextScene1->SetPos(Vecor2(90.f, 676.f));			// ���� ������
	GoToNextScene1->SetScale(Vecor2(50.f, 400.f));		// ������ũ�⸦ ������ �� �ִ�.
	GoToNextScene1->GetCollider()->SetScale(Vecor2(50.f, 400.f));	// �浹 ������ ��
	AddObject(GoToNextScene1, GROUP_TYPE::GOTONEXTSCENE);


	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::ROCK);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::FLOOR);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::LADDER);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::WALL);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::DOOR);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::FISH, GROUP_TYPE::WALL);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::FISH, GROUP_TYPE::FAKE);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::ROCK, GROUP_TYPE::FLOOR);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::ROCK, GROUP_TYPE::WALL);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::GOTONEXTSCENE);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::SEAUR);

}


void Stage2::Exit()
{
	DeleteAll();

	// �浹 üũ �� ���� �����Ѵ�.
	CCollisionManager::GetInstance()->Reset();
}

