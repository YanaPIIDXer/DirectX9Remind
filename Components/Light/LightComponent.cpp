#include "stdafx.h"
#include "LightComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Scene.h"

// �R���X�g���N�^
LightComponent::LightComponent(Actor* pInParent)
	: Component(pInParent)
{
}

// �f�X�g���N�^
LightComponent::~LightComponent()
{
}

// ������
void LightComponent::Initialize()
{
	GetParent()->GetScene()->RegisterLight(GetLight());
}
