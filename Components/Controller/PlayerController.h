#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "GameFramework/Component.h"
#include <functional>

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

	// �㉺���̓R�[���o�b�N��ݒ�
	void SetForwardCallback(const std::function<void(float)>& inForwardCallback) { forwardCallback = inForwardCallback; }

	// ���E���̓R�[���o�b�N��ݒ�
	void SetRightCallback(const std::function<void(float)>& inRightCallback) { rightCallback = inRightCallback; }

private:

	// �㉺���̓R�[���o�b�N
	std::function<void(float)> forwardCallback;

	// ���E���̓R�[���o�b�N
	std::function<void(float)> rightCallback;
};

#endif		// #ifndef PLAYERCONTROLLER_H
