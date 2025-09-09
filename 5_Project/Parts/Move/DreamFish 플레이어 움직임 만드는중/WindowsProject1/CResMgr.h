#pragma once

class CTexture;

class CResMgr
{
	SINGLE(CResMgr);
private:
	map<wstring, CTexture*> m_mapTex;


public:
	// key 핵심 키값 RelPath 상대 경로
	CTexture* LoadTexture(const wstring& _strKey, const wstring& _strRelativePath);
	CTexture* FindTexture(const wstring& _strKey);

};

