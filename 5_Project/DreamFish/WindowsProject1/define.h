#pragma once

#define SINGLE(type) public: static type* GetInstance() { static type mgr; return &mgr; } private: type(); ~type();

#define fDT CTimeManager::GetInstance()->GetfDT()
#define DT CTimeManager::GetInstance()->GetDT()

// � Ű�� ���ȴ��� Ȯ�� �ϴ� ��ũ�� �Լ�!
#define KEY_CHECK(key,state) CKeyManager::GetInstance()->GetKeyState(key) == state 

//��������� �̰� ����
#define CLONE(type) type* Clone() {return new type(*this);}

// ���� ���� �����ؼ� � Ű�� ������ �� KEY_STATE�� ���� ����Ǵ� ��ũ�� �Լ�
#define KEY_NONE(key) KEY_CHECK(key, KEY_STATE::NONE) 
#define KEY_TAP(key) KEY_CHECK(key, KEY_STATE::TAP)
#define KEY_HOLD(key) KEY_CHECK(key, KEY_STATE::HOLD)
#define KEY_AWAY(key) KEY_CHECK(key, KEY_STATE::AWAY)

#define PI 3.1415926535f

// �浹�� �׷찣�� �浹�� �� �����̴�.
enum class GROUP_TYPE
{
	DEFALUT,		// 0

	ROCK ,			// 1
	MONSTER,		// 2
	FLOOR,			// 3
	LADDER,			// 4
	DOOR,			// 5
	WALL,			// 6
	DOORBUTTON,		// 7
	FISHBUTTON,		// 8
	
	
	PLAYER ,		// 9
	FISH,			// 10

	SHARK,			// 11 ����Դϴ�.2
	SEAUR,			// 12 �����Դϴ�.3
	DOORKEY,		// 13
	BATTERAY,		// 14

	GAMETITLE,		// 15
	GOTONEXTSCENE,	// 16
	GAMELOGO,		// 17
	GAMESTART,		// 18
	GAMEQUIT,		// 19
	GAMETITLE_TEXT,	// 20
	GAMECONTROL,	// 21
	
	FAKE,	//22
	ENDLOGO,
	


	END = 32,
};

enum class SCENE_TYPE
{
	TOOL,
	TITLE,
	TUTORIAL,
	STAGE_01,
	STAGE_02,
	STAGE_03,
	STAGE_04,
	STAGE_05,
	STAGE_06,
	STAGE_07,

	END,
};

enum class BRUSH_TYPE
{
	HOLLOW,
	END,
};

enum class PEN_TYPE
{
	RED,
	GREEN,
	BLUE,
	END,
};

enum class EVENT_TYPE
{
	CREATE_OBJECT,
	DELETE_OBJECT,
	SCENE_CHANGE,


	END,
};

enum class STATE_TYPE
{
	Idle,
	None1,
	WalkLeft,
	WalkRight,


	END,
};

enum class SOUND_TRACK
{
	TITLE,
	BACKGROUND_SOUND,
	ENDING_SOUND,
	EFFECT_SOUND,


	END,
};