#include "stdafx.h"
#include "GameScene.h"
#include "Actors/TeapotActor.h"
#include "Actors/DirectionalLightActor.h"
#include "Actors/CameraActor.h"

// �R���X�g���N�^
GameScene::GameScene()
{
}

// �f�X�g���N�^
GameScene::~GameScene()
{
}

// �V�[���J�n
void GameScene::BeginScene()
{
	auto *pTeapot = new TeapotActor(this);
	pTeapot->SetPosition(D3DXVECTOR3(0.0f, 0.0f, 10.0f));
	new DirectionalLightActor(this);
	new CameraActor(this);
}


// ���t���[���̏���
void GameScene::Tick()
{
}
