#pragma once
#include "pch.h"
#include "CSceneStart.h"

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

CSceneStart::CSceneStart()
{

}

CSceneStart::~CSceneStart()
{

}

void CSceneStart::Update()
{
	CScene::Update();
	
	if (KEY_TAP(KEY::ENTER))
	{
		CSceneManager::GetInstance()->ChangeScene(SCENE_TYPE::TOOL);
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

void CSceneStart::Enter()
{

	// Object �߰�
	CObject* pBack = new CBackGround;
	pBack->SetPos(Vecor2(0.f, 0.f));
	pBack->SetScale(Vecor2(100.f, 100.f));
	AddObject(pBack, GROUP_TYPE::DEFALUT);

	//�����߰�
	CObject* fish = new CFish;
	fish->SetPos(Vecor2(640.f, 384.f));
	fish->SetScale(Vecor2(100.f, 100.f));
	AddObject(fish, GROUP_TYPE::FISH);

	//PLAYER �߰�
	CPlayer* pObj = new CPlayer;
	pObj->SetName(L"PLAYER");
	pObj->SetPos(Vecor2(640.f, 384.f));
	pObj->SetScale(Vecor2(100.f, 100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);

	//CPlayer*
	if (!pObj->IsDead()) {
		PlayerWidth* pWidth = new PlayerWidth;
		pWidth->SetName(L"PLAYERWidth");
		pWidth->SetPos(Vecor2(640.f, 384.f));
		pWidth->SetScale(Vecor2(100.f, 100.f));
		pWidth->SetPlayer(pObj);
		AddObject(pWidth, GROUP_TYPE::PLAYER);
	}


	//ī�޶�
	Vecor2 vResolution = CGameProcess::GetInstance()->GetResolution();
	CCamera::GetInstance()->SetLookAt(vResolution / 2.f);
	CCamera::GetInstance()->SetTarget(pObj,fish);

	///-------------------------------------------------------------------

	//����ġ
	CLadder* Ladder1 = nullptr;
	Ladder1 = new CLadder;
	Ladder1->SetName(L"Ladder1");
	Ladder1->SetPos(Vecor2(500.f, 450.f));	 // ��ٸ��� ������
	Ladder1->SetScale(Vecor2(50.f, 400.f));	 // ������ũ��

	Ladder1->GetCollider()->SetScale(Vecor2(50.f, 400.f));	//���� �浹 ������ ��
	AddObject(Ladder1, GROUP_TYPE::LADDER);


// 	// ���� ��ġ
// 	CRock* Rock1 = nullptr;
// 	Rock1 = new CRock;
// 	Rock1->SetName(L"Rock");
// 	Rock1->SetPos(Vecor2(300.f, 500.f)); // ����ȭ 17. 52:22
// 	Rock1->SetScale(Vecor2(50.f, 50.f));
// 	AddObject(Rock1, GROUP_TYPE::ROCK);


	//�ٴ��� ����
	Floor* Floor1 = nullptr;
	Floor1 = new Floor;
	Floor1->SetName(L"FLOOR1");
	Floor1->SetPos(Vecor2(500.f, 600.f)); // ����ȭ 17. 52:22
	Floor1->SetScale(Vecor2(1200.f, 50.f));
	AddObject(Floor1, GROUP_TYPE::FLOOR);

	//2�� �ٴ��� ����
	Floor* Floor2 = nullptr;
	Floor2 = new Floor;
	Floor2->SetName(L"FLOOR2");
	Floor2->SetPos(Vecor2(500.f, 300.f)); // ����ȭ 17. 52:22
	Floor2->SetScale(Vecor2(1200.f, 50.f));
	AddObject(Floor2, GROUP_TYPE::FLOOR);

	//����ġ
	CWall* Wall1 = nullptr;
	Wall1 = new CWall;
	Wall1->SetName(L"Wall1");
	Wall1->SetPos(Vecor2(1000.f, 475.f));	 // ���� ������
	Wall1->SetScale(Vecor2(50.f, 200.f));	 // ������ũ��
	AddObject(Wall1, GROUP_TYPE::WALL);

	GoToNextScene* GoToNextScene1 = nullptr;
	GoToNextScene1 = new GoToNextScene;
	GoToNextScene1->SetName(L"GoToNextScene");					///���� ������ �������� ������..����
	GoToNextScene1->SetPos(Vecor2(1000.f, 400.f));			// ���� ������
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
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::ROCK, GROUP_TYPE::FLOOR);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::GOTONEXTSCENE);


}

void CSceneStart::Exit()
{
	DeleteAll();

	// �浹 üũ �� ���� �����Ѵ�.
	CCollisionManager::GetInstance()->Reset();
}