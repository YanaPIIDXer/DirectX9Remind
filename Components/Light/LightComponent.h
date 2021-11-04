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
	
	// 初期化
	virtual void Initialize() override;

	// ライトパラメータを取得
	virtual const D3DLIGHT9& GetLight() const = 0;

protected:

	// ライトの更新
	void UpdateLight();

private:

	// ライトのインデックス
	int lightIndex;

};

#endif		// #ifndef LIGHTCOMPONENT_H
