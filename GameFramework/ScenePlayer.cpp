#include "stdafx.h"
#include "ScenePlayer.h"
#include "Scene.h"
#include "Core/DirectX/DirectXCore.h"

// コンストラクタ
ScenePlayer::ScenePlayer(Scene* pInitialScene)
	: pCurrentScene(pInitialScene)
	, pPrevScene(nullptr)
{
	pCurrentScene->BeginScene();
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

	auto* pDevice = DirectXCore::GetDevice();
	pCurrentScene->Update(pDevice);
	if (pCurrentScene->HasNextScene())
	{
		pPrevScene = pCurrentScene;
		pCurrentScene.reset(pCurrentScene->SweepNextScene());
		pCurrentScene->BeginScene();
	}
}

// 描画
void ScenePlayer::Render()
{
	auto* pDevice = DirectXCore::GetDevice();
	pDevice->Clear(0, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	if (FAILED(pDevice->BeginScene())) { return; }

	D3DXMATRIX projMat;
	D3DXMatrixPerspectiveFovLH(&projMat, D3DXToRadian(45.0f), 1024.0f / 768.0f, 0.1f, 1000.0f);
	pDevice->SetTransform(D3DTS_PROJECTION, &projMat);

	pCurrentScene->Render(pDevice);

	pDevice->EndScene();
	pDevice->Present(nullptr, nullptr, nullptr, nullptr);
}
