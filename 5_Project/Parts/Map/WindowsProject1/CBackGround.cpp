#include "pch.h"
#include "CBackGround.h"

#include "CResManager.h"
#include "CTexture.h"

// �ִϸ��̼� �ʿ�
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
	// �ý��� ��� �� ��������
	m_pTex = CResManager::GetInstance()->LoadTexture(L"BackgroundTex", L"texture\\BackGround01.bmp");

	//	����̵��� ����
	Vecor2 vPos = CCamera::GetInstance()->GetRenderPos(GetPos());
	SetRenderPos(vPos);

	// ������
	BitBlt(_dc, (int)vPos.x, (int)vPos.y, 3000, 3000, m_pTex->GetDC(), 0, 0, SRCCOPY);
}

