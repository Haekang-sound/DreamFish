#include "pch.h"
#include "cTimeMgr.h"
#include "CCore.h"

cTimeMgr::cTimeMgr()
	:m_llCurCount{}, m_llFrequency{}, m_iCallCount(0), m_llPrevCount{},
	m_dDT(0.), m_dAcc(0.)

{

}
cTimeMgr::~cTimeMgr()
{

}

void cTimeMgr::init()
{
	// 현재 카운트
	QueryPerformanceCounter(&m_llPrevCount);
	
	// 초당 카운트 횟수
	QueryPerformanceFrequency(&m_llFrequency);

}

void cTimeMgr::update()
{
	QueryPerformanceCounter(&m_llCurCount);

	m_dDT = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart)/(double)m_llFrequency.QuadPart;

	m_llPrevCount = m_llCurCount;

#ifdef _DEBUG
	if (m_dDT > (1.0 / 60.0))
	{
		m_dDT = 1.0 / 60.0;
	}
#endif
}

void cTimeMgr::render()
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
		SetWindowText(CCore::GetInst()->GetMainHwnd(), szBuffer);
	}
}
