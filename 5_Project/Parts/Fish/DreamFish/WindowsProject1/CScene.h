#pragma once

// ���� ����
class cObject;

class CScene
{
private:
	vector<cObject*> m_arrObj[(UINT)GROUP_TYPE::END]; // ������Ʈ�� ���� �� ������ ���͸� �׷� ������ŭ ����
	wstring m_strName; // scene �̸�

public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }
	
	void update();
	void finalupdate();
	void render(HDC _dc);

	virtual void Enter() = 0; // �ش� Scene �� ���� �� ȣ��
	virtual void Exit() = 0; // �ش� Scene �� Ż�� �� ȣ��

public:
	void AddObject(cObject* _pObj, GROUP_TYPE _eType)
	{
		m_arrObj[(UINT)_eType].push_back(_pObj);
	}

	const vector<cObject*>& GetGroupObject(GROUP_TYPE _eType){ return m_arrObj[(UINT)_eType]; }


public:
	CScene();
	virtual ~CScene();
};

