#include "stdafx.h"
#include "Shader.h"
#include "Core/DirectX/DirectXCore.h"

// コンストラクタ
Shader::Shader(const RenderCallback& onRenderCallback, const TCHAR* pInFilePath, const char* pInTechniqueName)
	: onRender(onRenderCallback)
	, pFilePath(pInFilePath)
	, pTechniqueName(pInTechniqueName)
	, pEffect(nullptr)
	, technique(nullptr)
{
}

// デストラクタ
Shader::~Shader()
{
	SAFE_RELEASE(pEffect);
}

// 読み込み
bool Shader::Load()
{
	if (FAILED(D3DXCreateEffectFromFile(DirectXCore::GetDevice(), pFilePath, nullptr, nullptr, 0, nullptr, &pEffect, nullptr)))
	{
		MessageBox(nullptr, _T("Shaderの読み込みに失敗しました"), _T("Error"), MB_OK);
		return false;
	}
	technique = pEffect->GetTechniqueByName(pTechniqueName);
	OnLoad(pEffect);
	return true;
}

// 描画
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
