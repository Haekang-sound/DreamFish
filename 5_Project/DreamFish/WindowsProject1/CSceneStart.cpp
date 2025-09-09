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
#include "CSoundManager.h"
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

#include "CBackGround.h"

#include "CResManager.h"
#include "CAnimator.h"


CSceneStart::CSceneStart()
	:m_pTex(nullptr), pGame(nullptr)
{
	m_pTex = CResManager::GetInstance()->LoadTexture(L"ControlTex", L"texture\\howtoPlay_1.bmp");
	pGame = CGameProcess::GetInstance();
}
CSceneStart::~CSceneStart()
{

}

void CSceneStart::Update()
{
	CScene::Update();
	
	if (KEY_TAP(KEY::LBTN))
	{
		CSceneManager::GetInstance()->ChangeScene(SCENE_TYPE::STAGE_01);
	}

	if (KEY_TAP(KEY::ESC))
	{
		// 게임 종료 Object 추가
		CButtonQuit* quit = nullptr;
		quit = new CButtonQuit;
		quit->SetPos(Vecor2(300.f, 200.f));
		quit->SetScale(Vecor2(200.f, 50.f));
		AddObject(quit, GROUP_TYPE::GAMEQUIT);

		// 타이틀 화면 Object 추가
		CButtonTitle* title = nullptr;
		title = new CButtonTitle;
		title->SetPos(Vecor2(200.f, 100.f));
		title->SetScale(Vecor2(200.f, 50.f));
		AddObject(title, GROUP_TYPE::GAMETITLE);

	}
}

void CSceneStart::Enter()
{
	CSoundManager::GetInstance()->SoundSetUp();
	CSoundManager::GetInstance()->PlayMusic(SOUND_TRACK::BACKGROUND_SOUND);
}

void CSceneStart::Render(HDC _dc)
{
	POINT windowResolution = pGame->GetResolution();

	int width = m_pTex->Height();
	int height = m_pTex->Width();


	// 애니메이션인자를 채우기 위한 내용들
	Vecor2 vScale = { 1.f, 1.f };
	CAnimator* pAni = new CAnimator;

	Vecor2 vPos = windowResolution;
	//SetRenderPos(vPos);

	// 애니메이션 적용

	BitBlt(_dc
		, (windowResolution.x / 2) - (height / 2)
		, (windowResolution.y / 2) - (width / 2)
		, (windowResolution.x / 2) + (height / 2)
		, (windowResolution.y / 2) + (width / 2)
		, m_pTex->GetDC(), 0, 0, SRCCOPY);
	delete pAni;

}

void CSceneStart::Exit()
{
	
}