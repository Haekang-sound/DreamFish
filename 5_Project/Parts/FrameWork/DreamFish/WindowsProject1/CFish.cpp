#include "pch.h"
#include "CFish.h"
#include <queue>
#include "CKeyMgr.h"
#include "cTimeMgr.h"
#include "CCore.h"

#include "CCollider.h"
CFish::CFish()
	:direction(0, 0)
	,velocity(0,0)
{
	CreateCollider();

	// 피격 범위의 위치를 조절 할 수 있다.
	GetCollider()->SetOffsetPos(Vec2(0.f, 0.f));
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
	POINT m_pt={};
	GetCursorPos(&m_pt);
	ScreenToClient(hwnd, &m_pt);
	Vec2 mousept = m_pt;

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
		//mousept = CKeyMgr::GetInst()->GetMousePoint();
		dt = 0;
		velocity = velocity / 2; 
		

		//디버그용 임시 코드
		
	}
	
	wchar_t szBuffer[255] = {};
	swprintf_s(szBuffer, L"vpos : %f , velocity : %f, fdt: %f, accel: %f, temp: %f", pos.x, velocity.x, fDT, accelerate.x, temp);
	SetWindowText(CCore::GetInst()->GetMainHwnd(), szBuffer);
	SetPos(pos);
}
