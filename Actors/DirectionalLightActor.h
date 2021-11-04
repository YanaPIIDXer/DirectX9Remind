#ifndef DIRECTIONALLIGHTACTOR_H
#define DIRECTIONALLIGHTACTOR_H

#include "GameFramework/Actor.h"

// ディレクショナルライトアクター
class DirectionalLightActor : public Actor
{
public:

	// コンストラクタ
	DirectionalLightActor(Scene* pInScene);

	// デストラクタ
	virtual ~DirectionalLightActor();
};

#endif		// #ifndef DIRECTIONALLIGHTACTOR_H
