#include "pch.h"
#include "CScene_Start.h"

#include "cObject.h"

#include "CPlayer.h"
#include "CFoothold.h"

#include "CCore.h"
#include "CPathMgr.h"
#include "CTexture.h"

#include "CCollisionMgr.h"
#include "CKeyMgr.h"
#include "CSceneMgr.h"

CScene_Start::CScene_Start()
{

}

CScene_Start::~CScene_Start()
{

}

void CScene_Start::update()
{
	CScene::update();

	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::TOOL);
	}
}

void CScene_Start::Enter()
{
	// Object �߰�
	cObject* pObj = new CPlayer;	
	pObj->SetPos(Vec2(640.f, 384.f));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);

	// ���� ��ġ
	CFoothold* pFoothold = nullptr; 
	for (int i = 0; i < 5; ++i)
	{
		// ���� ( Foothold ) �߰�
		pFoothold = new CFoothold;
		pFoothold->SetPos(Vec2(50.f + (float)i*500, 50.f)); // ����ȭ 17. 52:22
		pFoothold->SetScale(Vec2(200.f, 50.f));
		AddObject(pFoothold, GROUP_TYPE::FOOTHOLD);
	}

	// �浹 ����
	// �÷��̾�� ���� �׷� ���� �浹 üũ
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::FOOTHOLD);

}

void CScene_Start::Exit()
{
	DeleteAll();

	// �浹 üũ �� ���� �����Ѵ�.
	CCollisionMgr::GetInst()->Reset();
}