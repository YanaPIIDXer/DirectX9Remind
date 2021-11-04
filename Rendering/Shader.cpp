#include "stdafx.h"
#include "Shader.h"
#include "Core/DirectX/DirectXCore.h"

// �R���X�g���N�^
Shader::Shader(const std::function<void(LPD3DXEFFECT)>& onRenderCallback)
	: onRender(onRenderCallback)
	, pEffect(nullptr)
	, technique(nullptr)
{
}

// �f�X�g���N�^
Shader::~Shader()
{
	SAFE_RELEASE(pEffect);
}

// �ǂݍ���
bool Shader::Load(const TCHAR* pFilePath, const char* pTechniqueName)
{
	if (FAILED(D3DXCreateEffectFromFile(DirectXCore::GetDevice(), pFilePath, nullptr, nullptr, 0, nullptr, &pEffect, nullptr)))
	{
		MessageBox(nullptr, _T("Shader�̓ǂݍ��݂Ɏ��s���܂���"), _T("Error"), MB_OK);
		return false;
	}
	technique = pEffect->GetTechniqueByName(pTechniqueName);
	OnLoad(pEffect);
	return true;
}

// �`��
void Shader::Render()
{

}
