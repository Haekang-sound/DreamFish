#pragma once
class cObject;

class CCamera
{
	SINGLE(CCamera);
private:
	Vec2 m_vLookAt; //ī�޶� ���� ��ġ
	cObject* m_pTargetObj;
	cObject* m_pTargetObj2;

	Vec2 m_vDiff;

public:
	void SetLookAt(Vec2 _vLook) { m_vLookAt = _vLook; }
	void SetTarget(cObject* _pTarget, cObject* _pTarget2) {
		m_pTargetObj = _pTarget;
		m_pTargetObj2 = _pTarget2;
	}
	Vec2 GetRenderPos(Vec2 _ObjPos){ return _ObjPos - m_vDiff; }
	Vec2 GetRealPos(Vec2 _objPos) { return _objPos + m_vDiff; }

public:
	void update();

private:
	void CalDiff();
};

