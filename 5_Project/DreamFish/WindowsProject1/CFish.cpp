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
	, velocity(0, 0), plzFish(0)
{
	CreateFishCollider();
	//m_pTex = CResMgr::GetInstance()->LoadTexture(L"FishTex", L"texture\\fish.bmp");
	// 피격 범위의 위치를 조절 할 수 있다.
	GetCollider()->SetOffsetPos(Vecor2(0.f, 0.f));
	// 피격 범위를 조절할 수 있다.
	GetCollider()->SetScale(Vecor2(50.f, 50.f));
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
	pAni->m_frameCount = 5;
	pAni->frameCount = 0;

	// 애니메이션 적용
	pAni->MakeAnimation(_dc, vPos, vScale, spriteState, GROUP_TYPE::FISH);

	ComPonentRender(_dc);
	delete pAni;

}

void CFish::Move()
{
	//int plzFish = 0= m_pCollider->GetiCol();
	static double dt = 0;


	dt += DT;

	Vecor2 mousept = CKeyManager::GetInstance()->GetMousePos();

	Vecor2 pos = GetPos();
	Vecor2 normalVector = mousept - pos;
	direction = velocity;
	accelerate = (mousept - pos) / 25;
	velocity = velocity + accelerate;

	float temp = velocity.x * fDT;
	
	if (plzFish == 1)
	{
		pos.x -= 5;
		pos.y -= 5;
	}
	if (plzFish == 2)
	{
		pos.x -= 5;
		pos.y += 5;
	}
	if (plzFish == 3)
	{
		pos.x += 5;
		pos.y -= 5;
	}
	if (plzFish == 4)
	{
		pos.x += 5;
		pos.y += 5;
	}

	if ((pos - mousept).Length() < 25)	//(일정 거리내 들어오면 벡터값을 0으로 만들어 멈추게해요. 마우스 좌표도 받지 않아요_
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
	pos = pos + velocity * fDT;

	/**/
	SetPos(pos);
}

void CFish::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	Vecor2 Pos = GetPos();
	Vecor2 otherPos = CCamera::GetInstance()->GetRenderPos(pOtherObj->GetPos());
	if (pOtherObj->GetName() == L"Wall" || L"Door")
	{
		if ((Pos.x <= otherPos.x) && (Pos.y <= otherPos.y))
		{
			plzFish = 1;
		}
		if ((Pos.x <= otherPos.x) && (Pos.y > otherPos.y))
		{
			plzFish = 2;
		}
		if ((Pos.x > otherPos.x) && (Pos.y <= otherPos.y))
		{
			plzFish = 3;
		}
		if ((Pos.x > otherPos.x) && (Pos.y > otherPos.y))
		{
			plzFish = 4;
		}
	}
	if (pOtherObj->GetName() == L"FakeUP")
	{
		Pos.y += 5;
	}
	if (pOtherObj->GetName() == L"FakeDown")
	{
		Pos.y -= 5;
	}
	if (pOtherObj->GetName() == L"FakeLeft")
	{
		Pos.x += 5;
	}
	if (pOtherObj->GetName() == L"FakeRight")
	{
		Pos.x -= 5;
	}
	SetPos(Pos);
}

void CFish::OnCollision(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	Vecor2 Pos = GetPos();
	Vecor2 otherPos = CCamera::GetInstance()->GetRenderPos(pOtherObj->GetPos());
	if (pOtherObj->GetName() == L"Wall"||L"Door")
	{
		if ((Pos.x <= otherPos.x) && (Pos.y <= otherPos.y))
		{
			plzFish = 1;
		}
		if ((Pos.x <= otherPos.x) && (Pos.y > otherPos.y))
		{
			plzFish = 2;
		}
		if ((Pos.x > otherPos.x) && (Pos.y <= otherPos.y))
		{
			plzFish = 3;
		}
		if ((Pos.x > otherPos.x) && (Pos.y > otherPos.y))
		{
			plzFish = 4;
		}
	}
	if (pOtherObj->GetName() == L"FakeUP")
	{
		Pos.y += 5;
	}
	if (pOtherObj->GetName() == L"FakeDown")
	{
		Pos.y -= 5;
	}
	if (pOtherObj->GetName() == L"FakeLeft")
	{
		Pos.x += 5;
	}
	if (pOtherObj->GetName() == L"FakeRight")
	{
		Pos.x -= 5;
	}
	SetPos(Pos);
}

void CFish::OnCollisionExit(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	plzFish = 0;
}
