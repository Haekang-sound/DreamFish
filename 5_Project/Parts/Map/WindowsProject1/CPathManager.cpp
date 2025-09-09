#include "pch.h"
#include "CPathManager.h"

CPathManager::CPathManager()
	:m_szContentPath{}
{}

CPathManager::~CPathManager()
{

}

void CPathManager::Initialize()
{
	// 22강 Time render을 따로 줬다.
	// 현재 경로가 채워진다.
	GetCurrentDirectory(255, m_szContentPath);

	int iLen = (int)wcslen(m_szContentPath);

	// 상위폴더로 간 다음 + bin\\content\\->\0 asfd
	for (int i = iLen - 1; 0 <= i; --i)
	{
		if (m_szContentPath[i] == '\\')
		{
			m_szContentPath[i] = '\0';
			break;
		}
	}

	// 경로를 \0를 시켜 끊은 후에 리소스 파일이 있는 공간으로 들어간다.
	wcscat_s(m_szContentPath, 255, L"\\bin\\content\\");

}

