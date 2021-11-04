#include "stdafx.h"
#include "PlayerCamera.h"
#include "Components/Controller/PlayerController.h"

// �R���X�g���N�^
PlayerCamera::PlayerCamera(Scene* pInScene)
	: CameraActor(pInScene)
{
	PlayerController* playerController = new PlayerController(this);
	playerController->SetForwardCallback(std::bind(&PlayerCamera::moveForward, this, std::placeholders::_1));
	playerController->SetRightCallback(std::bind(&PlayerCamera::turnRight, this, std::placeholders::_1));
	AddComponent(playerController);
}

// �f�X�g���N�^
PlayerCamera::~PlayerCamera()
{
}


// �㉺�ړ�
void PlayerCamera::moveForward(float value)
{
	SetPosition(GetPosition() + D3DXVECTOR3(0.0f, 0.0f, value * 0.5f));
}

// ���E��]
void PlayerCamera::turnRight(float value)
{
	SetEulerAngle(GetEulerAngle() + D3DXVECTOR3(0.0f, value * 0.01f, 0.0f));
}
