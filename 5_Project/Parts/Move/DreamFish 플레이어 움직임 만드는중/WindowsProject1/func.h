#pragma once

class cObject;

// 오브젝트 생성
void CreateObject(cObject* _pObj, GROUP_TYPE _eGroup);
void DeleteObject(cObject* _pObj);
void ChangeScene(SCENE_TYPE _eNext);

// 템플릿이 있다. Safe_Delete_Vec 뭔가 안되서 포기함 그냥 삭제하자