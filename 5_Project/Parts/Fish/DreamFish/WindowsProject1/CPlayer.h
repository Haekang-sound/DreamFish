#pragma once
#include "cObject.h"

class CTexture;


class CPlayer :
    public cObject
{

private:
    CTexture* m_pTex;
    

public:
    virtual void update();
    virtual void render(HDC _dc);
    

public:
    CPlayer();
   ~CPlayer();
};

