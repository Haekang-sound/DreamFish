#include "pch.h"
#include "CButtonQuit.h"

#include "CGameProcess.h"
#include "COtherCollider.h"
#include "CSceneManager.h"
#include "CKeyManager.h"
#include "WindowsProject1.h"

#include "CResManager.h"
#include "CTexture.h"
#include "CScene.h"

CButtonQuit::CButtonQuit()
	:m_pTex(nullptr), pGame(nullptr)
{
	m_pTex = CResManager::GetInstance()->LoadTexture(L"QuitButtonTex", L"texture\\button_Menu_Quit_fixed.bmp");
	pGame = CGameProcess::GetInstance();
}

CButtonQuit::~CButtonQuit()
{

}

void CButtonQuit::Update()
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
		if ((windowResolution.y / 2) - (buttonHeight / 2) + 250 < ptPos.y && ptPos.y < (windowResolution.y / 2) + (buttonHeight / 2) + 250 ) 
		{
			checkRect = true;
		}
	}

	if ((KEY_TAP(KEY::LBTN)) && checkRect)
	{
		PostQuitMessage(0);
	}
}

void CButtonQuit::Render(HDC _dc)
{
	POINT windowResolution = pGame->GetResolution();

	int buttonHeight = m_pTex->Height();
	int buttonWidth = m_pTex->Width();



	TransparentBlt(_dc
		, (windowResolution.x / 2) - (buttonWidth / 2)
		, (windowResolution.y / 2) - (buttonHeight / 2) + 250
		, buttonWidth
		, buttonHeight
		, m_pTex->GetDC()	// 
		, 0					// 스프라이트 x좌표 (애니메이션 시작점)		
		, 0					// 스프라이트 y좌표 (애니메이션 상태좌표)
		, buttonWidth 	// 스프라이트 크기 (x길이)
		, buttonHeight 	// 스프라이트 크기 (y길이)
		, RGB(255, 0, 255));


// 	BitBlt(_dc
// 		, (windowResolution.x / 2) - (buttonWidth / 2)
// 		, (windowResolution.y / 2) - (buttonHight / 2) + 250
// 		, (windowResolution.x / 2) + (buttonWidth / 2)
// 		, (windowResolution.y / 2) + (buttonHight / 2) + 250
// 		, m_pTex->GetDC(), 0, 0, SRCCOPY);
}
