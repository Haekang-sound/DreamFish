#include "pch.h"
#include "CButtonStart.h"

#include "cObject.h"
#include "COtherCollider.h"
#include "CGameProcess.h"
#include "CKeyManager.h"
#include "CSceneManager.h"
#include "CSoundManager.h"

CButtonStart::CButtonStart()
{
	CreateCollider();

	GetCollider()->SetScale(Vecor2(200.f, 100.f));
}

CButtonStart::~CButtonStart()
{

}

void CButtonStart::Update()
{
	POINT ptPos = {};
	GetCursorPos(&ptPos);
	ScreenToClient(CGameProcess::GetInstance()->GetMainHwnd(), &ptPos);
	bool checkRect = false;

	if (100 < ptPos.x && ptPos.x < 300)
	{
		if (100 < ptPos.y && ptPos.y < 300)
		{
			checkRect = true;
		}
	}

	if ((KEY_TAP(KEY::LBTN)) && checkRect)
	{
		CSoundManager::GetInstance()->ReleaseMusic();
		CSceneManager::GetInstance()->ChangeScene(SCENE_TYPE::TOOL);
	}
}