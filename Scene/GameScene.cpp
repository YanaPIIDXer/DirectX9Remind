#include "stdafx.h"
#include "GameScene.h"
#include "Actors/TeapotActor.h"
#include "Actors/DirectionalLightActor.h"

// コンストラクタ
GameScene::GameScene()
{
}

// デストラクタ
GameScene::~GameScene()
{
}

// シーン開始
void GameScene::BeginScene()
{
	new TeapotActor(this);
	new DirectionalLightActor(this);
}


// 毎フレームの処理
void GameScene::Tick()
{
}
