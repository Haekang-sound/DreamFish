#pragma once
#include "CObject.h"

class CTexture;

class CBackGround :
    public CObject
{

private:
	CTexture* m_pTex;
	POINT size;

public:
	virtual void Update();
	virtual void Render(HDC _dc);
	void SetTexture(const wstring& _strKey, const wstring& _strRelativePath);
	void SetSize(int x, int y) { size = POINT { x, y }; }
	//CCollider* GetCollider() { return m_pCollider; }

public:
    CBackGround();
    ~CBackGround();

};

