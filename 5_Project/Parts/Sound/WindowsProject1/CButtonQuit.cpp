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
	// ��ư ������ ��
	GetCollider()->SetScale(Vecor2(200.f, 100.f)); 

	// ���� �ʿ��Ѱ�? 
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