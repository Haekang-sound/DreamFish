#include "pch.h"
#include "CFish.h"
#include "CKeyMgr.h"
#include "cTimeMgr.h"


#include "FishCollider.h"
CFish::CFish()
	:direction(0, 0)
	,velocity(0,0)
{
	CreateFishCollider();

	// 피격 범위의 위치를 조절 할 수 있다.
	GetCollider()->SetOffsetPos(Vec2(0.f, 0.f) );
	// 피격 범위를 조절할 수 있다.
	GetCollider()->SetScale(Vec2(100.f, 100.f));
}

CFish::~CFish()
{

}
void CFish::update()
{
	
	
	Move();
	
}

void CFish::render(HDC _dc)
{
	Vec2 vScale = GetScale();
	Vec2 vPos = GetPos();
	Rectangle(_dc, vPos.x - vScale.x / 2.f, vPos.y - vScale.y / 2.f, vPos.x + vScale.x / 2.f, vPos.y + vScale.y / 2.f);
	ComPonentRender(_dc);
}

void CFish::Move()
{
	static double dt = 0;
	dt += DT;
	int a = 0;
	HWND hwnd = GetFocus();
	
	
	Vec2 mousept = CKeyMgr::GetInst()->GetMousePoint();

	Vec2 pos = GetPos();
	Vec2 normalVector = mousept - pos;
	direction = velocity;
	accelerate = (mousept - pos) / 100;
	velocity = velocity + accelerate;

	float temp = velocity.x * fDT;
	pos = pos + velocity * fDT;
	if ((pos - mousept).Length() < 50)
	{
		velocity = velocity * 0;
		accelerate = accelerate * 0;
	}

	if (dt > 0.1)
	{
		dt = 0;
		velocity = velocity / 2; 
		

	}
	
	
	SetPos(pos);
	
}
