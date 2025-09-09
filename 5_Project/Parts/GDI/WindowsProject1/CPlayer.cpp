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
	// Texture 로딩하기
	//m_pTex = CResMgr::GetInst()->LoadTexture(L"PlayerTex", L"texture\\mokoko.bmp");

	CreateCollider();
	// 피격 범위의 위치를 조절 할 수 있다.
	GetCollider()->SetOffsetPos(Vec2(0.f, 50.f));
	// 피격 범위를 조절할 수 있다.
	GetCollider()->SetScale(Vec2(180.f, 200.f));

	// Texture 로딩하기
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

	// 위로 이동
	if (KEY_HOLD(KEY::W))
	{
		vPos.y -= 200.f * fDT;
	}

	// 아래로 이동
	if (KEY_HOLD(KEY::S))
	{
		vPos.y += 200.f * fDT;
	}

	// 왼쪽으로 이동
	if (KEY_HOLD(KEY::A))
	{
		vPos.x -= 200.f * fDT;
	}

	// 오른쪽으로 이동
	if (KEY_HOLD(KEY::D))
	{
		vPos.x += 200.f * fDT;
	}

	// 18강에 미사일 쏘는거 나온다. 필요없어서 안했다.
	// 19강에 세타를 사용해서 cos, sin을 사용했다.
	// 20강에 벡터를 사용해서 벡터의 정규화 윈도우 pos는 좌표 assert 구현


	SetPos(vPos);
}

void CPlayer::render(HDC _dc)
{
	// unsiged int 안하는 이유 이미지는 음수도 있기 때문에 상관이 없다. UINT 는 음수로 가게 되는 순간 UINT의 최대값이 출력된다.
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

	// 컴포넌트 (충돌체, etc
	ComPonentRender(_dc);
}

