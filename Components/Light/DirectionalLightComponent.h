#ifndef DIRECTIONALLIGHTCOMPONENT_H
#define DIRECTIONALLIGHTCOMPONENT_H

#include "LightComponent.h"

// �f�B���N�V���i�����C�g�R���|�[�l���g
class DirectionalLightComponent :  public LightComponent
{
public:

	// �R���X�g���N�^
	DirectionalLightComponent(Actor* pInActor);

	// �f�X�g���N�^
	virtual ~DirectionalLightComponent();

	// ���C�g�p�����[�^�擾
	virtual const D3DLIGHT9& GetLight() const override { return light; }

	// �X�V
	// ���ɉ������Ȃ�
	virtual void Update(LPDIRECT3DDEVICE9 pDevice) override {}

private:

	// ���C�g�p�����[�^
	D3DLIGHT9 light;
};

#endif		// #ifndef DIRECTIONALLIGHTCOMPONENT_H
