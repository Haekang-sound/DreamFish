#include "pch.h"
#include "CButtonQuit.h"

#include "CGameProcess.h"
#include "COtherCollider.h"
#include "CSceneManager.h"
#include "CKeyManager.h"
#include "WindowsProject1.h"
#include "CSoundManager.h"

CButtonQuit::CButtonQuit()
{
	CreateCollider();
	// 버튼 사이즈 값
	GetCollider()->SetScale(Vecor2(200.f, 100.f)); 

	// 위에 필요한가? 
}

CButtonQuit::~CButtonQuit()
{

}

void CButtonQuit::Update()
{
	POINT ptPos = {};
	GetCursorPos(&ptPos);
	ScreenToClient(CGameProcess::GetInstance()->GetMainHwnd(), &ptPos);
	bool checkRect = false;

	if (500 < ptPos.x && ptPos.x < 600)
	{
		if (100 < ptPos.y && ptPos.y < 300)
		{
			checkRect = true;
		}
	}

	if ((KEY_TAP(KEY::LBTN)) && checkRect)
	{
		PostQuitMessage(0);
		CSoundManager::GetInstance()->ReleaseMusic();
	}
}