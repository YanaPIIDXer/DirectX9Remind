#include "stdafx.h"
#include "DirectionalLightComponent.h"

// �R���X�g���N�^
DirectionalLightComponent::DirectionalLightComponent(Actor* pInParent)
	: LightComponent(pInParent)
	, light({})
{
	light.Type = D3DLIGHT_DIRECTIONAL;
	light.Diffuse = { 1.0f, 1.0f, 1.0f, 1.0f };
	light.Range = 1000.0f;
	light.Direction = D3DXVECTOR3(0.0f, -1.0f, 0.0f);
}

// �f�X�g���N�^
DirectionalLightComponent::~DirectionalLightComponent()
{
}
