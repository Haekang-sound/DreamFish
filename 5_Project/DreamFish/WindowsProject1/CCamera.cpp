#include "pch.h"
#include "CCamera.h"
#include "CGameProcess.h"
#include "CObject.h"

CCamera::CCamera()
	:m_pTargetObj(nullptr)
{}
CCamera::~CCamera()
{

}

void CCamera::Update()
{
	Vecor2 fPos = m_pTargetObj->GetPos();
	Vecor2 fishPos = m_pTargetObj2->GetPos();


	if (m_pTargetObj&&m_pTargetObj2)
	{
		fishPos = fishPos - fPos;
		fishPos = fishPos + m_vDiff;
		m_vLookAt = fPos+(fishPos / 2);
		if ((m_vLookAt - fPos).Length() > 300)
			m_vLookAt = (fPos + (m_vLookAt - fPos).Normalize() * 300);
	}
	/*wchar_t szBuffer[255] = {};
	swprintf_s(szBuffer, L"camerapos : %f playerpos : (%f,%f) fishpos : (%f,%f) ", m_vLookAt.x, fPos.x, fPos.y, fishPos.x,fishPos.y);
	SetWindowText(CGameProcess::GetInstance()->GetMainHwnd(), szBuffer);*/
	
	CalDiff();
}

void CCamera::CalDiff()
{
	Vecor2 vResolutiuon = CGameProcess::GetInstance()->GetResolution();
	Vecor2 vCenter = vResolutiuon / 2;

	m_vLookAt;
	m_vDiff = m_vLookAt - vCenter; 
}
