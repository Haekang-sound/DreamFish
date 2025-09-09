#include "pch.h"
#include "FishCollider.h"

#include "cObject.h"
#include "CCore.h"

#include "SelectGDI.h"
#include "CCamera.h"

void FishCollider::render(HDC _dc)
{
	PEN_TYPE ePen = PEN_TYPE::GREEN;
	Vec2 scale = GetScale();
	UINT m_iCol = GetCol();
	if (m_iCol)
	{
		ePen = PEN_TYPE::RED;
	}

	SelectGDI p(_dc, ePen);
	SelectGDI b(_dc, BRUSH_TYPE::HOLLOW);
	Vec2 vRenderPos = GetFinalPos();

	Rectangle(_dc,
		(int)(vRenderPos.x - scale.x / 2.f),
		(int)(vRenderPos.y - scale.y / 2.f),
		(int)(vRenderPos.x + scale.x / 2.f),
		(int)(vRenderPos.y + scale.y / 2.f));
}

FishCollider::FishCollider()
{
	
}
FishCollider::~FishCollider()
{

}