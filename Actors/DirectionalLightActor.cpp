#include "stdafx.h"
#include "DirectionalLightActor.h"
#include "Components/Light/DirectionalLightComponent.h"

// コンストラクタ
DirectionalLightActor::DirectionalLightActor(Scene* pInScene)
	: Actor(pInScene)
{
	AddComponent(new DirectionalLightComponent(this));
}

// デストラクタ
DirectionalLightActor::~DirectionalLightActor()
{
}
