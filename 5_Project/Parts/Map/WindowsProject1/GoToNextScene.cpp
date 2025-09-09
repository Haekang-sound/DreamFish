#include "pch.h"
#include "GoToNextScene.h"
#include "CCollider.h"
#include "CSceneManager.h"
#include "CScene.h"

GoToNextScene::GoToNextScene()
{
	CreateCollider();
	// 발판 충돌 사이즈 값
	GetCollider()->SetScale(Vecor2(0.f, 0.f));
}

GoToNextScene::~GoToNextScene()
{
}

void GoToNextScene::Update()
{
}
void GoToNextScene::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"PLAYER")
	{
		CScene* pCurScene = CSceneManager::GetInstance()->GetCurScene();
		if (pCurScene && pCurScene->GetName() == L"Stage1")		/// 현재씬을 받아와서 다음 씬으로 넘기기위한 조건입니다.
		{
			CSceneManager::GetInstance()->ChangeScene(SCENE_TYPE::STAGE_02); ///자~~ 다음 씬 드가자~~~~~~~~~~
		}
		if (pCurScene && pCurScene->GetName() == L"Stage2")		///현재씬을 받아와서 다음 씬으로 넘기기위한 조건입니다.
		{
			CSceneManager::GetInstance()->ChangeScene(SCENE_TYPE::STAGE_03); ///자~~ 다음 씬 드가자~~~~~~~~~~
		}
		if (pCurScene && pCurScene->GetName() == L"Stage3")		///현재씬을 받아와서 다음 씬으로 넘기기위한 조건입니다.
		{
			CSceneManager::GetInstance()->ChangeScene(SCENE_TYPE::STAGE_04); ///자~~ 다음 씬 드가자~~~~~~~~~~
		}
	}
}

void GoToNextScene::OnCollision(CCollider* _pOther)
{

}

void GoToNextScene::OnCollisionExit(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
}