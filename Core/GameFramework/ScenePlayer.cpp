#include "stdafx.h"
#include "ScenePlayer.h"
#include "Scene.h"
#include "Core/DirectX/DirectXCore.h"

// コンストラクタ
ScenePlayer::ScenePlayer(Scene* pInitialScene)
	: pCurrentScene(pInitialScene)
	, pPrevScene(nullptr)
{
}

// デストラクタ
ScenePlayer::~ScenePlayer()
{
}

// 更新
void ScenePlayer::Update()
{
	// 安全に解体
	if (pPrevScene != nullptr)
	{
		pPrevScene.reset();
	}

	pCurrentScene->Update();
	if (pCurrentScene->HasNextScene())
	{
		pPrevScene = pCurrentScene;
		pCurrentScene.reset(pCurrentScene->SweepNextScene());
	}
}

// 描画
void ScenePlayer::Render()
{
	auto* pDevice = DirectXCore::GetDevice();
	pDevice->Clear(0, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	if (FAILED(pDevice->BeginScene())) { return; }

	pCurrentScene->Render(pDevice);

	pDevice->EndScene();
	pDevice->Present(nullptr, nullptr, nullptr, nullptr);
}
