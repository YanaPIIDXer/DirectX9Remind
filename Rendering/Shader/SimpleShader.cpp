#include "stdafx.h"
#include "SimpleShader.h"
#include "Core/DirectX/DirectXCore.h"

// コンストラクタ
SimpleShader::SimpleShader(const RenderCallback& onRenderCallback)
	: Shader(onRenderCallback, _T("Shaders/Simple.fx"), "Simple")
	, mWVP(nullptr)
	, mWIT(nullptr)
{
	D3DXMatrixIdentity(&mWorld);
}

// デストラクタ
SimpleShader::~SimpleShader()
{
}

// 読み込まれた
void SimpleShader::OnLoad(LPD3DXEFFECT pEffect)
{
	mWVP = pEffect->GetParameterByName(nullptr, "mWVP");
	mWIT = pEffect->GetParameterByName(nullptr, "mWIT");
}

// 描画前の処理
void SimpleShader::PreRender(LPDIRECT3DDEVICE9 pDevice, LPD3DXEFFECT pEffect)
{
	D3DXMATRIX mView, mProj;
	pDevice->GetTransform(D3DTS_VIEW, &mView);
	pDevice->GetTransform(D3DTS_PROJECTION, &mProj);

	D3DXMATRIX mat = mWorld * mView * mProj;
	pEffect->SetMatrix(mWVP, &mat);

	D3DXMatrixInverse(&mat, nullptr, &mWorld);
	D3DXMatrixTranspose(&mat, &mat);
	pEffect->SetMatrix(mWIT, &mat);
}
