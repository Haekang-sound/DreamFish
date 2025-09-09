#pragma once

#define SINGLE(type) public: static type* GetInst() { static type mgr; return &mgr; } private: type(); ~type();

#define fDT cTimeMgr::GetInst()->GetfDT()
#define DT cTimeMgr::GetInst()->GetDT()

// 어떤 키가 눌렸는지 확인 하는 매크로 함수!
#define KEY_CHECK(key,state) CKeyMgr::GetInst()->GetKeyState(key) == state 

// 위에 꺼랑 연계해서 어떤 키가 눌렸을 때 KEY_STATE에 따라 적용되는 매크로 함수
#define KEY_NONE(key) KEY_CHECK(key, KEY_STATE::NONE) 
#define KEY_TAP(key) KEY_CHECK(key, KEY_STATE::TAP)
#define KEY_HOLD(key) KEY_CHECK(key, KEY_STATE::HOLD)
#define KEY_AWAY(key) KEY_CHECK(key, KEY_STATE::AWAY)

#define PI 3.1415926535f

// 충돌을 그룹간의 충돌로 할 예정이다.
enum class GROUP_TYPE
{
	DEFALUT, //0
	PLAYER,  //1
	FISH, //2
	FOOTHOLD,//3
	MONNSTER,//4

	END = 32,
};

enum class SCENE_TYPE
{
	TOOL,
	START,
	STAGE_01,
	STAGE_02,

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

