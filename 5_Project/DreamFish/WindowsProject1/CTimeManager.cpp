#include "pch.h"
#include "CTimeManager.h"
#include "CGameProcess.h"

// 일시정지
#include "CKeyManager.h"

CTimeManager::CTimeManager()
	:m_llCurCount{}, m_llFrequency{}, m_iCallCount(0), m_llPrevCount{},
	m_dDT(0.), m_dAcc(0.)

{

}
CTimeManager::~CTimeManager()
{

}

void CTimeManager::Initialize()
{
	// 현재 카운트
	QueryPerformanceCounter(&m_llPrevCount);
	
	// 초당 카운트 횟수
	QueryPerformanceFrequency(&m_llFrequency);

}

void CTimeManager::Update()
{
		QueryPerformanceCounter(&m_llCurCount);

		m_dDT = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / (double)m_llFrequency.QuadPart;

		m_llPrevCount = m_llCurCount;

#ifdef _DEBUG
		if (m_dDT > (1. / 60.))
		{
			m_dDT = (1. / 60.);
		}

#endif




}

void CTimeManager::Render()
{
	++m_iCallCount;
	m_dAcc += m_dDT;

	if (m_dAcc >= 1.)
	{
		m_iFPS = m_iCallCount;
		m_dAcc = 0.;
		m_iCallCount = 0;

		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS : %d , DT : %f", m_iFPS, m_dDT);
		SetWindowText(CGameProcess::GetInstance()->GetMainHwnd(), szBuffer);
	}
}
