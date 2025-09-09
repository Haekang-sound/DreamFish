#pragma once
class CPathManager
{
	SINGLE(CPathManager);

private:
	wchar_t m_szContentPath[255];

public:
	void Initialize();
	const wchar_t* GetContentPath() { return m_szContentPath; }

};

