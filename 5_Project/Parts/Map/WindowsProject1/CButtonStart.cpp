#include "pch.h"
#include "CButtonStart.h"

#include "cObject.h"
#include "COtherCollider.h"
#include "CGameProcess.h"
#include "CKeyManager.h"
#include "CSceneManager.h"

#include "CResManager.h"
#include "CTexture.h"
#include "CSoundManager.h"

CButtonStart::CButtonStart()
	:m_pTex(nullptr), pGame(nullptr)
{
	m_pTex = CResManager::GetInstance()->LoadTexture(L"StartButtonTex", L"texture\\StartButton.bmp");
	pGame = CGameProcess::GetInstance();
}

CButtonStart::~CButtonStart()
{

}

void CButtonStart::Update()
{
	POINT windowResolution = pGame->GetResolution();
	POINT ptPos = {};

	int buttonHeight = m_pTex->Height();
	int buttonWidth = m_pTex->Width();

	GetCursorPos(&ptPos);
	ScreenToClient(CGameProcess::GetInstance()->GetMainHwnd(), &ptPos);
	bool checkRect = false;

	if ((windowResolution.x / 2) - (buttonWidth / 2) < ptPos.x && ptPos.x < (windowResolution.x / 2) + (buttonWidth / 2))
	{
		if ((windowResolution.y / 2) - (buttonHeight / 2) + 100 < ptPos.y && ptPos.y < (windowResolution.y / 2) + (buttonHeight / 2) + 100)
		{
			checkRect = true;
		}
	}

	if ((KEY_TAP(KEY::LBTN)) && checkRect)
	{
		CSoundManager::GetInstance()->ReleaseMusic();
		CSceneManager::GetInstance()->ChangeScene(SCENE_TYPE::STAGE_01);
		//CSGameProcess::pused = fales;
	}
}

void CButtonStart::Render(HDC _dc)
{
	POINT windowResolution = pGame->GetResolution();

	int buttonHight = m_pTex->Height();
	int buttonWidth = m_pTex->Width();


	BitBlt(_dc
		, (windowResolution.x / 2) - (buttonWidth / 2)
		, (windowResolution.y / 2) - (buttonHight / 2) + 100
		, (windowResolution.x / 2) + (buttonWidth / 2)
		, (windowResolution.y / 2) + (buttonHight / 2) + 100
		, m_pTex->GetDC(), 0, 0, SRCCOPY);

}
