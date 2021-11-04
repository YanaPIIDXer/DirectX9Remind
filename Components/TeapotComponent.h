#ifndef TEAPOTCOMPONENT_H
#define TEAPOTCOMPONENT_H

#include "GameFramework/Component.h"

// �e�B�[�|�b�g�`��Component
class TeapotComponent : public Component
{
public:

	// �R���X�g���N�^
	TeapotComponent(Actor* pInParent);

	// �f�X�g���N�^
	virtual ~TeapotComponent();

	// �X�V
	// �������M�͉������Ȃ�
	virtual void Update(LPDIRECT3DDEVICE9 pDevice) override {}

	// �`��
	virtual void Render(LPDIRECT3DDEVICE9 pDevice) override;

private:
	// ���b�V��
	LPD3DXMESH pMesh;

	// �}�e���A��
	D3DMATERIAL9 material;

	// �V�F�[�_
	LPD3DXEFFECT pShaderEffect;

	// �e�N�j�b�N
	D3DXHANDLE technique;

	// ���[���h�`�ˉe�s��
	D3DXHANDLE mWVP;
};

#endif		// #ifndef TEAPOTCOMPONENT_H
