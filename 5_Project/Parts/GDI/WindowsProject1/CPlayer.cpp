#include "pch.h"
#include "CPlayer.h"

#include "CKeyMgr.h"
#include "cTimeMgr.h"

#include "CScene.h"
#include "CSceneMgr.h"

#include "CResMgr.h"
#include "CTexture.h"
#include "CCollider.h"
#include "CAnimator.h"

CPlayer::CPlayer()
	:m_pTex(nullptr)
{
	// Texture �ε��ϱ�
	//m_pTex = CResMgr::GetInst()->LoadTexture(L"PlayerTex", L"texture\\mokoko.bmp");

	CreateCollider();
	// �ǰ� ������ ��ġ�� ���� �� �� �ִ�.
	GetCollider()->SetOffsetPos(Vec2(0.f, 50.f));
	// �ǰ� ������ ������ �� �ִ�.
	GetCollider()->SetScale(Vec2(180.f, 200.f));

	// Texture �ε��ϱ�
	m_pTex = CResMgr::GetInst()->LoadTexture(L"PlayerTex", L"texture\\image.bmp");
	CreateAnimator();
	GetAnimator()->CreateAnimation(m_pTex, Vec2(0.f, 260.f), Vec2(60.f, 100.f), Vec2(60.f, 0.f));

}

CPlayer::~CPlayer()
{
	
}

void CPlayer::update()
{
	Vec2 vPos = GetPos();

	// ���� �̵�
	if (KEY_HOLD(KEY::W))
	{
		vPos.y -= 200.f * fDT;
	}

	// �Ʒ��� �̵�
	if (KEY_HOLD(KEY::S))
	{
		vPos.y += 200.f * fDT;
	}

	// �������� �̵�
	if (KEY_HOLD(KEY::A))
	{
		vPos.x -= 200.f * fDT;
	}

	// ���������� �̵�
	if (KEY_HOLD(KEY::D))
	{
		vPos.x += 200.f * fDT;
	}

	// 18���� �̻��� ��°� ���´�. �ʿ��� ���ߴ�.
	// 19���� ��Ÿ�� ����ؼ� cos, sin�� ����ߴ�.
	// 20���� ���͸� ����ؼ� ������ ����ȭ ������ pos�� ��ǥ assert ����


	SetPos(vPos);
}

void CPlayer::render(HDC _dc)
{
	// unsiged int ���ϴ� ���� �̹����� ������ �ֱ� ������ ����� ����. UINT �� ������ ���� �Ǵ� ���� UINT�� �ִ밪�� ��µȴ�.
	int iWidth =(int)m_pTex->Width();
	int iHeight=(int)m_pTex->Height();

	Vec2 vPos = GetPos();
	
	//BitBlt(_dc, int(vPos.x - (float)(iWidth / 2)), 
	//			int(vPos.y - (float)(iHeight / 2)),
	//			iWidth, iHeight, m_pTex->GetDC(), 0, 0, SRCCOPY);

	TransparentBlt(_dc, int(vPos.x - (float)(iWidth / 2)),
		int(vPos.y - (float)(iHeight / 2)),
		iWidth, iHeight, m_pTex->GetDC(), 0, 0, iWidth, iHeight,
		RGB(0,0,255));

	// ������Ʈ (�浹ü, etc
	ComPonentRender(_dc);
}

