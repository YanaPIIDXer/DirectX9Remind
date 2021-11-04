#include "stdafx.h"
#include "Scene.h"

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
