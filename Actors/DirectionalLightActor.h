#ifndef DIRECTIONALLIGHTACTOR_H
#define DIRECTIONALLIGHTACTOR_H

#include "GameFramework/Actor.h"

// �f�B���N�V���i�����C�g�A�N�^�[
class DirectionalLightActor : public Actor
{
public:

	// �R���X�g���N�^
	DirectionalLightActor(Scene* pInScene);

	// �f�X�g���N�^
	virtual ~DirectionalLightActor();
};

#endif		// #ifndef DIRECTIONALLIGHTACTOR_H
