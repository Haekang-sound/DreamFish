#include "pch.h"
#include "CSceneTool.h"

#include "CObject.h"

#include "CBackGround.h"
#include "CPlayer.h"
#include "Floor.h"
#include "CRock.h"

#include "CGameProcess.h"
#include "CPathManager.h"
#include "CTexture.h"

#include "CCollisionManager.h"
#include "CKeyManager.h"
#include "CSceneManager.h"
#include "CCamera.h"
#include "CTimeManager.h"
#include "CFish.h"

CSceneTool::CSceneTool()
{

}

CSceneTool::~CSceneTool()
{

}

void CSceneTool::Update()
{
	// SCEEN Ʃ�丮�󿡼� > START�Ѿ�Բ� �ϱ�?
	CScene::Update();

	if (KEY_TAP(KEY::ENTER))
	{
		CSceneManager::GetInstance()->ChangeScene(SCENE_TYPE::START);
	}
}

void CSceneTool::Enter()
{
	// Object �߰�
	CObject* pBack = new CBackGround;
	pBack->SetPos(Vecor2(0.f, 0.f));
	pBack->SetScale(Vecor2(100.f, 100.f));
	AddObject(pBack, GROUP_TYPE::DEFALUT);

	CObject* pObj = new CPlayer;
	pObj->SetPos(Vecor2(640.f, 384.f));
	pObj->SetScale(Vecor2(100.f, 100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);

	CObject* fish = new CFish;
	fish->SetPos(Vecor2(640.f, 384.f));
	fish->SetScale(Vecor2(100.f, 100.f));
	AddObject(fish, GROUP_TYPE::FISH);

	// ���� ��ġ
	CRock* Rock123 = nullptr;
	for (int i = 0; i < 5; ++i)
	{
		// ���� ( Foothold ) �߰�
		Rock123 = new CRock;
		Rock123->SetPos(Vecor2(50.f + (float)i * 500, 50.f)); // ����ȭ 17. 52:22
		Rock123->SetScale(Vecor2(200.f, 50.f));
		AddObject(Rock123, GROUP_TYPE::ROCK);
	}
	Vecor2 vResolution = CGameProcess::GetInstance()->GetResolution();
	CCamera::GetInstance()->SetLookAt(vResolution / 2.f);
	CCamera::GetInstance()->SetTarget(pObj, fish);

	//�ٴ��� ����
	Floor* Floor1 = nullptr;
	Floor1 = new Floor;
	Floor1->SetPos(Vecor2(500.f, 600.f)); // ����ȭ 17. 52:22
	Floor1->SetScale(Vecor2(3000.f, 50.f));
	AddObject(Floor1, GROUP_TYPE::FLOOR);

	// �浹 ����
	// �÷��̾�� ���� �׷� ���� �浹 üũ
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::ROCK);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::FLOOR);
	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::FISH, GROUP_TYPE::ROCK);
}

void CSceneTool::Exit()
{
	DeleteAll();

	// �浹 üũ �� ���� �����Ѵ�.
	CCollisionManager::GetInstance()->Reset();
}