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
/// �ִϸ��̼��� ������ִ� �Լ�
/// </summary>
void CAnimator::MakeAnimation(HDC _dc, Vecor2 vPos, Vecor2 vScale, int spriteState,  GROUP_TYPE spriteGroup)
{
	// �̵��Ǵ�
	// �������� �̵�


	// ��� �� DC�޾ƿ���
	// �׷�Ÿ�Կ� ���� �ٸ� ���ϰ�θ� �־����
	m_pTex = CResManager::GetInstance()->LoadTexture(spriteInfoArray[static_cast<int>(spriteGroup)].strKey
		, spriteInfoArray[static_cast<int>(spriteGroup)].strRelativePath);

	int iWidth = (int)m_pTex->Width();		// ��Ʈ�� ���α���
	int iHeight = (int)m_pTex->Height();	// ��Ʈ�� ���α���

	

	// �ִϸ��̼� ��������� ���� ��������
	static int frameCount = 0;
	static double CheckTime = 0;


	//spriteState = CheckObjectStatus();



	// �޸�DC�� �̹��� �ۼ�
	TransparentBlt(_dc
		, int(vPos.x - (float)((iWidth / spriteInfoArray[static_cast<int>(spriteGroup)].spriteWidthRatio) / 2))		// x��ǥ
		, int(vPos.y - (float)((iHeight / spriteInfoArray[static_cast<int>(spriteGroup)].spriteHeightRatio) / 2))	// y��ǥ
		, iWidth / spriteInfoArray[static_cast<int>(spriteGroup)].spriteWidthRatio
		, iHeight / spriteInfoArray[static_cast<int>(spriteGroup)].spriteHeightRatio 		// ��Ʈ�� ��ü ���� (x,y)
		, m_pTex->GetDC()		// 
		, spriteInfoArray[static_cast<int>(spriteGroup)].spriteSize* frameCount			// ��������Ʈ x��ǥ (�ִϸ��̼� ������)
		, spriteInfoArray[static_cast<int>(spriteGroup)].spriteHeight * spriteState																	// ��������Ʈ y��ǥ (�ִϸ��̼� ������ǥ)
		, iWidth / spriteInfoArray[static_cast<int>(spriteGroup)].spriteWidthRatio		// ��������Ʈ ũ�� (x����)
		, iHeight / spriteInfoArray[static_cast<int>(spriteGroup)].spriteHeightRatio,	// ��������Ʈ ũ�� (y����)
		RGB(255, 0, 255));

	// �ִϸ��̼� ����ð��� �����ϴ� �ڵ�
	// �ִϸ��̼Ǹ��� �ֱⰡ �ٸ� �� �ִ�.. �ϴ� ���鼭;
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

