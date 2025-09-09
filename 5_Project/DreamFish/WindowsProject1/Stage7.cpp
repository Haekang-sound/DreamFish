#include "pch.h"
#include "Stage7.h"

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

#include "CSoundManager.h"
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
#include "CAnimator.h"
#include "CLogo.h"
#include "CEnd.h"

#include "CResManager.h"
#include "CBackGround.h"

Stage7::Stage7()
	: m_pTex(nullptr), pGame(nullptr)
{
	m_pTex = CResManager::GetInstance()->LoadTexture(L"LogoTex", L"texture\\Title.bmp");
	pGame = CGameProcess::GetInstance();
}

Stage7::~Stage7()
{

}

void Stage7::Update()
{

	/// �ذ��� ���� ���⿡ ���� ���� ���� �ϳ��� ����� �ֽø� �����մϴ� :)
	CScene::Update();


		
// 	CEnd* pEnd = nullptr;
// 	pEnd = new CEnd;
// 	pEnd->SetPos(Vecor2(300.f, 200.f));
// 	pEnd->SetScale(Vecor2(200.f, 50.f));
// 	AddObject(pEnd, GROUP_TYPE::END);


// 	CBackGround* pBack = new CBackGround;			///�̰� �ǹ��ϴ� �ٰ� ����?
// 	pBack->SetPos(Vecor2(500.f, 500.f));
// 	pBack->SetTexture(L"EndTex", L"texture\\end.bmp");
// 	pBack->SetSize(1540, 448);
// 	//pBack->SetScale(Vecor2(100.f, 100.f));
// 	AddObject(pBack, GROUP_TYPE::ENDLOGO);

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
	

	// �ΰ� �߰�
	CEnd* pEndLogo = nullptr;
	pEndLogo = new CEnd;
	pEndLogo->SetPos(Vecor2(300.f, 200.f));
	pEndLogo->SetScale(Vecor2(200.f, 50.f));
	AddObject(pEndLogo, GROUP_TYPE::ENDLOGO);


 }
		
void Stage7::Enter()
{
	CSoundManager::GetInstance()->PlayMusic(SOUND_TRACK::ENDING_SOUND);
}

void Stage7::Exit()
{
	DeleteAll();

	// �浹 üũ �� ���� �����Ѵ�.
	CCollisionManager::GetInstance()->Reset();
}

