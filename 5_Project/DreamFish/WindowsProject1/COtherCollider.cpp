#include "pch.h"
#include "COtherCollider.h"

#include "CObject.h"
#include "CGameProcess.h"

#include "CSelectGDI.h"
#include "CCamera.h"
void COtherCollider::Render(HDC _dc)
{
	PEN_TYPE ePen = PEN_TYPE::GREEN;
	Vecor2 scale = GetScale();
	UINT m_iCol = GetCol();
	Vecor2 m_vFinalPos = GetFinalPos();
	if (m_iCol)
	{
		ePen = PEN_TYPE::RED;
	}

	CSelectGDI p(_dc, ePen);
	CSelectGDI b(_dc, BRUSH_TYPE::HOLLOW);
	Vecor2 vRenderPos = CCamera::GetInstance()->GetRenderPos(m_vFinalPos);
// 
// 	Rectangle(_dc,
// 		(int)(vRenderPos.x - scale.x / 2.f),
// 		(int)(vRenderPos.y - scale.y / 2.f),
// 		(int)(vRenderPos.x + scale.x / 2.f),
// 		(int)(vRenderPos.y + scale.y / 2.f));
}
