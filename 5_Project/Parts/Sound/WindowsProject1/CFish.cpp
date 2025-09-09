#include "pch.h"
#include "CFish.h"
#include "CKeyManager.h"
#include "CTimeManager.h"
#include "CGameProcess.h"

#include "CCollider.h"
// 애니메이션을 위한헤더
#include "CAnimator.h"

CFish::CFish()
	:direction(0, 0)
	,velocity(0,0)
{
	CreateFishCollider();
	//m_pTex = CResMgr::GetInstance()->LoadTexture(L"FishTex", L"texture\\fish.bmp");
	// 피격 범위의 위치를 조절 할 수 있다.
	GetCollider()->SetOffsetPos(Vecor2(0.f, 0.f));
	// 피격 범위를 조절할 수 있다.
	GetCollider()->SetScale(Vecor2(100.f, 100.f));
}

CFish::~CFish()
{

}
void CFish::Update()
{
	
	
	Move();
	
}

void CFish::Render(HDC _dc)
{

	Vecor2 vPos = GetPos();

	// 애니메이션인자를 채우기 위한 내용들
	Vecor2 vScale = { 0.5f, 0.5f };
	CAnimator* pAni = new CAnimator;
	int spriteState = 0;
	// 애니메이션 적용
	pAni->MakeAnimation(_dc, vPos, vScale, spriteState,  GROUP_TYPE::FISH);

	ComPonentRender(_dc);
	delete pAni;

}

void CFish::Move()
{
	int plzFish = m_pCollider->GetiCol();
	static double dt = 0;
	
	
	dt += DT;
	int a = 0;
	HWND hwnd = GetFocus();
	POINT m_pt={};
	GetCursorPos(&m_pt);
	ScreenToClient(hwnd, &m_pt);
	Vecor2 mousept = m_pt;

	Vecor2 pos = GetPos();
	Vecor2 normalVector = mousept - pos;
	direction = velocity;
	accelerate = (mousept - pos) / 100;
	velocity = velocity + accelerate;

	float temp = velocity.x * fDT;
	if (plzFish == 0)
	{
	pos = pos + velocity * fDT;
	}
	else
	{
		// 충돌 시 마우스의 반대 방향으로 튕겨져 나가기

		pos = pos + normalVector * -1 * fDT;
		velocity = normalVector * -0.5f; // 튕겨나가는 정도 조절 가능
	}
	if ((pos - mousept).Length() < 50)	//(일정 거리내 들어오면 벡터값을 0으로 만들어 멈추게해요. 마우스 좌표도 받지 않아요_
	{
		velocity = velocity * 0;
		accelerate = accelerate * 0;
	}

	if (dt > 0.1)
	{
		//mousept = CKeyMgr::GetInstance()->GetMousePoint();		///속도가 줄어들어요(절반씩)
		dt = 0;
		velocity = velocity / 2; 
		//디버그용 임시 코드
		
	}


	wchar_t szBuffer[255] = {};
	swprintf_s(szBuffer, L"vpos : %f , velocity : %f, fdt: %f, accel: %f, temp: %f", pos.x, velocity.x, fDT, accelerate.x, temp);
	SetWindowText(CGameProcess::GetInstance()->GetMainHwnd(), szBuffer);
	SetPos(pos);
}
