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
	// 22�� Time render�� ���� ���.
	// ���� ��ΰ� ä������.
	GetCurrentDirectory(255, m_szContentPath);

	int iLen = (int)wcslen(m_szContentPath);

	// ���������� �� ���� + bin\\content\\->\0 asfd
	for (int i = iLen - 1; 0 <= i; --i)
	{
		if (m_szContentPath[i] == '\\')
		{
			m_szContentPath[i] = '\0';
			break;
		}
	}

	// ��θ� \0�� ���� ���� �Ŀ� ���ҽ� ������ �ִ� �������� ����.
	wcscat_s(m_szContentPath, 255, L"\\bin\\content\\");

}

