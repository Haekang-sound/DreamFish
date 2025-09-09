#include "pch.h"
#include "CBackGround.h"

#include "CResManager.h"
#include "CTexture.h"

// 애니메이션 필요
//#include "CAnimator.h"

CBackGround::CBackGround()
	:m_pTex(nullptr)
{
}

CBackGround::~CBackGround()
{
}

void CBackGround::Update()
{
}

void CBackGround::Render(HDC _dc)
{
	// 택스쳐 등록 및 가져오기
	m_pTex = CResManager::GetInstance()->LoadTexture(L"BackgroundTex", L"texture\\BackGround01.bmp");

	//	배경이동을 위함
	Vecor2 vPos = CCamera::GetInstance()->GetRenderPos(GetPos());
	SetRenderPos(vPos);

	// 배경출력
	BitBlt(_dc, (int)vPos.x, (int)vPos.y, 3000, 3000, m_pTex->GetDC(), 0, 0, SRCCOPY);
}

