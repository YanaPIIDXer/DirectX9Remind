#include "stdafx.h"
#include "PlayerCamera.h"
#include "Components/Controller/PlayerController.h"

// コンストラクタ
PlayerCamera::PlayerCamera(Scene* pInScene)
	: CameraActor(pInScene)
{
	PlayerController* playerController = new PlayerController(this);
	playerController->SetForwardCallback(std::bind(&PlayerCamera::moveForward, this, std::placeholders::_1));
	playerController->SetRightCallback(std::bind(&PlayerCamera::turnRight, this, std::placeholders::_1));
	AddComponent(playerController);
}

// デストラクタ
PlayerCamera::~PlayerCamera()
{
}


// 上下移動
void PlayerCamera::moveForward(float value)
{
	SetPosition(GetPosition() + D3DXVECTOR3(0.0f, 0.0f, value * 0.5f));
}

// 左右回転
void PlayerCamera::turnRight(float value)
{
	SetEulerAngle(GetEulerAngle() + D3DXVECTOR3(0.0f, value * 0.01f, 0.0f));
}
