#include "pch.h"
#include "CTexture.h"

#include "CGameProcess.h"

CTexture::CTexture()
	:m_hBit(0), m_dc(0), m_bitInfo{}
{

}

CTexture::~CTexture()
{
	DeleteDC(m_dc);
	DeleteObject(m_hBit);
}

void CTexture::Load(const wstring& _strFilePath)
{
	// LOADIMAGE 검색하면 나온다 가장 기본이 되는 것은 이것과 같다.
	// 파일로 부터 로딩한 데이터를 비트맵으로 생성
	m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	assert(m_hBit);

	// 비트맵과 연결할 DC
	m_dc = CreateCompatibleDC(CGameProcess::GetInstance()->GetMainDC());

	// 비트맵과 DC 연결
	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_dc, m_hBit);
	DeleteObject(hPrevBit);

	// 비트맵 정보
	GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);
}