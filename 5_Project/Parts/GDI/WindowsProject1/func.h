#pragma once
#include <vector>
#include <map>
using namespace std;


class cObject;

// 오브젝트 생성
void CreateObject(cObject* _pObj, GROUP_TYPE _eGroup);
void DeleteObject(cObject* _pObj);
void ChangeScene(SCENE_TYPE _eNext);

// 템플릿이 있다. Safe_Delete_Vec 뭔가 안되서 포기함 그냥 삭제하자

template<typename T>
void Safe_Delete_Vec(vector<T>& _vec)
{
	for (size_t i = 0; i < _vec.size(); ++i)
	{
		if (nullptr != _vec[i])
			delete _vec;
	}
	_vec.clear();
}

template<typename T1, typename T2>
void Safe_Delete_Map(map<T1, T2>& _map)
{
// 	typename map<T1, T2>::iterator iter == _map.begin();
// 
// 	for (; iter != _map.end(0); ++iter)
// 	{
// 		if (nullptr != iter->second)
// 			delete iter->second;
// 	}
// 	_map.clear();
}