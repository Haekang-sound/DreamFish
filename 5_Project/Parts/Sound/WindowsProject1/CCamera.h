#pragma once
class CObject;

class CCamera
{
	SINGLE(CCamera);
private:
	Vecor2 m_vLookAt; //카메라가 보는 위치
	CObject* m_pTargetObj;
	CObject* m_pTargetObj2;

	Vecor2 m_vDiff;

public:
	void SetLookAt(Vecor2 _vLook) { m_vLookAt = _vLook; }
	void SetTarget(CObject* _pTarget, CObject* _pTarget2) {
		m_pTargetObj = _pTarget;
		m_pTargetObj2 = _pTarget2;
	}
	Vecor2 GetRenderPos(Vecor2 _ObjPos){ return _ObjPos - m_vDiff; }
	Vecor2 GetRealPos(Vecor2 _objPos) { return _objPos + m_vDiff; }

public:
	void Update();

private:
	void CalDiff();
};

