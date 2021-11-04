#ifndef TEAPOTCOMPONENT_H
#define TEAPOTCOMPONENT_H

#include "GameFramework/Component.h"
#include "Rendering/Shader/SimpleShader.h"

// �e�B�[�|�b�g�`��Component
class TeapotComponent : public Component
{
public:

	// �R���X�g���N�^
	TeapotComponent(Actor* pInParent);

	// �f�X�g���N�^
	virtual ~TeapotComponent();

	// �X�V
	virtual void Update(LPDIRECT3DDEVICE9 pDevice) override;

	// �`��
	virtual void Render(LPDIRECT3DDEVICE9 pDevice) override;

	// �J�����̍��W��ݒ�
	void SetCameraPosition(const D3DXVECTOR3& position);

private:
	// ���b�V��
	LPD3DXMESH pMesh;

	// �}�e���A��
	D3DMATERIAL9 material;

	// �V�F�[�_
	SimpleShader shader;


	// Shader�ɂ��`��
	void postRender(LPDIRECT3DDEVICE9 pDevice, LPD3DXEFFECT pEffect);
};

#endif		// #ifndef TEAPOTCOMPONENT_H
