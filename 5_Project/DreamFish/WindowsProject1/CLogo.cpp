#include "pch.h"
#include "CLogo.h"

#include "CGameProcess.h"
#include "CAnimator.h"
#include "CResManager.h"
#include "CTexture.h"


CLogo::CLogo()
	:m_pTex(nullptr), pGame(nullptr)
{
	m_pTex = CResManager::GetInstance()->LoadTexture(L"LogoTex", L"texture\\Title.bmp");
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

	int width = m_pTex->Height();
	int height = m_pTex->Width();




	// 애니메이션 적용

	BitBlt(_dc
	, (windowResolution.x / 2) - (height / 2)
	, (windowResolution.y / 3) - (width / 2) 
	, (windowResolution.x / 2) + (height / 2)
	, (windowResolution.y / 3) + (width / 2)
 	, m_pTex->GetDC(), 0, 0, SRCCOPY);


	// 애니메이션인자를 채우기 위한 내용들
	Vecor2 vScale = { 1.f, 1.f };
	CAnimator* pAni = new CAnimator;

	Vecor2 vPos = windowResolution;
	//SetRenderPos(vPos);
	pAni->MakeText(_dc, vPos, vScale, 0, GROUP_TYPE::GAMETITLE_TEXT);

	delete pAni;

}


