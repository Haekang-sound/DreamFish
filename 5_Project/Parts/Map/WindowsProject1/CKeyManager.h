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
	LBTN,
	RBTN,

	LAST,
};

struct tKeyInfo
{
	KEY_STATE eState; // 키의 상태값
	bool	  bPrevPush;  // 이전 프레임에서 눌렸는지 여부
};

class CKeyManager
{
	SINGLE(CKeyManager);

private:
	vector<tKeyInfo> m_vecKey;
	Vecor2 m_vCurMousePos;
	POINT m_pt;

public:
	void Initialize();
	void Update();

public:
	KEY_STATE GetKeyState(KEY _eKey) { return m_vecKey[(int)_eKey].eState; }
	Vecor2 GetMousePos() { return m_vCurMousePos; }
	Vecor2 GetMousePoint()
	{
		return m_pt;
	}
};