#include "stdafx.h"
#include "LightComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Scene.h"

// コンストラクタ
LightComponent::LightComponent(Actor* pInParent)
	: Component(pInParent)
{
}

// デストラクタ
LightComponent::~LightComponent()
{
}

// 初期化
void LightComponent::Initialize()
{
	GetParent()->GetScene()->RegisterLight(GetLight());
}
