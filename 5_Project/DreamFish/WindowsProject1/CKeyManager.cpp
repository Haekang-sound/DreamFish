#include "pch.h"
#include "CKeyManager.h"
#include "CCamera.h"
#include "CGameProcess.h"

int g_arrVK[(int)KEY::LAST] =
{
	VK_LEFT,
	VK_RIGHT,
	VK_UP,
	VK_DOWN,

	'Q',
	'W',
	'E',
	'R',
	'T',
	'Y',
	'U',
	'I',
	'O',
	'P',
	'A',
	'S',
	'D',
	'F',
	'G',
	'H',
	'J',
	'K',
	'L',

	VK_MENU,
	VK_LCONTROL,
	VK_LSHIFT,
	VK_SPACE,
	VK_RETURN,
	VK_ESCAPE,
	VK_LBUTTON,
	VK_RBUTTON,
};

CKeyManager::CKeyManager()
{

}
CKeyManager::~CKeyManager()
{

}

void CKeyManager::Initialize()
{
	for (int i = 0; i < (int)KEY::LAST; ++i)
	{
		m_vecKey.push_back(tKeyInfo{ KEY_STATE::NONE, false });
	}

	m_vecKey[(int)KEY::LEFT].eState;
	m_vecKey[(int)KEY::LEFT].bPrevPush;
}

void CKeyManager::Update()
{
	// 윈도우 포커싱 알아내기
	//HWND hMainWnd = CCore::GetInstance()->GetMainHwnd();
	HWND hWnd = GetFocus();

	
	// 윈도우가 포커싱 중 일때
	if(nullptr != hWnd)
	{
		GetCursorPos(&m_pt);
		ScreenToClient(hWnd, &m_pt);
		Vecor2 point = m_pt;
		m_vCurMousePos = point;
		RECT rtRect;
		/*ClientToScreen(hWnd, &m_pt);
		point = m_pt;
		m_vSetMousePos = point;*/
		GetClientRect(hWnd, &rtRect);
		ClipCursor(&rtRect);

		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			// 키가 눌려있따.
			if(GetAsyncKeyState(g_arrVK[i]) & 0x8000) 
			{
				if (m_vecKey[i].bPrevPush)
				{
					m_vecKey[i].eState = KEY_STATE::HOLD;
				}
				else
				{
					// 이전에 안 눌렸다.
					m_vecKey[i].eState = KEY_STATE::TAP;
				}

				m_vecKey[i].bPrevPush = true;
			}
			else
			{
				if (m_vecKey[i].bPrevPush)
				{
					// 이전에 눌려 있었다.
					m_vecKey[i].eState = KEY_STATE::AWAY;
				}
				else
				{
					// 이전에 눌려 있었다.
					m_vecKey[i].eState = KEY_STATE::NONE;
				}

				m_vecKey[i].bPrevPush = false;
			}
		}
	}
	else
	{
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			m_vecKey[i].bPrevPush = false;

			if (KEY_STATE::TAP == m_vecKey[i].eState || KEY_STATE::HOLD == m_vecKey[i].eState)
			{
				m_vecKey[i].eState = KEY_STATE::AWAY;
			}
			else if (KEY_STATE::AWAY == m_vecKey[i].eState)
			{
				m_vecKey[i].eState = KEY_STATE::NONE;
			}
			
		}
	}
}

void CKeyManager::SetCursorPosition()
{
	HWND hWnd = GetFocus();


	// 윈도우가 포커싱 중 일때
	if (nullptr != hWnd)
	{
		GetCursorPos(&m_pt);
		ScreenToClient(hWnd, &m_pt);
		Vecor2 point = m_pt;

		SetCursorPos(CCamera::GetInstance()->GetRenderPos(point).x, CCamera::GetInstance()->GetRenderPos(point).y);
		m_vCurMousePos = point;
		RECT rtRect;
		/*ClientToScreen(hWnd, &m_pt);
		point = m_pt;
		m_vSetMousePos = point;*/
		GetClientRect(hWnd, &rtRect);
		ClipCursor(&rtRect);
	}
}
