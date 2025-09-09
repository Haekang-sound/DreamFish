#pragma once
#include "cObject.h"
class CTexture;
class CGameProcess;


class CEnd :
	public CObject
{

private:
	CTexture* m_pTex;
	CGameProcess* pGame;

public:
	virtual void Update();
	virtual void Render(HDC _dc);

public:
	CEnd();
	~CEnd();
};