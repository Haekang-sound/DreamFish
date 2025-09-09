#pragma once
#include "CObject.h"
class CFish :
    public CObject
{
private:
    Vecor2 direction;
    Vecor2 velocity;
    

public:
    int plzFish;
    virtual void Update();
    virtual void Render(HDC _dc);
    
    void Move();
private:
	virtual void OnCollisionEnter(CCollider* _pOther);
	virtual void OnCollision(CCollider* _pOther);
	virtual void OnCollisionExit(CCollider* _pOther);

    Vecor2 GetVelocity() { return velocity; }
    void SetVelocity(Vecor2 _vel) { velocity = _vel; }

public:
    CFish();
    ~CFish();
};

