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
	m_pTex = CResManager::GetInstance()->LoadTexture(L"StartButtonTex", L"texture\\button_Title_Start_fixed.bmp");
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
		CSceneManager::GetInstance()->ChangeScene(SCENE_TYPE::TUTORIAL);
		//CSGameProcess::pused = fales;
	}
}

void CButtonStart::Render(HDC _dc)
{
	POINT windowResolution = pGame->GetResolution();

	int buttonHeight = m_pTex->Height();
	int buttonWidth = m_pTex->Width();


// 	BitBlt(_dc
// 		, (windowResolution.x / 2) - (buttonWidth / 2)
// 		, (windowResolution.y / 2) - (buttonHight / 2) + 100
// 		, (windowResolution.x / 2) + (buttonWidth / 2)
// 		, (windowResolution.y / 2) + (buttonHight / 2) + 100
// 		, m_pTex->GetDC(), 0, 0, SRCCOPY);


	TransparentBlt(_dc
		, (windowResolution.x / 2) - (buttonWidth / 2)
		, (windowResolution.y / 2) - (buttonHeight / 2) + 100
		, buttonWidth
		, buttonHeight
		, m_pTex->GetDC()	// 
		, 0					// 스프라이트 x좌표 (애니메이션 시작점)		
		, 0					// 스프라이트 y좌표 (애니메이션 상태좌표)
		, buttonWidth 	// 스프라이트 크기 (x길이)
		, buttonHeight 	// 스프라이트 크기 (y길이)
		, RGB(255, 0, 255));

}
