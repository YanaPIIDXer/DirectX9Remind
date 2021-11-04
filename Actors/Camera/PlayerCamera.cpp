#include "stdafx.h"
#include "PlayerCamera.h"
#include "Components/Controller/PlayerController.h"

// �R���X�g���N�^
PlayerCamera::PlayerCamera(Scene* pInScene)
	: CameraActor(pInScene)
{
	AddComponent(new PlayerController(this));
}

// �f�X�g���N�^
PlayerCamera::~PlayerCamera()
{
}