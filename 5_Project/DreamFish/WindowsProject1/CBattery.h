#pragma once
#include "cObject.h"

class CTexture;

class CBattery :
    public CObject
{
private:
	virtual void OnCollisionEnter(CCollider* _pOther);
	virtual void OnCollision(CCollider* _pOther);
	virtual void OnCollisionExit(CCollider* _pOther);
	/// <summary>
	/// 성동재_접근자 함수에 대하여
	/// 초기값 설정 cpp파일 맨위에 초기값을 설정해준다
	static bool isHave;									/// 획득 하면 배터리가 활성화 될수 있도록 하기.
public:
	virtual void Update();
	virtual void Render(HDC _dc);
	static bool& GetisHave() { return isHave; }		///*** 플레이어가 건전지를 가지고 있으면 머신이 발동하기 위한 참조자를 반환하는 접근자 함수 추가 >>>shark.h로 가세요
public:
	
	CBattery();
	~CBattery();
};

