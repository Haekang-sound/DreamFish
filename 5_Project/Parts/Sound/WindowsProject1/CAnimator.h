#pragma once

class CTexture;
class CTimeManager;

class CAnimator
{
public:
	CAnimator();
	~CAnimator();
public:
	void MakeAnimation(HDC _dc, Vecor2 vPos, Vecor2 vScale, int spriteState, GROUP_TYPE spriteGroup);
	
	// 특정 오브젝트의 키상태와, 충돌상태를 알아야 함
	int CheckObjectStatus(STATE_TYPE aniamtionState);

	// 애니메이션 사용을 위한 구조체
	struct SpriteInfo
	{
		int spriteSize;
		int spriteWidthRatio;
		int spriteHeightRatio;
		int spriteHeight;
		wstring strKey;
		wstring strRelativePath;
	};

	// 애니메이션 사용을 위한 구조체 배열
	SpriteInfo spriteInfoArray[static_cast<int>(GROUP_TYPE::END)] = {
		{5000,1,1,2970,L"BackgroundTex", L"texture\\BackGround01.bmp"},
		{60, 4, 4, 100, L"PlayerTex", L"texture\\image.bmp"},
		{30, 6, 3, 100, L"FishTex", L"texture\\FishAnimation.bmp"}
	};


private:
	CTexture* m_pTex;

	

};

