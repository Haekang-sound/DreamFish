#include "pch.h"
#include "CButtonTitle.h"

#include "CGameProcess.h"
#include "COtherCollider.h"
#include "CSceneManager.h"
#include "CKeyManager.h"

void CButtonTitle::Update()
{
	CreateCollider();
	// 버튼 사이즈 값
	GetCollider()->SetScale(Vecor2(200.f, 100.f));
}

CButtonTitle::CButtonTitle()
{

}

CButtonTitle::~CButtonTitle()
{
	POINT ptPos = {};
	GetCursorPos(&ptPos);
	ScreenToClient(CGameProcess::GetInstance()->GetMainHwnd(), &ptPos);
	bool checkRect = false;

	if (500 < ptPos.x && ptPos.x < 600) // 정해주면 된다.
	{
		if (100 < ptPos.y && ptPos.y < 300)
		{
			checkRect = true;
		}
	}

	if ((KEY_TAP(KEY::LBTN)) && checkRect)
	{
		CSceneManager::GetInstance()->ChangeScene(SCENE_TYPE::TITLE); // 타이틀로 돌아간다.
	}
}
