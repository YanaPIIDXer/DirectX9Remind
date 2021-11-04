#ifndef CAMERAACTOR_H
#define CAMERAACTOR_H

#include "GameFramework/Actor.h"

class CameraActor : public Actor
{
public:

	// コンストラクタ
	CameraActor(Scene* pInScene);

	// デストラクタ
	virtual ~CameraActor();
};

#endif		// #ifndef CAMERAACTOR_H
