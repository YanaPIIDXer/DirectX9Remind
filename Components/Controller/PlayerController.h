#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "GameFramework/Component.h"

// �v���C���[����Component
class PlayerController : public Component
{
public:

	// �R���X�g���N�^
	PlayerController(Actor* pInParent);

	// �f�X�g���N�^
	virtual ~PlayerController();

	// �X�V
	virtual void Update(LPDIRECT3DDEVICE9 pDevice) override;
};

#endif		// #ifndef PLAYERCONTROLLER_H
