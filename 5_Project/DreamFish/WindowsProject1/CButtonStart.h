#pragma once
#include "CObject.h"

class CTexture;
class CGameProcess;

class CButtonStart :
    public CObject
{

private:
	CTexture* m_pTex;
	CGameProcess* pGame;

public:
	virtual void Update();
	virtual void Render(HDC _dc);


public:
    CButtonStart();
    ~CButtonStart();
};