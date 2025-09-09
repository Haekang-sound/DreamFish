#pragma once
#include "CObject.h"

class CTexture;

class CBackGround :
    public CObject
{

private:
	CTexture* m_pTex;

public:
	virtual void Update();
	virtual void Render(HDC _dc);
	//CCollider* GetCollider() { return m_pCollider; }

public:
    CBackGround();
    ~CBackGround();

};

