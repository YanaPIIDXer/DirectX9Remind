#ifndef CAMERACOMPONENT_H
#define CAMERACOMPONENT_H

#include "GameFramework/Component.h"

// �J�����R���|�[�l���g
class CameraComponent : public Component
{
public:

	// �R���X�g���N�^
	CameraComponent(Actor* pInParent);

	// �f�X�g���N�^
	virtual ~CameraComponent();

	// �X�V
	virtual void Update(LPDIRECT3DDEVICE9 pDevice) override;

private:
};

#endif		// #ifndef CAMERACOMPONENT_H
