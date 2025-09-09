#include "pch.h"
#include "CCamera.h"
#include "CCore.h"
#include"cObject.h"

CCamera::CCamera()
	:m_pTargetObj(nullptr)
{}
CCamera::~CCamera()
{

}

void CCamera::update()
{
	if (m_pTargetObj)
	{
		m_vLookAt = m_pTargetObj->GetPos();
	}

	CalDiff();
}

void CCamera::CalDiff()
{
	Vec2 vResolutiuon = CCore::GetInst()->GetResolution();
	Vec2 vCenter = vResolutiuon / 2;

	m_vLookAt;
	m_vDiff = m_vLookAt - vCenter; 
}
