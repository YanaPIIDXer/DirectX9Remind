#ifndef CAMERAACTOR_H
#define CAMERAACTOR_H

#include "GameFramework/Actor.h"

class CameraActor : public Actor
{
public:

	// �R���X�g���N�^
	CameraActor(Scene* pInScene);

	// �f�X�g���N�^
	virtual ~CameraActor();
};

#endif		// #ifndef CAMERAACTOR_H
