#pragma once
#include "CObject.h"

class CTexture;
class CGameProcess;

class CButtonTitle :
    public CObject
{
private:
	CTexture* m_pTex;
	CGameProcess* pGame;

public:
	virtual void Update();
	virtual void Render(HDC _dc);


public:
	CButtonTitle();
	~CButtonTitle();
	
};