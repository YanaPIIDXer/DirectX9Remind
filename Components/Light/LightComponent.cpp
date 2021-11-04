#include "stdafx.h"
#include "LightComponent.h"

// コンストラクタ
LightComponent::LightComponent(Actor* pInParent)
	: Component(pInParent)
	, light({})
{
}

// デストラクタ
LightComponent::~LightComponent()
{
}
