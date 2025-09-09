#pragma once
#include "CScene.h"

class CTexture;
class CGameProcess;

class Stage7 :
    public CScene
{
private:
	CTexture* m_pTex;
	CGameProcess* pGame;


public:
	virtual void Update();
	virtual void Enter();
	virtual void Exit();
	//virtual void Render(HDC _dc);


public:
	Stage7();
	~Stage7();
};

