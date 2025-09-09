#include "pch.h"
#include "CObject.h"

#include "CCollider.h"
#include "CFishCollider.h"

CObject::CObject()
	:m_vPos{}, m_vScale{}, m_pCollider(nullptr), m_bAlive(true), IsTouch(TRUE)
{

}

CObject::~CObject()
{
	if (nullptr != m_pCollider)
		delete m_pCollider;
}

void CObject::FinalUpdate()
{
	if (m_pCollider)
	{
		m_pCollider->FinalUpdate();
	}
}

void CObject::Render(HDC _dc)
{
	Vecor2 vRenderPos = CCamera::GetInstance()->GetRenderPos(m_vPos);
	Rectangle(_dc, (int)(vRenderPos.x - m_vScale.x / 2.f), (int)(vRenderPos.y - m_vScale.y / 2.f)
		, (int)(vRenderPos.x + m_vScale.x / 2.f), (int)(vRenderPos.y + m_vScale.y / 2.f));

	Rectangle(_dc, 
		(int)(vRenderPos.x - m_vScale.x / 2.f), 
		(int)(vRenderPos.y - m_vScale.y / 2.f), 
		(int)(vRenderPos.x + m_vScale.x / 2.f), 
		(int)(vRenderPos.y + m_vScale.y / 2.f));

	ComPonentRender(_dc);
}

void CObject::ComPonentRender(HDC _dc)
{
	if (nullptr != m_pCollider)
	{
		m_pCollider->Render(_dc);
	}
}

void CObject::SetPos(Vecor2 _vPos)
{
	
	p_vPos = m_vPos; // 현재 위치를 이전 위치
	m_vPos = _vPos;
	

}
void CObject::CreateCollider()
{
	m_pCollider = new CCollider;
	m_pCollider->m_pOwner = this;
}
void CObject::CreateFishCollider()
{
	m_pCollider = new CFishCollider;
	m_pCollider->SetOwner(this);
}