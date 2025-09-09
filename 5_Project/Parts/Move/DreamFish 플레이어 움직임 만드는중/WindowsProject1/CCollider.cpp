#include "pch.h"
#include "CCollider.h"

#include "cObject.h"
#include "CCore.h"

#include "SelectGDI.h"

UINT CCollider::g_iNextID = 0;

CCollider::CCollider()
	: m_pOwner(nullptr), m_iID(g_iNextID++), m_iCol(0)
{

}

CCollider::CCollider(const CCollider& _origin)
	: m_pOwner(nullptr), m_vOffsetPos(_origin.m_vOffsetPos),
	  m_vScale(_origin.m_vScale), m_iID(g_iNextID++)
{

}

CCollider::~CCollider()
{

}

void CCollider::finalupdate()
{
	// object에 따라 움직인다.
	Vec2  vObjectPos = m_pOwner->GetPos();
	m_vFinalPos = vObjectPos + m_vOffsetPos;

	assert(0 <= m_iCol);
}

void CCollider::render(HDC _dc)
{
	PEN_TYPE ePen = PEN_TYPE::GREEN;

	if (m_iCol)
	{
		ePen = PEN_TYPE::RED;
	}

	SelectGDI p(_dc, ePen);
	SelectGDI b(_dc, BRUSH_TYPE::HOLLOW);

	Rectangle(_dc,
		(int)(m_vFinalPos.x - m_vScale.x / 2.f),
		(int)(m_vFinalPos.y - m_vScale.y / 2.f),
		(int)(m_vFinalPos.x + m_vScale.x / 2.f),
		(int)(m_vFinalPos.y + m_vScale.y / 2.f));
}

void CCollider::OnCollision(CCollider* _pOther)
{
	m_pOwner->OnCollision(_pOther);
}

void CCollider::OnCollisionEnter(CCollider* _pOther)
{
	// true false가 아닌 이유는 여러개가 충돌했을 때 on off가 될 것이기 때문에 ++로 한다.
	m_pOwner->OnCollisionEnter(_pOther);
	++m_iCol;
}

void CCollider::OnCollisionExit(CCollider* _pOther)
{
	m_pOwner->OnCollisionExit(_pOther);
	--m_iCol;
}
