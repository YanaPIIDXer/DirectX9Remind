#ifndef SHADER_H
#define SHADER_H

#include <functional>

// �V�F�[�_���N���X
class Shader
{
public:

	// �R���X�g���N�^
	Shader(const std::function<void(LPD3DXEFFECT)> &onRenderCallback);

	// �f�X�g���N�^
	virtual ~Shader() = 0;

	// �ǂݍ���
	bool Load(const TCHAR* pFilePath, const char *pTechniqueName);

	// �`��
	void Render();

	// �L�����H
	bool IsValid() const { return (pEffect != nullptr); }

protected:

	// �ǂݍ��݂���������
	virtual void OnLoad(LPD3DXEFFECT pEffect) = 0;

	// �`��O�̏���
	virtual void PreRender(LPD3DXEFFECT pEffect) = 0;

private:

	// �`��R�[���o�b�N
	std::function<void(LPD3DXEFFECT)> onRender;

	// �G�t�F�N�g
	LPD3DXEFFECT pEffect;

	// �e�N�j�b�N
	D3DXHANDLE technique;
};

#endif		// #ifndef SHADER_H
