#include "stdafx.h"
#include "LightComponent.h"

// �R���X�g���N�^
LightComponent::LightComponent(Actor* pInParent)
	: Component(pInParent)
	, light({})
{
}

// �f�X�g���N�^
LightComponent::~LightComponent()
{
}
