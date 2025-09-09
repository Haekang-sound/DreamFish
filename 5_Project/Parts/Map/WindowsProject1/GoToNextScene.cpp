#include "pch.h"
#include "GoToNextScene.h"
#include "CCollider.h"
#include "CSceneManager.h"
#include "CScene.h"

GoToNextScene::GoToNextScene()
{
	CreateCollider();
	// ���� �浹 ������ ��
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
		if (pCurScene && pCurScene->GetName() == L"Stage1")		/// ������� �޾ƿͼ� ���� ������ �ѱ������ �����Դϴ�.
		{
			CSceneManager::GetInstance()->ChangeScene(SCENE_TYPE::STAGE_02); ///��~~ ���� �� �尡��~~~~~~~~~~
		}
		if (pCurScene && pCurScene->GetName() == L"Stage2")		///������� �޾ƿͼ� ���� ������ �ѱ������ �����Դϴ�.
		{
			CSceneManager::GetInstance()->ChangeScene(SCENE_TYPE::STAGE_03); ///��~~ ���� �� �尡��~~~~~~~~~~
		}
		if (pCurScene && pCurScene->GetName() == L"Stage3")		///������� �޾ƿͼ� ���� ������ �ѱ������ �����Դϴ�.
		{
			CSceneManager::GetInstance()->ChangeScene(SCENE_TYPE::STAGE_04); ///��~~ ���� �� �尡��~~~~~~~~~~
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