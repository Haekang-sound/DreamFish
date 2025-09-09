#include "pch.h"
#include "CResManager.h"

#include "CPathManager.h"
#include "CTexture.h"

CResManager::CResManager()
{

}

CResManager::~CResManager()
{
	map<wstring, CTexture*>::iterator iter = m_mapTex.begin();
	for (; iter != m_mapTex.end(); ++iter)
	{
		delete iter->second;
	}
}

CTexture* CResManager::LoadTexture(const wstring& _strKey, const wstring& _strRelativePath)
{
	CTexture* pTex = FindTexture(_strKey);
	if (nullptr != pTex)
	{
		return pTex;
	}

	wstring strFilePath = CPathManager::GetInstance()->GetContentPath();
	strFilePath += _strRelativePath;

	pTex = new CTexture;
	pTex->Load(strFilePath);
	pTex->SetKey(_strKey);
	pTex->SetRelativePath(_strRelativePath);

	m_mapTex.insert(make_pair(_strKey, pTex)); 

	return pTex;
}

CTexture* CResManager::FindTexture(const wstring& _strKey)
{
	map<wstring, CTexture*>::iterator iter = m_mapTex.find(_strKey);
	if (iter == m_mapTex.end())
	{
		return nullptr;
	}

	return iter->second;
}
