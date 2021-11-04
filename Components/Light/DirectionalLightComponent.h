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

	// 更新
	// 特に何もしない
	virtual void Update(LPDIRECT3DDEVICE9 pDevice) override {}

private:

	// ライトパラメータ
	D3DLIGHT9 light;
};

#endif		// #ifndef DIRECTIONALLIGHTCOMPONENT_H
