#include "stdafx.h"
#include "Scene.h"
#include "Actor.h"

// コンストラクタ
Scene::Scene()
	: pNextScene(nullptr)
{
}

// デストラクタ
Scene::~Scene()
{
	releaseNextScene();
}

// 更新
void Scene::Update()
{
	auto it = actorList.begin();
	while (it != actorList.end())
	{
		auto* pActor = *it;
		if (pActor->IsDestroyed())
		{
			delete pActor;
			it = actorList.erase(it);
		}
		else
		{
			pActor->Update();
			++it;
		}
	}
}

// 描画
void Scene::Render(LPDIRECT3DDEVICE9 pDevice)
{
	for (auto it = actorList.begin(); it != actorList.end(); ++it)
	{
		(*it)->Render();
	}
}


// 次のシーンをセット
void Scene::SetNextScene(Scene* pScene)
{
	releaseNextScene();		// もし既にセットされていた場合は解放
	pNextScene = pScene;
}

// 次のシーンを解放
void Scene::releaseNextScene()
{
	if (pNextScene != nullptr)
	{
		delete pNextScene;
		pNextScene = nullptr;
	}
}
