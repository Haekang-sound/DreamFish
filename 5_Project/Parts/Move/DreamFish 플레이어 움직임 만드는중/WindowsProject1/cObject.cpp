#include "pch.h"
#include "cObject.h"

#include "CCollider.h"

cObject::cObject()
	:m_vPos{}, m_vScale{}, m_pCollider(nullptr), m_bAlive(true), IsTouch(TRUE)
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
	Rectangle(_dc, (int)(m_vPos.x - m_vScale.x / 2.f), (int)(m_vPos.y - m_vScale.y / 2.f)
		, (int)(m_vPos.x + m_vScale.x / 2.f), (int)(m_vPos.y + m_vScale.y / 2.f));

	ComPonentRender(_dc);
}

void cObject::ComPonentRender(HDC _dc)
{
	if (nullptr != m_pCollider)
	{
		m_pCollider->render(_dc);
	}
}

void cObject::PastSetPos(Vec2 _vpos)
{
	//p_vPos = m_vPos;

}

void cObject::SetPos(Vec2 _vPos)
{
	if (m_pCollider)
	{
		int plz = m_pCollider->GetiCol();
		if (plz&&IsTouch)
		{
			m_vPos = p_vPos;
			IsTouch = FALSE;
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

void cObject::CreateCollider()
{
	m_pCollider = new CCollider;
	m_pCollider->m_pOwner = this;
}
