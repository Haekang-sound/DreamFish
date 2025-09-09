#include "pch.h"
#include "CButtonTitle.h"

#include "CGameProcess.h"
#include "COtherCollider.h"
#include "CSceneManager.h"
#include "CKeyManager.h"

#include "CResManager.h"
#include "CTexture.h"

CButtonTitle::CButtonTitle()
	:m_pTex(nullptr), pGame(nullptr)
{
	m_pTex = CResManager::GetInstance()->LoadTexture(L"TitleButtonTex", L"texture\\TitleButton.bmp");
	pGame = CGameProcess::GetInstance();
}

CButtonTitle::~CButtonTitle()
{

}

void CButtonTitle::Update()
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
		CSceneManager::GetInstance()->ChangeScene(SCENE_TYPE::TITLE);
		//CSGameProcess::pused = fales;
	}
}

void CButtonTitle::Render(HDC _dc)
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

