#include "stdafx.h"
#include "CameraActor.h"
#include "Components/CameraComponent.h"

// コンストラクタ
CameraActor::CameraActor(Scene* pInScene)
	: Actor(pInScene)
{
	AddComponent(new CameraComponent(this));
}

// デストラクタ
CameraActor::~CameraActor()
{
}
