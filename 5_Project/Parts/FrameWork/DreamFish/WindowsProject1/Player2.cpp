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
	// Texture 로딩하기
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

	// 위로 이동
	if (KEY_HOLD(KEY::UP))
	{
		vPos.y -= 200.f * fDT;
	}

	// 아래로 이동
	if (KEY_HOLD(KEY::DOWN))
	{
		vPos.y += 200.f * fDT;
	}

	// 왼쪽으로 이동
	if (KEY_HOLD(KEY::LEFT))
	{
		vPos.x -= 200.f * fDT;
	}

	// 오른쪽으로 이동
	if (KEY_HOLD(KEY::RIGHT))
	{
		vPos.x += 200.f * fDT;
	}

	// 18강에 미사일 쏘는거 나온다. 필요없어서 안했다.
	// 19강에 세타를 사용해서 cos, sin을 사용했다.
	// 20강에 벡터를 사용해서 벡터의 정규화 윈도우 pos는 좌표 assert 구현


	SetPos(vPos);
}

void Player2::render(HDC _dc)
{
	// unsiged int 안하는 이유 이미지는 음수도 있기 때문에 상관이 없다. UINT 는 음수로 가게 되는 순간 UINT의 최대값이 출력된다.
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

	// 컴포넌트 (충돌체, etc
	ComPonentRender(_dc);
}

