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
};

#endif		// #ifndef PLAYERCAMERA_H
