#include "stdafx.h"
#include "GameScene.h"
#include "Actors/TeapotActor.h"
#include "Actors/DirectionalLightActor.h"

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
	new TeapotActor(this);
	new DirectionalLightActor(this);
}


// ���t���[���̏���
void GameScene::Tick()
{
}
