#include "pch.h"
#include "CFish.h"
#include "CKeyManager.h"
#include "CTimeManager.h"
#include "CGameProcess.h"

#include "CCollider.h"
// �ִϸ��̼��� �������
#include "CAnimator.h"

CFish::CFish()
	:direction(0, 0)
	,velocity(0,0)
{
	CreateFishCollider();
	//m_pTex = CResMgr::GetInstance()->LoadTexture(L"FishTex", L"texture\\fish.bmp");
	// �ǰ� ������ ��ġ�� ���� �� �� �ִ�.
	GetCollider()->SetOffsetPos(Vecor2(0.f, 0.f));
	// �ǰ� ������ ������ �� �ִ�.
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

	// �ִϸ��̼����ڸ� ä��� ���� �����
	Vecor2 vScale = { 0.5f, 0.5f };
	CAnimator* pAni = new CAnimator;
	int spriteState = 0;
	// �ִϸ��̼� ����
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
		// �浹 �� ���콺�� �ݴ� �������� ƨ���� ������

		pos = pos + normalVector * -1 * fDT;
		velocity = normalVector * -0.5f; // ƨ�ܳ����� ���� ���� ����
	}
	if ((pos - mousept).Length() < 50)	//(���� �Ÿ��� ������ ���Ͱ��� 0���� ����� ���߰��ؿ�. ���콺 ��ǥ�� ���� �ʾƿ�_
	{
		velocity = velocity * 0;
		accelerate = accelerate * 0;
	}

	if (dt > 0.1)
	{
		//mousept = CKeyMgr::GetInstance()->GetMousePoint();		///�ӵ��� �پ����(���ݾ�)
		dt = 0;
		velocity = velocity / 2; 
		//����׿� �ӽ� �ڵ�
		
	}


	wchar_t szBuffer[255] = {};
	swprintf_s(szBuffer, L"vpos : %f , velocity : %f, fdt: %f, accel: %f, temp: %f", pos.x, velocity.x, fDT, accelerate.x, temp);
	SetWindowText(CGameProcess::GetInstance()->GetMainHwnd(), szBuffer);
	SetPos(pos);
}
