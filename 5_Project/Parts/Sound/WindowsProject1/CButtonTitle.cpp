#include "pch.h"
#include "CButtonTitle.h"

#include "CGameProcess.h"
#include "COtherCollider.h"
#include "CSceneManager.h"
#include "CKeyManager.h"

void CButtonTitle::Update()
{
	CreateCollider();
	// ��ư ������ ��
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

	if (500 < ptPos.x && ptPos.x < 600) // �����ָ� �ȴ�.
	{
		if (100 < ptPos.y && ptPos.y < 300)
		{
			checkRect = true;
		}
	}

	if ((KEY_TAP(KEY::LBTN)) && checkRect)
	{
		CSceneManager::GetInstance()->ChangeScene(SCENE_TYPE::TITLE); // Ÿ��Ʋ�� ���ư���.
	}
}
