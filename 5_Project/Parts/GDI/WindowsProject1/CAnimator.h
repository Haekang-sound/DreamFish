#pragma once

class cobject;
class CAnimation;
class CTexture;

class CAnimator
{
private:
	map<wstring, CAnimation*>	m_mapAnim;	// ��� �ִϸ��̼�
	CAnimation* m_pCurAnim;					// ���� ������� �ִϸ��̼�
	cObject* m_pOwner;						// �ִϸ����� ���� ������Ʈ

public:
	void CreateAnimation(const wstring& _strName, CTexture* _pTex, Vec2 _vLT, Vec2 _vSliceSize, Vec2 _vStep, UINT _iFrameCout);
	CAnimation* FindAnimation(const wstring& _strName);
	void Play();
	
	void update();
	void render(HDC _dc);

public:
	CAnimator();
	~CAnimator();

	friend class cObject;

};

