#pragma once
#include "CObject.h"

class CTexture;

class DoorKey :
    public CObject
{
private:
	virtual void OnCollisionEnter(CCollider* _pOther);
	virtual void OnCollision(CCollider* _pOther);
	virtual void OnCollisionExit(CCollider* _pOther);
	/// <summary>
	/// 성동재_접근자 함수에 대하여
	/// 초기값 설정 cpp파일 맨위에 초기값을 설정해준다
	static bool isOpen;									///물고기가 버튼을 누르면 문이 열리게끔 하기위한
public:
	virtual void Update();
	virtual void Render(HDC _dc);

	static bool& GetisOpen() { return isOpen; }		///***물고기가 버튼을 누르면 문이 열리게끔 하기위한 참조자를 반환하는 접근자 함수 추가 
public:
	DoorKey();
	~DoorKey();
};