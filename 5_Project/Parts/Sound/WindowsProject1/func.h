#pragma once

class CObject;

// 오브젝트 생성
void CreateObject(CObject* _pObj, GROUP_TYPE _eGroup);
void DeleteObject(CObject* _pObj);
void ChangeScene2(SCENE_TYPE _eNext);