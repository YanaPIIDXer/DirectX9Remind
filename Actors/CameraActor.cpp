#include "stdafx.h"
#include "CameraActor.h"
#include "Components/CameraComponent.h"

// �R���X�g���N�^
CameraActor::CameraActor(Scene* pInScene)
	: Actor(pInScene)
{
	AddComponent(new CameraComponent(this));
}

// �f�X�g���N�^
CameraActor::~CameraActor()
{
}
