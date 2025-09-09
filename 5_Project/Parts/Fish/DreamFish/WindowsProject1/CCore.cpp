#include "pch.h"
#include "CCore.h"

#include "cTimeMgr.h"
#include "CKeyMgr.h"
#include "CSceneMgr.h"
#include "CPathMgr.h"
#include "CCollisionMgr.h"
#include "CCamera.h"
CCore::CCore()
	: m_hWnd(0), m_ptResolution{}, m_hDC(0), m_hBit(0), m_memDC(0), m_arrBrush{}, m_arrPen{}
{


}

CCore::~CCore()
{
	ReleaseDC(m_hWnd, m_hDC);

	DeleteObject(m_memDC);
	DeleteObject(m_hBit);

	for (int i = 0; i < (UINT)PEN_TYPE::END; ++i)
	{
		DeleteObject(m_arrPen[i]);
	}
}

int CCore::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;
	
	// 해상도에 맞게 윈도우 크기 조정
	RECT rt = {0, 0, m_ptResolution.x, m_ptResolution.y};
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(m_hWnd, nullptr, 0, 0, rt.right - rt.left, rt.bottom - rt.top, 0);

	m_hDC = GetDC(m_hWnd);

	// 이중 버퍼링 용도의 비트맵과 DC 를 만든다.
	m_hBit = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);
	m_memDC = CreateCompatibleDC(m_hDC);

	HBITMAP hOldbit = (HBITMAP)SelectObject(m_memDC, m_hBit);
	DeleteObject(hOldbit);

	// 자주 사용할 펜 및 브러쉬 생성
	CreateBrushPen();

	// Manager 초기화
	CPathMgr::GetInst()->init();
	cTimeMgr::GetInst()->init();
	CKeyMgr::GetInst()->init();
	CSceneMgr::GetInst()->init();

	return S_OK;
}

void CCore::progress()
{
	// Manager Update
	cTimeMgr::GetInst()->update();
	CKeyMgr::GetInst()->update();

	CSceneMgr::GetInst()->update();
	CCollisionMgr::GetInst()->update();
	CCamera::GetInst()->update();
	Rectangle(m_memDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);
	
	CSceneMgr::GetInst()->render(m_memDC);
	//cTimeMgr::GetInst()->render();
	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y, m_memDC, 0, 0, SRCCOPY);


}

void CCore::CreateBrushPen()
{
	// Hollow brush (WINDOW가 알아서 Delete 시켜준다.)
	m_arrBrush[(UINT)BRUSH_TYPE::HOLLOW] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);

	// Red Green Blue pen (WINDOW가 알아서 안 지워주기 때문에 지워야 한다.)
	m_arrPen[(UINT)PEN_TYPE::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(UINT)PEN_TYPE::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_arrPen[(UINT)PEN_TYPE::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
}

