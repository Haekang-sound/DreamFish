#pragma once

class cObject;

// ������Ʈ ����
void CreateObject(cObject* _pObj, GROUP_TYPE _eGroup);
void DeleteObject(cObject* _pObj);
void ChangeScene(SCENE_TYPE _eNext);

// ���ø��� �ִ�. Safe_Delete_Vec ���� �ȵǼ� ������ �׳� ��������