#ifndef PLAYERCAMERA_H
#define PLAYERCAMERA_H

#include "CameraActor.h"

// �v���C���[������\�ȃJ����
class PlayerCamera : public CameraActor
{
public:
	// �R���X�g���N�^
	PlayerCamera(Scene* pInScene);

	// �f�X�g���N�^
	virtual ~PlayerCamera();

private:

	// �㉺�ړ�
	void moveForward(float value);

	// ���E����
	void turnRight(float Value);
};

#endif		// #ifndef PLAYERCAMERA_H
