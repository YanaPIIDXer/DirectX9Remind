#include "stdafx.h"
#include "DirectionalLightActor.h"
#include "Components/Light/DirectionalLightComponent.h"

// �R���X�g���N�^
DirectionalLightActor::DirectionalLightActor(Scene* pInScene)
	: Actor(pInScene)
{
	AddComponent(new DirectionalLightComponent(this));
}

// �f�X�g���N�^
DirectionalLightActor::~DirectionalLightActor()
{
}
