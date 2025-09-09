#include "pch.h"
#include "CTitleText.h"

#include "CGameProcess.h"

#include "CResManager.h"
#include "CTexture.h"

CTitleText::CTitleText()
	:m_pTex(nullptr), pGame(nullptr)
{
		m_pTex = CResManager::GetInstance()->LoadTexture(L"LogoTex", L"texture\\DreamFish_Logo_01.bmp");
		pGame = CGameProcess::GetInstance();
}

CTitleText::~CTitleText()
{

}


void CTitleText::Update()
{

}

void CTitleText::Render(HDC _dc)
{
	POINT windowResolution = pGame->GetResolution();

	int buttonHight = m_pTex->Height();
	int buttonWidth = m_pTex->Width();

	TransparentBlt(_dc
		, (windowResolution.x / 2) - (buttonWidth / 2)
		, (windowResolution.y / 2) - (buttonHight / 2)
		, buttonHight
		, buttonWidth	
		, m_pTex->GetDC()
		, 0
		, 0
		, buttonHight
		, buttonWidth
		, RGB(255, 0, 255));
}

