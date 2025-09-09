#include "pch.h"
#include "CTitle.h"
#include "CButtonStart.h"
#include "CButtonQuit.h"
#include "CLogo.h"

#include "CObject.h"

#include "CPlayer.h"
#include "CKeyManager.h"
#include "CGameProcess.h"
#include "CFish.h"

#include "CCollisionManager.h"
#include "CSceneManager.h"
#include "CSoundManager.h"

#include "CResManager.h"
#include "CTexture.h"

CTitle::CTitle()
{

}

CTitle::~CTitle()
{

}

void CTitle::Update()
{
	CScene::Update();

	//Button_Start(update()); �̽��׸� �ڵ� (������ �ȴ�...)
	CButtonStart buttonStart;
	CButtonQuit buttonQuit;
	buttonStart.Update();
	buttonQuit.Update();

}

void CTitle::Enter()
{
	// Ÿ��Ʋ �뷡����
	CSoundManager::GetInstance()->PlayMusic(SOUND_TRACK::BACKGROUND_SOUND);

	// ���� ���� Object �߰�
	CButtonStart* Start = nullptr;
	Start = new CButtonStart;
	Start->SetPos(Vecor2(200.f, 100.f));
	Start->SetScale(Vecor2(200.f, 50.f));
	AddObject(Start, GROUP_TYPE::GAMESTART);

	// ���� ���� Object �߰�
	CButtonQuit* quit = nullptr;
	quit = new CButtonQuit;
	quit->SetPos(Vecor2(300.f, 200.f));
	quit->SetScale(Vecor2(200.f, 50.f));
	AddObject(quit, GROUP_TYPE::GAMEQUIT);

	// �ΰ� �߰�
	CLogo* pLogo = nullptr;
	pLogo = new CLogo;
	pLogo->SetPos(Vecor2(300.f, 200.f));
	pLogo->SetScale(Vecor2(200.f, 50.f));
	AddObject(pLogo, GROUP_TYPE::GAMELOGO);


	Vecor2 vResolution = CGameProcess::GetInstance()->GetResolution();
	CCamera::GetInstance()->SetLookAt(vResolution / 2.f);
	CCamera::GetInstance()->SetTarget(Start, Start);

}

void CTitle::Exit()
{
	DeleteAll();

}

