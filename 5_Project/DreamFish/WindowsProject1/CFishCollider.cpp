#include "pch.h"
#include "CFishCollider.h"

#include "CObject.h"
#include "CGameProcess.h"

#include "CSelectGDI.h"
#include "CCamera.h"
#include "CKeyManager.h"

void CFishCollider::FinalUpdate()
{
	// object에 따라 움직인다.
	Vecor2  vObjectPos = m_pOwner->GetPos();
	m_vFinalPos = CCamera::GetInstance()->GetRealPos(vObjectPos + m_vOffsetPos);

	assert(0 <= m_iCol);
}

void CFishCollider::OnCollisionEnter()
{
	
	
}

void CFishCollider::Render(HDC _dc)
{
	PEN_TYPE ePen = PEN_TYPE::GREEN;
	Vecor2 scale = GetScale();
	UINT m_iCol = GetCol();
	if (m_iCol)
	{
		ePen = PEN_TYPE::RED;
	}

	CSelectGDI p(_dc, ePen);
	CSelectGDI b(_dc, BRUSH_TYPE::HOLLOW);
	Vecor2 vRenderPos = m_pOwner->GetPos();

// 	Rectangle(_dc,
// 		(int)(vRenderPos.x - scale.x / 2.f),
// 		(int)(vRenderPos.y - scale.y / 2.f),
// 		(int)(vRenderPos.x + scale.x / 2.f),
// 		(int)(vRenderPos.y + scale.y / 2.f));
}

CFishCollider::CFishCollider()
{
	
}
CFishCollider::~CFishCollider()
{

}