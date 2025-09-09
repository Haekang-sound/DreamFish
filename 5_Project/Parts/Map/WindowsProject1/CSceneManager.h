#pragma once

class CScene;

class CSceneManager
{
	SINGLE(CSceneManager);

private:
	CScene*      m_arrScene[(UINT)SCENE_TYPE::END]; // ��� �� ���
	CScene*      m_pCurScene; // ���� ��

public:
	void Initialize();
	void Update();
	void Render(HDC _dc);
	void ChangeScene(SCENE_TYPE _eNext);

public:
	CScene* GetCurScene() { return m_pCurScene; }

private:
	friend class CEventManager;

};
