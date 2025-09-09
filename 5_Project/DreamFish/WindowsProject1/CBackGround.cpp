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
	

	//	배경이동을 위함
	Vecor2 vPos = CCamera::GetInstance()->GetRenderPos(GetPos());
	SetRenderPos(vPos);

	// 배경출력
	BitBlt(_dc, (int)vPos.x, (int)vPos.y, size.x, size.y, m_pTex->GetDC(), 0, 0, SRCCOPY);
}

void CBackGround::SetTexture(const wstring& _strKey, const wstring& _strRelativePath)
{
	m_pTex = CResManager::GetInstance()->LoadTexture(_strKey, _strRelativePath);
}

