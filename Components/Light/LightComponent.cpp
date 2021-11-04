#include "stdafx.h"
#include "LightComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Scene.h"

// �R���X�g���N�^
LightComponent::LightComponent(Actor* pInParent)
	: Component(pInParent)
	, lightIndex(-1)
{
}

// �f�X�g���N�^
LightComponent::~LightComponent()
{
}

// ������
void LightComponent::Initialize()
{
	lightIndex = GetParent()->GetScene()->RegisterLight(GetLight());
}


// ���C�g�̍X�V
void LightComponent::UpdateLight()
{
	GetParent()->GetScene()->UpdateLight(lightIndex, GetLight());
}
