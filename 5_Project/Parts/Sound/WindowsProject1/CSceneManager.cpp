#include "pch.h"
#include "CSceneManager.h"

#include "CSceneStart.h"
#include "CSceneTool.h"
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

	m_arrScene[(UINT)SCENE_TYPE::TOOL] = new CSceneTool;
	m_arrScene[(UINT)SCENE_TYPE::TOOL]->SetName(L"Start TOOL");

	//m_arrScene[(UINT)SCENE_TYPE::TOOL] = new CScene_Tool;
	//m_arrScene[(UINT)SCENE_TYPE::STAGE_01] = new CScene_Stage01;
	//m_arrScene[(UINT)SCENE_TYPE::STAGE_02] = new CScene_Stage02;
	
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