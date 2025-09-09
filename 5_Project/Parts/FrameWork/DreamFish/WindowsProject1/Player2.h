#pragma once
#include "cObject.h"

class CTexture;


class Player2 :
	public cObject
{

private:
	CTexture* m_pTex2;

public:
	virtual void update();
	virtual void render(HDC _dc);

public:
	Player2();
	~Player2();
};

