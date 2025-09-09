#include "pch.h"
#include "CTitle.h"
#include "CButtonStart.h"
#include "CButtonQuit.h"

#include "CObject.h"

#include "CPlayer.h"
#include "CKeyManager.h"
#include "CGameProcess.h"
#include "CFish.h"

#include "CCollisionManager.h"
#include "CSceneManager.h"
#include "CSoundManager.h"

CTitle::CTitle()
{

}

CTitle::~CTitle()
{

}

void CTitle::Update()
{
	CScene::Update();

	//Button_Start(update()); 미스테리 코드 (실행이 된다...)
	CButtonStart buttonStart;
	CButtonQuit buttonQuit;
	buttonStart.Update();
	buttonQuit.Update();
	

}

void CTitle::Enter()
{
	CSoundManager::GetInstance()->PlayMusic(SOUND_TRACK::BACKGROUND_SOUND);

	// 게임 시작 Object 추가
	CButtonStart* Start = nullptr;
	Start = new CButtonStart;
	Start->SetPos(Vecor2(200.f, 100.f));
	Start->SetScale(Vecor2(200.f, 50.f));
	AddObject(Start, GROUP_TYPE::GAMESTART);

	// 게임 종료 Object 추가 
	CButtonQuit* quit = nullptr;
	quit = new CButtonQuit;
	quit->SetPos(Vecor2(300.f, 200.f));
	quit->SetScale(Vecor2(200.f, 50.f));
	AddObject(quit, GROUP_TYPE::GAMEQUIT);

	Vecor2 vResolution = CGameProcess::GetInstance()->GetResolution();
	CCamera::GetInstance()->SetLookAt(vResolution / 2.f);
	CCamera::GetInstance()->SetTarget(Start, Start);
}

void CTitle::Exit()
{
	DeleteAll();

}

