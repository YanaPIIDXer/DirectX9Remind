#include "stdafx.h"
#include "GameScene.h"
#include "Actors/TeapotActor.h"
#include "Actors/DirectionalLightActor.h"
#include "Actors/Camera/PlayerCamera.h"

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
	auto *pTeapot = new TeapotActor(this);
	pTeapot->SetPosition(D3DXVECTOR3(0.0f, 0.0f, 10.0f));
	new DirectionalLightActor(this);
	new PlayerCamera(this);
}


// 毎フレームの処理
void GameScene::Tick()
{
}
