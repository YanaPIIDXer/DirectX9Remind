#include "stdafx.h"
#include "Shader.h"
#include "Core/DirectX/DirectXCore.h"

// コンストラクタ
Shader::Shader(const std::function<void(LPD3DXEFFECT)>& onRenderCallback)
	: onRender(onRenderCallback)
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
bool Shader::Load(const TCHAR* pFilePath, const char* pTechniqueName)
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
void Shader::Render()
{

}
