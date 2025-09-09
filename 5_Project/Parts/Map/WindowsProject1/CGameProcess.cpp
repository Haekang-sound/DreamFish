#include "pch.h"
#include "CGameProcess.h"

#include "CTimeManager.h"
#include "CKeyManager.h"
#include "CSceneManager.h"
#include "CPathManager.h"
#include "CCollisionManager.h"
#include "CCamera.h"
#include "CEventManager.h"
#include "CCamera.h"
#include "CSoundManager.h"
#include "CTitle.h"

#include "CScene.h"

#include "CButtonQuit.h"
#include "CButtonStart.h"



CGameProcess::CGameProcess()
	: m_hWnd(0), m_ptResolution{}, m_hDC(0), m_hBit(0), m_memDC(0), m_arrBrush{}, m_arrPen{}
{


}

CGameProcess::~CGameProcess()
{
	ReleaseDC(m_hWnd, m_hDC);

	DeleteObject(m_memDC);
	DeleteObject(m_hBit);

	for (int i = 0; i < (UINT)PEN_TYPE::END; ++i)
	{
		DeleteObject(m_arrPen[i]);
	}
}
int CGameProcess::Initialize(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	// 해상도에 맞게 윈도우 크기 조정
	RECT rt = { 0, 0, m_ptResolution.x, m_ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	m_hDC = GetDC(m_hWnd);

	// 이중 버퍼링 용도의 비트맵과 DC 를 만든다.
	m_hBit = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);
	m_memDC = CreateCompatibleDC(m_hDC);

	HBITMAP hOldbit = (HBITMAP)SelectObject(m_memDC, m_hBit);
	DeleteObject(hOldbit);

	// 자주 사용할 펜 및 브러쉬 생성
	CreateBrushPen();

	// Manager 초기화
	CSoundManager::GetInstance()->SoundSetUp();
	CPathManager::GetInstance()->Initialize();
	CTimeManager::GetInstance()->Initialize();
	CKeyManager::GetInstance()->Initialize();
	CSceneManager::GetInstance()->Initialize();

	return S_OK;
}

void CGameProcess::Progress()
{

	// 키값 업데이트
	CKeyManager::GetInstance()->Update();
	static bool paused = false;
	if (KEY_AWAY(KEY::ESC))
	{
		paused = !paused; // 일시정지 상태를 토글
	}

	if (paused)
	{
		// 시간 업데이트
		// 일시정지
		CScene* CScene = new CTitle;
		CScene->Update();
		delete CScene;

	}
	else
	{
		/// Update
		// 시간 업데이트
		CTimeManager::GetInstance()->Update();
		// Scene 업데이트
		CSceneManager::GetInstance()->Update();
		// 충돌 체크
		CCollisionManager::GetInstance()->Update();
		// 카메라
		CCamera::GetInstance()->Update();


		/// Render 
		Rectangle(m_memDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);
		CSceneManager::GetInstance()->Render(m_memDC);
		//cTimeMgr::GetInstance()->render();
		BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y, m_memDC, 0, 0, SRCCOPY);
		//CTimeManager::GetInstance()->Render();

		/// 이벤트 지연 처리
		CEventManager::GetInstance()->Update();

	}


// 
// 	// 시간 업데이트
// 	CTimeManager::GetInstance()->Update();
// 
// 	CCamera::GetInstance()->Update();
// 
// 
// 
// 	// Scene 업데이트
// 	CSceneManager::GetInstance()->Update();
// 	// 충돌 체크
// 	CCollisionManager::GetInstance()->Update();
// 	CCamera::GetInstance()->Update();
// 	// Render
// 	Rectangle(m_memDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);
// 	
// 	CSceneManager::GetInstance()->Render(m_memDC);
// 	//cTimeMgr::GetInstance()->render();
// 	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y, m_memDC, 0, 0, SRCCOPY);
// 
// 
// 
// 	CTimeManager::GetInstance()->Render();
// 	
// 	// 이벤트 지연 처리
// 	CEventManager::GetInstance()->Update();
	
}

void CGameProcess::CreateBrushPen()
{
	// Hollow brush (WINDOW가 알아서 Delete 시켜준다.)
	m_arrBrush[(UINT)BRUSH_TYPE::HOLLOW] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);

	// Red Green Blue pen (WINDOW가 알아서 안 지워주기 때문에 지워야 한다.)
	m_arrPen[(UINT)PEN_TYPE::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(UINT)PEN_TYPE::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_arrPen[(UINT)PEN_TYPE::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
}

