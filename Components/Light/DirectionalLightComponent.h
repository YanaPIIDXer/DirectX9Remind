#ifndef DIRECTIONALLIGHTCOMPONENT_H
#define DIRECTIONALLIGHTCOMPONENT_H

#include "LightComponent.h"

// �f�B���N�V���i�����C�g�R���|�[�l���g
class DirectionalLightComponent :  public LightComponent
{
public:

	// �R���X�g���N�^
	DirectionalLightComponent(Actor* pInActor);

	// �f�X�g���N�^
	virtual ~DirectionalLightComponent();
};

#endif		// #ifndef DIRECTIONALLIGHTCOMPONENT_H
