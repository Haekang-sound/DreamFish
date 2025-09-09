#pragma once


class CTimeManager
{
	SINGLE(CTimeManager);

private:
	LARGE_INTEGER m_llCurCount;
	LARGE_INTEGER m_llPrevCount;
	LARGE_INTEGER m_llFrequency;


	double m_dDT;
	double m_dAcc;
	UINT m_iCallCount;
	UINT m_iFPS;
	//FPS
	// 1프레임당 시간 (Delta Time)
	
public:
	void Initialize();
	void Update();
	void Render();

public:
	double GetDT() { return m_dDT; }
	float GetfDT() { return (float)m_dDT; }
};

