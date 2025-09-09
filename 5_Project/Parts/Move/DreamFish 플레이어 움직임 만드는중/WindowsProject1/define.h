#pragma once

#define SINGLE(type) public: static type* GetInst() { static type mgr; return &mgr; } private: type(); ~type();

#define fDT cTimeMgr::GetInst()->GetfDT()
#define DT cTimeMgr::GetInst()->GetDT()

// � Ű�� ���ȴ��� Ȯ�� �ϴ� ��ũ�� �Լ�!
#define KEY_CHECK(key,state) CKeyMgr::GetInst()->GetKeyState(key) == state 

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
	DEFALUT, //0
	PLAYER,  //1
	MISSILE, //2
	FOOTHOLD,//3
	MONSTER,//4
	FLOOR,//5
	ROCK, //6
	LADDER,
	WALL,//7


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

enum class EVENT_TYPE
{
	CREATE_OBJECT,
	DELETE_OBJECT,
	SCENE_CHANGE,
	
	
	END,
};

