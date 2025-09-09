#include "pch.h"
#include "func.h"

#include "CEventManager.h"

void CreateObject(CObject* _pObj, GROUP_TYPE _eGroup)
{
	Event evn = {};
	evn.even = EVENT_TYPE::CREATE_OBJECT;
	evn.lParam = (DWORD_PTR)_pObj;
	evn.wParam = (DWORD_PTR)_eGroup;

	CEventManager::GetInstance()->AddEvent(evn);
}

void DeleteObject(CObject* _pObj)
{
	Event evn = {};
	evn.even = EVENT_TYPE::DELETE_OBJECT;
	evn.lParam = (DWORD_PTR)_pObj;

	CEventManager::GetInstance()->AddEvent(evn);
}

void ChangeScene2(SCENE_TYPE _eNext)
{
	Event evn = {};
	evn.even = EVENT_TYPE::SCENE_CHANGE;
	evn.lParam = (DWORD_PTR)_eNext;

	CEventManager::GetInstance()->AddEvent(evn);
}
