#include "pch.h"
#include "Stage5.h"

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

Stage5::Stage5()
{

}

Stage5::~Stage5()
{

}

void Stage5::Update()
{
	CScene::Update();

	if (KEY_TAP(KEY::ENTER))
	{
		CSceneManager::GetInstance()->ChangeScene(SCENE_TYPE::STAGE_02);
	}
}

void Stage5::Enter()
{

}

void Stage5::Exit()
{
	DeleteAll();

	// �浹 üũ �� ���� �����Ѵ�.
	CCollisionManager::GetInstance()->Reset();
}

