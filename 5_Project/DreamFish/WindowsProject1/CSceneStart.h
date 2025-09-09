#pragma once
#include "CScene.h"

class CTexture;
class CGameProcess;

class CSceneStart :
    public CScene
{

private:
	CTexture* m_pTex;
	CGameProcess* pGame;

public:
   virtual void Enter();
   virtual void Render(HDC _dc);
   virtual void Exit();


public:
    CSceneStart();
    ~CSceneStart();
    void Update();
};

