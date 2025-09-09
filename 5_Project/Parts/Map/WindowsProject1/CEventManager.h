#pragma once

struct Event
{
	EVENT_TYPE even;
	DWORD_PTR lParam; // ÇÃ·§Æû¿¡ µû¶ó 4byte 8byte°¡ µÈ´Ù.
	DWORD_PTR wParam;
};

class CEventManager
{
	SINGLE(CEventManager)
private:
	vector<Event> m_vecEvent;

	vector<CObject*> m_vecDead;

public:
	void Update();

private:
	void Excute(const Event& _eve);

public:
	void AddEvent(const Event& _eve){ m_vecEvent.push_back(_eve); }
};

