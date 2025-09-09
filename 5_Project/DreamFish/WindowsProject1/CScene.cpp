#include "pch.h"
#include "CScene.h"

#include "CObject.h"

CScene::CScene()
{

}

CScene::~CScene()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_arrObj[i].size(); ++j) 
		{
			// m_arrOb j 그룹 벡터의 j 삭제
			delete m_arrObj[i][j];
		}
	}
}

void CScene::Update()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_arrObj[i].size(); ++j)
		{
			m_arrObj[i][j]->Update();
		}
	}
}

void CScene::FinalUpdate()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_arrObj[i].size(); ++j)
		{
			m_arrObj[i][j]->FinalUpdate();
		}
	}
}

void CScene::Render(HDC _dc)
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_arrObj[i].size(); ++j)
		{
			m_arrObj[i][j]->Render(_dc);
		}
	}
}

void CScene::DeleteGroup(GROUP_TYPE _eTarget)
{
	for (size_t i = 0; i < m_arrObj[(UINT)_eTarget].size(); ++i)
	{
		delete m_arrObj[(UINT)_eTarget][i];
	}

	m_arrObj[(UINT)_eTarget].clear();
}

void CScene::DeleteAll()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		DeleteGroup((GROUP_TYPE)i);
	}
}