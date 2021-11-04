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

	// ライトパラメータ取得
	virtual const D3DLIGHT9& GetLight() const override { return light; }

private:

	// ライトパラメータ
	D3DLIGHT9 light;
};

#endif		// #ifndef DIRECTIONALLIGHTCOMPONENT_H
