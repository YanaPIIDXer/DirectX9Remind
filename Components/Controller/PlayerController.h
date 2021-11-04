#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "GameFramework/Component.h"
#include <functional>

// プレイヤー制御Component
class PlayerController : public Component
{
public:

	// コンストラクタ
	PlayerController(Actor* pInParent);

	// デストラクタ
	virtual ~PlayerController();

	// 更新
	virtual void Update(LPDIRECT3DDEVICE9 pDevice) override;

	// 上下入力コールバックを設定
	void SetForwardCallback(const std::function<void(float)>& inForwardCallback) { forwardCallback = inForwardCallback; }

	// 左右入力コールバックを設定
	void SetRightCallback(const std::function<void(float)>& inRightCallback) { rightCallback = inRightCallback; }

private:

	// 上下入力コールバック
	std::function<void(float)> forwardCallback;

	// 左右入力コールバック
	std::function<void(float)> rightCallback;
};

#endif		// #ifndef PLAYERCONTROLLER_H
