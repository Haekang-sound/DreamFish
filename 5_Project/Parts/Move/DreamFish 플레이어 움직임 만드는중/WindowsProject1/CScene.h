#pragma once

// 전방 선언
class cObject;

class CScene
{
private:
	vector<cObject*> m_arrObj[(UINT)GROUP_TYPE::END]; // 오브젝트를 저장 및 관리할 벡터를 그룹 개수만큼 선언
	wstring m_strName; // scene 이름

public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }
	
	virtual void update();
	virtual void finalupdate();
	virtual void render(HDC _dc);

	virtual void Enter() = 0; // 해당 Scene 에 진입 시 호출
	virtual void Exit() = 0; // 해당 Scene 을 탈출 시 호출

public:
	void AddObject(cObject* _pObj, GROUP_TYPE _eType)
	{
		m_arrObj[(UINT)_eType].push_back(_pObj);
	}

	const vector<cObject*>& GetGroupObject(GROUP_TYPE _eType){ return m_arrObj[(UINT)_eType]; }
	void DeleteGroup(GROUP_TYPE _eTarget);
	void DeleteAll();

public:
	CScene();
	virtual ~CScene();
};

