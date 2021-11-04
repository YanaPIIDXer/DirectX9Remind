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
	for (auto it = actorList.begin(); it != actorList.end(); ++it)
	{
		(*it)->Update();
	}
}

// 描画
void Scene::Render(LPDIRECT3DDEVICE9 pDevice)
{
}


// 次のシーンをセット
void Scene::setNextScene(Scene* pScene)
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
