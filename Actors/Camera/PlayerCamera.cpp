#include "stdafx.h"
#include "PlayerCamera.h"
#include "Components/Controller/PlayerController.h"

// コンストラクタ
PlayerCamera::PlayerCamera(Scene* pInScene)
	: CameraActor(pInScene)
{
	AddComponent(new PlayerController(this));
}

// デストラクタ
PlayerCamera::~PlayerCamera()
{
}