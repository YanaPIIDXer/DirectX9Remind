#ifndef CAMERACOMPONENT_H
#define CAMERACOMPONENT_H

#include "GameFramework/Component.h"

// カメラコンポーネント
class CameraComponent : public Component
{
public:

	// コンストラクタ
	CameraComponent(Actor* pInParent);

	// デストラクタ
	virtual ~CameraComponent();

	// 更新
	virtual void Update(LPDIRECT3DDEVICE9 pDevice) override;

private:
};

#endif		// #ifndef CAMERACOMPONENT_H
