#include "stdafx.h"
#include "Shader.h"
#include "Core/DirectX/DirectXCore.h"

// �R���X�g���N�^
Shader::Shader(const RenderCallback& onRenderCallback, const TCHAR* pInFilePath, const char* pInTechniqueName)
	: onRender(onRenderCallback)
	, pFilePath(pInFilePath)
	, pTechniqueName(pInTechniqueName)
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
bool Shader::Load()
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
void Shader::Render(LPDIRECT3DDEVICE9 pDevice)
{
	if (!IsValid()) { return; }

	pEffect->SetTechnique(technique);
	pEffect->Begin(nullptr, 0);
	pEffect->BeginPass(0);

	PreRender(pDevice, pEffect);
	onRender(pDevice, pEffect);

	pEffect->EndPass();
	pEffect->End();
}
