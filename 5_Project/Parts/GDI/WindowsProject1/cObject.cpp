#include "pch.h"
#include "cObject.h"

#include "CAnimator.h"
#include "CCollider.h"

cObject::cObject()
	:m_vPos{}
	, m_vScale{}
	, m_pCollider(nullptr)
	, m_pAnimator(nullptr)
	, m_bAlive(true)
{

}

//35강 복사 생성자인데 우리 게임에 필요할까??
cObject::cObject(const cObject& _origin)
	: m_strName(_origin.m_strName)
	, m_vPos(_origin.m_vPos)
	, m_vScale(_origin.m_vScale)
	, m_pCollider(nullptr)
	, m_pAnimator(nullptr)
	, m_bAlive(true)
{
	if(_origin.m_pCollider)
	{
		m_pCollider = new CCollider(*_origin.m_pCollider);
		m_pCollider->m_pOwner = this;
	}

	if (_origin.m_pAnimator)
	{
		m_pAnimator = new CAnimator(*_origin.m_pAnimator);
		m_pAnimator->m_pOwner = this;
		
	}
}

cObject::~cObject()
{
	if (nullptr != m_pCollider)
		delete m_pCollider;

	if (nullptr != m_pAnimator)
		delete m_pAnimator;

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

	if (nullptr != m_pAnimator)
	{
		m_pAnimator->render(_dc);
	}
}

void cObject::CreateCollider()
{
	m_pCollider = new CCollider;
	m_pCollider->m_pOwner = this;
}

void cObject::CreateAnimator()
{
	m_pAnimator = new CAnimator;
	m_pAnimator->m_pOwner = this;
}
