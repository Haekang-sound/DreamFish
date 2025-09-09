#pragma once

#include "pch.h"

enum class KEY_STATE
{
	NONE, // 누르지 않았고 눌리지 않는 상태
	TAP,  // 막 누른 시점
	HOLD, // 누르고 있는
	AWAY, // 막 뗀 시점
};

enum class KEY
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	Q,
	W,
	E,
	R,
	T,
	Y,
	U,
	I,
	O,
	P,
	A,
	S,
	D,
	F,
	G,
	H,
	J,
	K,
	L,
	ALT,
	CTRL,
	LSHIFT,
	SPACE,
	ENTER,
	ESC,

	LAST,
};

struct tKeyInfo
{
	KEY_STATE eState; // 키의 상태값
	bool	  bPrevPush;  // 이전 프레임에서 눌렸는지 여부
};

class CKeyMgr
{
	SINGLE(CKeyMgr);

private:
	vector<tKeyInfo> m_vecKey;

public:
	void init();
	void update();

public:
	KEY_STATE GetKeyState(KEY _eKey)
	{
		return m_vecKey[(int)_eKey].eState;
	}
};