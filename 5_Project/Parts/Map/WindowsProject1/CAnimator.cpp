#include "pch.h"
#include "CAnimator.h"

#include "CTimeManager.h"
#include "CResManager.h"
#include "CTexture.h"

#include "CKeyManager.h"



CAnimator::CAnimator()
	:m_pTex(nullptr)
{

}

CAnimator::~CAnimator()
{

}

/// <summary>
/// 애니메이션을 만들어주는 함수
/// </summary>
void CAnimator::MakeAnimation(HDC _dc, Vecor2 vPos, Vecor2 vScale, int spriteState,  GROUP_TYPE spriteGroup)
{
	// 이동판단
	// 왼쪽으로 이동


	// 경로 및 DC받아오기
	// 그룹타입에 따라 다른 파일경로를 주어야함
	m_pTex = CResManager::GetInstance()->LoadTexture(spriteInfoArray[static_cast<int>(spriteGroup)].strKey
		, spriteInfoArray[static_cast<int>(spriteGroup)].strRelativePath);

	int iWidth = (int)m_pTex->Width();		// 비트맵 가로길이
	int iHeight = (int)m_pTex->Height();	// 비트맵 세로길이

	

	// 애니메이션 프레임제어를 위한 정적변수
	static int frameCount = 0;
	static double CheckTime = 0;


	//spriteState = CheckObjectStatus();



	// 메모리DC에 이미지 작성
	TransparentBlt(_dc
		, int(vPos.x - (float)((iWidth / spriteInfoArray[static_cast<int>(spriteGroup)].spriteWidthRatio) / 2))		// x좌표
		, int(vPos.y - (float)((iHeight / spriteInfoArray[static_cast<int>(spriteGroup)].spriteHeightRatio) / 2))	// y좌표
		, iWidth / spriteInfoArray[static_cast<int>(spriteGroup)].spriteWidthRatio
		, iHeight / spriteInfoArray[static_cast<int>(spriteGroup)].spriteHeightRatio 		// 비트맵 전체 길이 (x,y)
		, m_pTex->GetDC()		// 
		, spriteInfoArray[static_cast<int>(spriteGroup)].spriteSize* frameCount			// 스프라이트 x좌표 (애니메이션 시작점)
		, spriteInfoArray[static_cast<int>(spriteGroup)].spriteHeight * spriteState																	// 스프라이트 y좌표 (애니메이션 상태좌표)
		, iWidth / spriteInfoArray[static_cast<int>(spriteGroup)].spriteWidthRatio		// 스프라이트 크기 (x길이)
		, iHeight / spriteInfoArray[static_cast<int>(spriteGroup)].spriteHeightRatio,	// 스프라이트 크기 (y길이)
		RGB(255, 0, 255));

	// 애니메이션 재생시간을 결정하는 코드
	// 애니메이션마다 주기가 다를 수 있다.. 일단 보면서;
	if (CheckTime >= 1.0)
	{
		frameCount++;
		frameCount = frameCount % 4;
		CheckTime = 0;
	}
	else
		CheckTime += DT;
}


int CAnimator::CheckObjectStatus(STATE_TYPE aniamtionState)
{
	int statement = 0;
	if (!static_cast<int>(aniamtionState))
	{
		statement = static_cast<int>(aniamtionState);
	}

	return statement;
}

