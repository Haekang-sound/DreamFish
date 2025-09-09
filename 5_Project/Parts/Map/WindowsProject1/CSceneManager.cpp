#include "pch.h"
#include "CSceneManager.h"

#include "CSceneStart.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "Stage4.h"
#include "Stage5.h"
#include "Stage6.h"
#include "CTitle.h"

CSceneManager::CSceneManager()
	: m_pCurScene(nullptr), m_arrScene{}
{

}

CSceneManager::~CSceneManager()
{
	// 씬 전부 삭제
	for (UINT i = 0;  i < (UINT)SCENE_TYPE::END; ++i)
	{
		if (nullptr != m_arrScene[i])
		{
			delete m_arrScene[i];
		}
	}
}

void CSceneManager::Initialize()
{
	// Scene 생성
	m_arrScene[(UINT)SCENE_TYPE::TITLE] = new CTitle;
	m_arrScene[(UINT)SCENE_TYPE::TITLE]->SetName(L"Title");

	m_arrScene[(UINT)SCENE_TYPE::START] = new CSceneStart;
	m_arrScene[(UINT)SCENE_TYPE::START]->SetName(L"Start Scene");

	m_arrScene[(UINT)SCENE_TYPE::STAGE_01] = new Stage1;
	m_arrScene[(UINT)SCENE_TYPE::STAGE_01]->SetName(L"Stage1");

	m_arrScene[(UINT)SCENE_TYPE::STAGE_02] = new Stage2;
	m_arrScene[(UINT)SCENE_TYPE::STAGE_02]->SetName(L"Stage2");

	m_arrScene[(UINT)SCENE_TYPE::STAGE_03] = new Stage3;
	m_arrScene[(UINT)SCENE_TYPE::STAGE_03]->SetName(L"Stage3");

	m_arrScene[(UINT)SCENE_TYPE::STAGE_04] = new Stage4;
	m_arrScene[(UINT)SCENE_TYPE::STAGE_04]->SetName(L"Stage4");

	m_arrScene[(UINT)SCENE_TYPE::STAGE_05] = new Stage5;
	m_arrScene[(UINT)SCENE_TYPE::STAGE_05]->SetName(L"Stage5");

	m_arrScene[(UINT)SCENE_TYPE::STAGE_06] = new Stage6;
	m_arrScene[(UINT)SCENE_TYPE::STAGE_06]->SetName(L"Stage6");

	
	// 현재 씬 저장
	m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::TITLE];
	m_pCurScene->Enter();
}

void CSceneManager::Update()
{
	m_pCurScene->Update();

	m_pCurScene->FinalUpdate();
}

void CSceneManager::Render(HDC _dc)
{
	m_pCurScene->Render(_dc);
}

void CSceneManager::ChangeScene(SCENE_TYPE _eNext)
{
	m_pCurScene->Exit();

	m_pCurScene = m_arrScene[(UINT)_eNext];

	m_pCurScene->Enter();
}