#ifndef LIGHTCOMPONENT_H
#define LIGHTCOMPONENT_H

#include "GameFramework/Component.h"

// ライトコンポーネント基底クラス
// ※UE4だとStaticライトとかMovableライトとかあるけど、
//   今回は「全部Movable」と言う前提で設計する
class LightComponent : public Component
{
public:

	// コンストラクタ
	LightComponent(Actor* pInParent);

	// デストラクタ
	virtual ~LightComponent() = 0;

	// ライトパラメータを取得
	const D3DLIGHT9& GetLight() const { return light; }

private:

	// ライトパラメータ
	D3DLIGHT9 light;
};

#endif		// #ifndef LIGHTCOMPONENT_H
