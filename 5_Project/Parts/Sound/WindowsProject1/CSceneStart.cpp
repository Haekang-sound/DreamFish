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

#include "CKeyManager.h"
#include "CGameProcess.h"
#include "CPathManager.h"
#include "CTexture.h"
#include "CCollider.h"

#include "CCollisionManager.h"
#include "CSceneManager.h"
#include "CCamera.h"
#include "CTimeManager.h"
#include "CFish.h"
#include "CSoundManager.h"

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


	// ���� ��ġ
	CRock* Rock1 = nullptr;
	Rock1 = new CRock;
	Rock1->SetName(L"Rock1");
	Rock1->SetPos(Vecor2(300.f, 550.f)); // ����ȭ 17. 52:22
	Rock1->SetScale(Vecor2(50.f, 50.f));
	AddObject(Rock1, GROUP_TYPE::ROCK);


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

	///-----------------------------------------------------------------------------------------

	// �浹 ����
	// �÷��̾�� ���� �׷� ���� �浹 üũ
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::ROCK);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::FLOOR);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::LADDER);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::WALL);
}

void CSceneStart::Exit()
{
	DeleteAll();

	// �浹 üũ �� ���� �����Ѵ�.
	CCollisionManager::GetInstance()->Reset();
}