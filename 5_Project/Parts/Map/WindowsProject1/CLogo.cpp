#include "pch.h"
#include "CLogo.h"

#include "CGameProcess.h"

#include "CResManager.h"
#include "CTexture.h"


CLogo::CLogo()
	:m_pTex(nullptr), pGame(nullptr)
{
	m_pTex = CResManager::GetInstance()->LoadTexture(L"LogoTex", L"texture\\Logo.bmp");
	pGame = CGameProcess::GetInstance();
}

CLogo::~CLogo()
{

}

void CLogo::Update()
{
}

void CLogo::Render(HDC _dc)
{
	POINT windowResolution = pGame->GetResolution();

	int buttonHight = m_pTex->Height();
	int buttonWidth = m_pTex->Width();


	BitBlt(_dc
		, (windowResolution.x / 2) - (buttonWidth / 2)
		, (windowResolution.y / 3) - (buttonHight / 2)
		, (windowResolution.x / 2) + (buttonWidth / 2)
		, (windowResolution.y / 3) + (buttonHight / 2)
		, m_pTex->GetDC(), 0, 0, SRCCOPY);
}


