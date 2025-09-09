#include "pch.h"
#include "cObject.h"

#include "CCollider.h"

cObject::cObject()
	:m_vPos{}, m_vScale{}, m_pCollider(nullptr)
{

}

cObject::~cObject()
{
	if (nullptr != m_pCollider)
		delete m_pCollider;
}

void cObject::finalupdate()
{
	if (m_pCollider)
	{
		m_pCollider->finalupdate();
	}
}

void cObject::render(HDC _dc)
{
	Vec2 vRenderPos = CCamera::GetInst()->GetRenderPos(m_vPos);
	Rectangle(_dc, (int)(vRenderPos.x - m_vScale.x / 2.f), (int)(vRenderPos.y - m_vScale.y / 2.f)
		, (int)(vRenderPos.x + m_vScale.x / 2.f), (int)(vRenderPos.y + m_vScale.y / 2.f));

	ComPonentRender(_dc);
}

void cObject::ComPonentRender(HDC _dc)
{
	if (nullptr != m_pCollider)
	{
		m_pCollider->render(_dc);
	}
}

void cObject::SetPos(Vec2 _vPos)
{
	if (m_pCollider) 
	{
		int plz = m_pCollider->GetiCol();
		if (plz)
		{
			m_vPos = p_vPos;
		}
		else
		{
			p_vPos = m_vPos; // 현재 위치를 이전 위치로 저장
			m_vPos = _vPos;
		}
	}
	else
	{
		m_vPos = _vPos;
	}

}

void cObject::PastSetPos(Vec2 _vpos)
{
	p_vPos = m_vPos;

}

void cObject::CreateCollider()
{
	m_pCollider = new CCollider;
	m_pCollider->m_pOwner = this;
}
