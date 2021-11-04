#ifndef PLAYERCAMERA_H
#define PLAYERCAMERA_H

#include "CameraActor.h"

// プレイヤーが制御可能なカメラ
class PlayerCamera : public CameraActor
{
public:
	// コンストラクタ
	PlayerCamera(Scene* pInScene);

	// デストラクタ
	virtual ~PlayerCamera();

private:

	// 上下移動
	void moveForward(float value);

	// 左右旋回
	void turnRight(float Value);
};

#endif		// #ifndef PLAYERCAMERA_H
