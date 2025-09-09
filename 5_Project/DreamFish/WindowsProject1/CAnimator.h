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
	void MakeMap(HDC _dc, Vecor2 vPos, Vecor2 vScale, int spriteState, GROUP_TYPE spriteGroup);
	void MakeText(HDC _dc, Vecor2 vPos, Vecor2 vScale, int spriteState, GROUP_TYPE spriteGroup);
	void MakeEnd(HDC _dc, Vecor2 vPos, Vecor2 vScale, int spriteState, GROUP_TYPE spriteGroup);

	
	// 특정 오브젝트의 키상태와, 충돌상태를 알아야 함
	int CheckObjectStatus(STATE_TYPE aniamtionState);

	int m_frameCount;
	int frameCount;


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
		{3000,1,1,890,L"BackgroundTex", L"texture\\BackGround01.bmp"}, // 0
		{100,1,1,250,L"RockTex", L"texture\\Rock_Fixed.bmp"},	 // 1
		{1500 / 5,5,2,234 / 2,L"SharkTex", L"texture\\Shark_Animation.bmp" },	 // 2 monster
		{350,1,1,50, L"FloorTex", L"texture\\FLOOR2.bmp"},	 // 3
		{100,1,1,450,L"LadderTex", L"texture\\LADDER.bmp" },	 // 4
		{20, 1, 1, 200,L"DoorTex", L"texture\\door_right.bmp" },	 // 5
		{50,1,1,300, L"WallTex", L"texture\\WALL_LEFT.bmp"},	 // 6
		{50,1,1,20, L"FishButtonTex", L"texture\\Button_PushedRow.bmp"},	 // 7
		{50,1,1,20, L"ButtonTex", L"texture\\Button_PushedCol_inv.bmp"},	 // 8
		{450 / 5, 5, 6, 960 / 6, L"PlayerTex", L"texture\\Girl_Animation_fixed_03.bmp"},	// 9
		{500 / 5, 5, 12, 772 / 12, L"FishTex", L"texture\\Fish_Animation.bmp"},	// 10

		{},	// 11
		{200,1,1,200,L"SeaurTex", L"texture\\seaurchin.bmp" },	// 12 성게

		{25,1,1,25,L"DoorKeyTex", L"texture\\Button_PushedCol_inv_key.bmp" },	// 13
		{100,1,1,100,L"BatteryTex", L"texture\\Battery.bmp"},	// 14 


		{},	// 15
		{},	// 16
		{},	// 17d
		{},	// 18
		{},	// 19
		{1220, 1, 1, 460,L"TitelTex", L"texture\\DreamFish_Logo_Fixed_02.bmp" },	// 20
		{2560,1,1,1440, L"ControlTex", L"texture\\howtoPlay.bmp" },	// 21
		{},	// 22
		{1677,1,1,500, L"EndTex", L"texture\\end.bmp"},	// 23
		{},	// 24
		{},	// 25
		{},	// 26
		{},	// 27
		{},	// 28
		{},	// 29
		{},	// 30
		{}	// 31
		};


private:
	CTexture* m_pTex;

	

};

