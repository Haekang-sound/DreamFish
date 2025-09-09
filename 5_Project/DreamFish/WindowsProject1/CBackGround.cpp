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
	

	//	����̵��� ����
	Vecor2 vPos = CCamera::GetInstance()->GetRenderPos(GetPos());
	SetRenderPos(vPos);

	// ������
	BitBlt(_dc, (int)vPos.x, (int)vPos.y, size.x, size.y, m_pTex->GetDC(), 0, 0, SRCCOPY);
}

void CBackGround::SetTexture(const wstring& _strKey, const wstring& _strRelativePath)
{
	m_pTex = CResManager::GetInstance()->LoadTexture(_strKey, _strRelativePath);
}

