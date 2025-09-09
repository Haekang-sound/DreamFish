#pragma once

#include "pch.h"

enum class KEY_STATE
{
	NONE, // ������ �ʾҰ� ������ �ʴ� ����
	TAP,  // �� ���� ����
	HOLD, // ������ �ִ�
	AWAY, // �� �� ����
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
	KEY_STATE eState; // Ű�� ���°�
	bool	  bPrevPush;  // ���� �����ӿ��� ���ȴ��� ����
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