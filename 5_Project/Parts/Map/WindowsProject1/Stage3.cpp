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
	// Object �߰�		
	CObject* pBack = new CBackGround;			///�̰� �ǹ��ϴ� �ٰ� ����?
	pBack->SetPos(Vecor2(0.f, 0.f));
	pBack->SetScale(Vecor2(100.f, 100.f));
	AddObject(pBack, GROUP_TYPE::DEFALUT);

	//�����߰�
	CObject* fish = new CFish;					///���콺�� �̵��� ������ ������ �����.
	fish->SetPos(Vecor2(100.f, 400.f));
	fish->SetScale(Vecor2(100.f, 100.f));
	AddObject(fish, GROUP_TYPE::FISH);

	//PLAYER �߰�
	CPlayer* pObj = new CPlayer;				///WASD�� �̵��� ������ �÷��̾ �����
	pObj->SetName(L"PLAYER");
	pObj->SetPos(Vecor2(2800.f, 800.f));
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

	CWall* WallL = nullptr;
	WallL = new CWall;
	WallL->SetName(L"Wall");					///���ʺ�
	WallL->SetPos(Vecor2(0.f, 400.f));			// ���� ������
	WallL->SetScale(Vecor2(50.f, 2550.f));		// ������ũ�⸦ ������ �� �ִ�.
	WallL->GetCollider()->SetScale(Vecor2(50.f, 2550.f));	//���� �浹 ������ ��
	AddObject(WallL, GROUP_TYPE::WALL);

	CWall* WallR = nullptr;
	WallR = new CWall;
	WallR->SetName(L"Wall");					///������ ��1
	WallR->SetPos(Vecor2(3000.f, 400.f));			// ���� ������
	WallR->SetScale(Vecor2(50.f, 2550.f));		// ������ũ�⸦ ������ �� �ִ�.
	WallR->GetCollider()->SetScale(Vecor2(50.f, 2550.f));	// �浹 ������ ��
	AddObject(WallR, GROUP_TYPE::WALL);

	CWall* WallUp = nullptr;
	WallUp = new CWall;
	WallUp->SetName(L"Wall");					///���� ��
	WallUp->SetPos(Vecor2(800.f, 0.f));			// ���� ������
	WallUp->SetScale(Vecor2(1650.f, 50.f));		// ������ũ�⸦ ������ �� �ִ�.
	WallUp->GetCollider()->SetScale(Vecor2(1650.f, 50.f));	// �浹 ������ ��
	AddObject(WallUp, GROUP_TYPE::WALL);

	/// �߰� �ٴ�
	Floor* Floor1 = nullptr;
	Floor1 = new Floor;
	Floor1->SetName(L"FLOOR1");
	Floor1->SetPos(Vecor2(1500.f, 900.f)); // �ٴ��� ����
	Floor1->SetScale(Vecor2(3050.f, 50.f));
	Floor1->GetCollider()->SetScale(Vecor2(3050.f, 50.f));	//���� �浹 ������ ��
	AddObject(Floor1, GROUP_TYPE::FLOOR);

	/// ��ٸ�1 , �÷��� 1, ��ٸ� 2, ��
	CLadder* Ladder1 = nullptr;
	Ladder1 = new CLadder;
	Ladder1->SetName(L"Ladder1");
	Ladder1->SetPos(Vecor2(2300.f, 640.f));	 // ��ٸ��� ������
	Ladder1->SetScale(Vecor2(60.f, 470.f));	 // ������ũ��
	Ladder1->GetCollider()->SetScale(Vecor2(60.f, 470.f));	// �浹 ������ ��
	AddObject(Ladder1, GROUP_TYPE::LADDER);

	Floor* Floor3 = nullptr;
	Floor3 = new Floor;
	Floor3->SetName(L"FLOOR2");
	Floor3->SetPos(Vecor2(1850.f, 440.f)); //�ٴ��� ����
	Floor3->SetScale(Vecor2(1000.f, 50.f));
	Floor3->GetCollider()->SetScale(Vecor2(1000.f, 50.f));	//���� �浹 ������ ��
	AddObject(Floor3, GROUP_TYPE::FLOOR);

	CLadder* Ladder2 = nullptr;
	Ladder2 = new CLadder;
	Ladder2->SetName(L"Ladder1");
	Ladder2->SetPos(Vecor2(1400.f, 640.f));	 // ��ٸ��� ������
	Ladder2->SetScale(Vecor2(60.f, 470.f));	 // ������ũ��
	Ladder2->GetCollider()->SetScale(Vecor2(60.f, 470.f));	// �浹 ������ ��
	AddObject(Ladder2, GROUP_TYPE::LADDER);

	/// ���� (ū ��) ��ġ
	CRock* Rock1 = nullptr;
	Rock1 = new CRock;
	Rock1->SetName(L"Rock");
	Rock1->SetPos(Vecor2(1650.f, 100.f)); // ������ ��ġ
	Rock1->SetScale(Vecor2(170.f, 170.f));
	Rock1->GetCollider()->SetScale(Vecor2(170.f, 170.f));	// �浹 ������ ��
	AddObject(Rock1, GROUP_TYPE::ROCK);

	/// ���� ��ư
	DoorButton* doorButton1 = nullptr;
	doorButton1 = new DoorButton;
	doorButton1->SetName(L"DoorButton");
	doorButton1->SetPos(Vecor2(1250.f, 866.f));
	doorButton1->SetScale(Vecor2(50.f, 20.f));
	doorButton1->GetCollider()->SetScale(Vecor2(50.f, 20.f));
	AddObject(doorButton1, GROUP_TYPE::DOORBUTTON);

	/// �� ��
	CWall* WallL1 = nullptr;
	WallL1 = new CWall;
	WallL1->SetName(L"Wall");					///���ʺ�
	WallL1->SetPos(Vecor2(510.f, 350.f));			// ���� ������
	WallL1->SetScale(Vecor2(50.f, 700.f));		// ������ũ�⸦ ������ �� �ִ�.
	WallL1->GetCollider()->SetScale(Vecor2(50.f, 700.f));	//���� �浹 ������ ��
	AddObject(WallL1, GROUP_TYPE::WALL);

	Door* door1 = nullptr;
	door1 = new Door;
	door1->SetName(L"DoorButton");
	door1->SetPos(Vecor2(510.f, 777.f));
	door1->SetScale(Vecor2(50.f, 200.f));
	door1->GetCollider()->SetScale(Vecor2(50.f, 200.f));
	AddObject(door1, GROUP_TYPE::DOOR);

	/// stage4 �̵�
	GoToNextScene* GoToNextScene3 = nullptr;
	GoToNextScene3 = new GoToNextScene;
	GoToNextScene3->SetName(L"GoToNextScene");					///���� ������ �������� ������..����
	GoToNextScene3->SetPos(Vecor2(100.f, 840.f));			// ���� ������
	GoToNextScene3->SetScale(Vecor2(50.f, 1000.f));		// ������ũ�⸦ ������ �� �ִ�.
	GoToNextScene3->GetCollider()->SetScale(Vecor2(50.f, 1000.f));	// �浹 ������ ��
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

	// �浹 üũ �� ���� �����Ѵ�.
	CCollisionManager::GetInstance()->Reset();
}
