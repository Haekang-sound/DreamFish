#pragma once

#define SINGLE(type) public: static type* GetInstance() { static type mgr; return &mgr; } private: type(); ~type();

#define fDT CTimeManager::GetInstance()->GetfDT()
#define DT CTimeManager::GetInstance()->GetDT()

// 어떤 키가 눌렸는지 확인 하는 매크로 함수!
#define KEY_CHECK(key,state) CKeyManager::GetInstance()->GetKeyState(key) == state 

//문제생기면 이걸 지워
#define CLONE(type) type* Clone() {return new type(*this);}

// 위에 꺼랑 연계해서 어떤 키가 눌렸을 때 KEY_STATE에 따라 적용되는 매크로 함수
#define KEY_NONE(key) KEY_CHECK(key, KEY_STATE::NONE) 
#define KEY_TAP(key) KEY_CHECK(key, KEY_STATE::TAP)
#define KEY_HOLD(key) KEY_CHECK(key, KEY_STATE::HOLD)
#define KEY_AWAY(key) KEY_CHECK(key, KEY_STATE::AWAY)

#define PI 3.1415926535f

// 충돌을 그룹간의 충돌로 할 예정이다.
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

	SHARK,			// 11 상어입니다.2
	SEAUR,			// 12 성게입니다.3
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