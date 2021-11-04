#ifndef LIGHTCOMPONENT_H
#define LIGHTCOMPONENT_H

#include "GameFramework/Component.h"

// ���C�g�R���|�[�l���g���N���X
// ��UE4����Static���C�g�Ƃ�Movable���C�g�Ƃ����邯�ǁA
//   ����́u�S��Movable�v�ƌ����O��Ő݌v����
class LightComponent : public Component
{
public:

	// �R���X�g���N�^
	LightComponent(Actor* pInParent);

	// �f�X�g���N�^
	virtual ~LightComponent() = 0;

	// ���C�g�p�����[�^���擾
	const D3DLIGHT9& GetLight() const { return light; }

private:

	// ���C�g�p�����[�^
	D3DLIGHT9 light;
};

#endif		// #ifndef LIGHTCOMPONENT_H
