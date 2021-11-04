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
	for (auto it = actorList.begin(); it != actorList.end(); ++it)
	{
		delete (*it);
	}
	releaseNextScene();
}

// 更新
void Scene::Update(LPDIRECT3DDEVICE9 pDevice)
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
			pActor->Update(pDevice);
			++it;
		}
	}

	Tick();
}

// 描画
void Scene::Render(LPDIRECT3DDEVICE9 pDevice)
{
	for (auto it = actorList.begin(); it != actorList.end(); ++it)
	{
		(*it)->Render(pDevice);
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
