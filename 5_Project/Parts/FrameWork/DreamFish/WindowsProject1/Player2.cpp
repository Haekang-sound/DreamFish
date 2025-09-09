#include "pch.h"
#include "Player2.h"

#include "CKeyMgr.h"
#include "cTimeMgr.h"

#include "CScene.h"
#include "CSceneMgr.h"

#include "CResMgr.h"
#include "CTexture.h"

#include "CCollider.h"

Player2::Player2()
	:m_pTex2(nullptr)
{
	// Texture �ε��ϱ�
	m_pTex2 = CResMgr::GetInst()->LoadTexture(L"PlayerTex", L"texture\\mokoko.bmp");
	//m_pTex = CResMgr::GetInst()->LoadTexture(L"PlayerTex", L"texture\\mokoko.bmp");


	CreateCollider();
	GetCollider()->SetScale(Vec2(100.f, 100.f));

}

Player2::~Player2()
{

}

void Player2::update()
{
	Vec2 vPos = GetPos();

	// ���� �̵�
	if (KEY_HOLD(KEY::UP))
	{
		vPos.y -= 200.f * fDT;
	}

	// �Ʒ��� �̵�
	if (KEY_HOLD(KEY::DOWN))
	{
		vPos.y += 200.f * fDT;
	}

	// �������� �̵�
	if (KEY_HOLD(KEY::LEFT))
	{
		vPos.x -= 200.f * fDT;
	}

	// ���������� �̵�
	if (KEY_HOLD(KEY::RIGHT))
	{
		vPos.x += 200.f * fDT;
	}

	// 18���� �̻��� ��°� ���´�. �ʿ��� ���ߴ�.
	// 19���� ��Ÿ�� ����ؼ� cos, sin�� ����ߴ�.
	// 20���� ���͸� ����ؼ� ������ ����ȭ ������ pos�� ��ǥ assert ����


	SetPos(vPos);
}

void Player2::render(HDC _dc)
{
	// unsiged int ���ϴ� ���� �̹����� ������ �ֱ� ������ ����� ����. UINT �� ������ ���� �Ǵ� ���� UINT�� �ִ밪�� ��µȴ�.
	int iWidth = (int)m_pTex2->Width();
	int iHeight = (int)m_pTex2->Height();

	Vec2 vPos = GetPos();

	//BitBlt(_dc, int(vPos.x - (float)(iWidth / 2)), 
	//			int(vPos.y - (float)(iHeight / 2)),
	//			iWidth, iHeight, m_pTex->GetDC(), 0, 0, SRCCOPY);

	TransparentBlt(_dc, int(vPos.x - (float)(iWidth / 2)),
		int(vPos.y - (float)(iHeight / 2)),
		iWidth, iHeight, m_pTex2->GetDC(), 0, 0, iWidth, iHeight,
		RGB(255, 0, 255));

	// ������Ʈ (�浹ü, etc
	ComPonentRender(_dc);
}

