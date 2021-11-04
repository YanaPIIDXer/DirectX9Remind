#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "GameFramework/Component.h"

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
};

#endif		// #ifndef PLAYERCONTROLLER_H
