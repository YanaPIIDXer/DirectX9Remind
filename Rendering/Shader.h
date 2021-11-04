#ifndef SHADER_H
#define SHADER_H

#include <functional>

typedef std::function<void(LPDIRECT3DDEVICE9, LPD3DXEFFECT)> RenderCallback;

// �V�F�[�_���N���X
class Shader
{
public:

	// �R���X�g���N�^
	Shader(const RenderCallback &onRenderCallback, const TCHAR* pInFilePath, const char *pInTechniqueName);

	// �f�X�g���N�^
	virtual ~Shader() = 0;

	// �ǂݍ���
	bool Load();

	// �`��
	void Render(LPDIRECT3DDEVICE9 pDevice);

	// �L�����H
	bool IsValid() const { return (pEffect != nullptr); }

protected:

	// �ǂݍ��݂���������
	virtual void OnLoad(LPD3DXEFFECT pEffect) = 0;

	// �`��O�̏���
	virtual void PreRender(LPDIRECT3DDEVICE9 pDevice, LPD3DXEFFECT pEffect) = 0;

private:

	// �`��R�[���o�b�N
	RenderCallback onRender;

	// �t�@�C���p�X
	const TCHAR* pFilePath;

	// �e�N�j�b�N��
	const char* pTechniqueName;

	// �G�t�F�N�g
	LPD3DXEFFECT pEffect;

	// �e�N�j�b�N
	D3DXHANDLE technique;
};

#endif		// #ifndef SHADER_H
