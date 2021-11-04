#include "stdafx.h"
#include "ScenePlayer.h"
#include "Scene.h"
#include "Core/DirectX/DirectXCore.h"

// �R���X�g���N�^
ScenePlayer::ScenePlayer(Scene* pInitialScene)
	: pCurrentScene(pInitialScene)
	, pPrevScene(nullptr)
{
	pCurrentScene->BeginScene();
}

// �f�X�g���N�^
ScenePlayer::~ScenePlayer()
{
}

// �X�V
void ScenePlayer::Update()
{
	// ���S�ɉ��
	if (pPrevScene != nullptr)
	{
		pPrevScene.reset();
	}

	pCurrentScene->Update();
	if (pCurrentScene->HasNextScene())
	{
		pPrevScene = pCurrentScene;
		pCurrentScene.reset(pCurrentScene->SweepNextScene());
		pCurrentScene->BeginScene();
	}
}

// �`��
void ScenePlayer::Render()
{
	auto* pDevice = DirectXCore::GetDevice();
	pDevice->Clear(0, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	if (FAILED(pDevice->BeginScene())) { return; }

	D3DXMATRIX projMat;
	D3DXMatrixPerspectiveFovLH(&projMat, D3DXToRadian(45.0f), 1.0f, 0.1f, 1000.0f);
	pDevice->SetTransform(D3DTS_PROJECTION, &projMat);

	pCurrentScene->Render(pDevice);

	pDevice->EndScene();
	pDevice->Present(nullptr, nullptr, nullptr, nullptr);
}
