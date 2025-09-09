#pragma once
#include "cObject.h"
#include "CPlayer.h"
class CTexture;


class CPlayer_Left :
	public CPlayer
{

private:


public:
	void update();
	virtual void render(HDC _dc);

public:
	CPlayer_Left();
	~CPlayer_Left();
};

