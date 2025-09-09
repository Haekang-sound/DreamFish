#pragma once
class cObject;

class CCamera
{
	SINGLE(CCamera);
private:
	Vec2 m_vLookAt; //ī�޶� ���� ��ġ
	cObject* m_pTargetObj;

	Vec2 m_vDiff;

public:
	void SetLookAt(Vec2 _vLook) { m_vLookAt = _vLook; }
	void SetTarget(cObject* _pTarget) { m_pTargetObj = _pTarget; }
	Vec2 GetRenderPos(Vec2 _ObjPos){ return _ObjPos - m_vDiff; }

public:
	void update();

private:
	void CalDiff();
};

