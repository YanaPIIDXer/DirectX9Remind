#include "stdafx.h"
#include "LightComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Scene.h"

// コンストラクタ
LightComponent::LightComponent(Actor* pInParent)
	: Component(pInParent)
	, lightIndex(-1)
{
}

// デストラクタ
LightComponent::~LightComponent()
{
}

// 初期化
void LightComponent::Initialize()
{
	lightIndex = GetParent()->GetScene()->RegisterLight(GetLight());
}
