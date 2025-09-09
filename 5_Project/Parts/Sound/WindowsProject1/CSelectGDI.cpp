#include "pch.h"
#include "CSelectGDI.h"
#include "CGameProcess.h"


CSelectGDI::CSelectGDI(HDC _dc, PEN_TYPE _ePenType)
	:m_hDc(_dc), m_hDefaultPen(nullptr), m_hDefaultBrush(nullptr)
{
	HPEN hPen = CGameProcess::GetInstance()->GetPen(_ePenType);
	m_hDefaultPen = (HPEN)SelectObject(_dc, hPen);
}

CSelectGDI::CSelectGDI(HDC _dc, BRUSH_TYPE _eBrushType)
	:m_hDc(_dc), m_hDefaultPen(nullptr), m_hDefaultBrush(nullptr)
{
	HBRUSH hBrush = CGameProcess::GetInstance()->GetBrush(_eBrushType);
	m_hDefaultBrush = (HBRUSH)SelectObject(_dc, hBrush);
}

CSelectGDI::~CSelectGDI()
{
	SelectObject(m_hDc, m_hDefaultPen);
	SelectObject(m_hDc, m_hDefaultBrush);
}
