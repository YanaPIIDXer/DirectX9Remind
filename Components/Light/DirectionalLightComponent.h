#ifndef DIRECTIONALLIGHTCOMPONENT_H
#define DIRECTIONALLIGHTCOMPONENT_H

#include "LightComponent.h"

// ディレクショナルライトコンポーネント
class DirectionalLightComponent :  public LightComponent
{
public:

	// コンストラクタ
	DirectionalLightComponent(Actor* pInActor);

	// デストラクタ
	virtual ~DirectionalLightComponent();
};

#endif		// #ifndef DIRECTIONALLIGHTCOMPONENT_H
