#include "pch.h"
#include "cObject.h"

#include "CCollider.h"
#include "FishCollider.h"
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

void cObject::CreateCollider()
{
	m_pCollider = new CCollider;
	m_pCollider->m_pOwner = this;
}
void cObject::CreateFishCollider()
{
	m_pCollider = new FishCollider;
	m_pCollider->SetOwner( this);
}
