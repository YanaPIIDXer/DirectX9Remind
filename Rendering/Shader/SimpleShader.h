#ifndef SIMPLESHADER_H
#define SIMPLESHADER_H

#include "Rendering/Shader.h"

// �V���v����Shader
class SimpleShader : public Shader
{
public:

	// �R���X�g���N�^
	SimpleShader(const RenderCallback &onRenderCallback);

	// �f�X�g���N�^
	virtual ~SimpleShader();

	// ���[���h�s���ݒ�
	void SetWorldMatrix(const D3DXMATRIX& mInWorld) { mWorld = mInWorld; }

	// �J�����̍��W��ݒ�
	void SetCameraPosition(const D3DXVECTOR3& position);

protected:

	// �ǂݍ��܂ꂽ
	virtual void OnLoad(LPD3DXEFFECT pEffect) override;

	// �`��O�̏���
	virtual void PreRender(LPDIRECT3DDEVICE9 pDevice, LPD3DXEFFECT pEffect) override;

private:

	// ���[���h�s��
	D3DXMATRIX mWorld;

	// World View Projection Matrix
	D3DXHANDLE mWVP;

	// World Inverse Transpose Matrix
	D3DXHANDLE mWIT;

	// �J�����̍��W�E�n���h��
	D3DXVECTOR3 cameraPos;
	D3DXHANDLE cameraPosHandle;

};

#endif		// #ifndef SIMPLESHADER_H
