#include "stdafx.h"
#include "TeapotComponent.h"
#include "Core/DirectX/DirectXCore.h"
#include "GameFramework/Actor.h"

// コンストラクタ
TeapotComponent::TeapotComponent(Actor* pInParent)
	: Component(pInParent)
	, pMesh(nullptr)
	, material({})
	, mWVP(nullptr)
{
	if (FAILED(D3DXCreateTeapot(DirectXCore::GetDevice(), &pMesh, nullptr)))
	{
		MessageBox(nullptr, _T("ティーポットが砕け散った"), _T("Error"), MB_OK);
	}

	material.Diffuse = { 1.0f, 1.0f, 1.0f, 1.0f };
	material.Ambient = { 1.0f, 1.0f, 1.0f, 1.0f };
}

// デストラクタ
TeapotComponent::~TeapotComponent()
{
	SAFE_RELEASE(pMesh);
}

// 描画
void TeapotComponent::Render(LPDIRECT3DDEVICE9 pDevice)
{
	if (pMesh == nullptr) { return; }

	//pDevice->SetMaterial(&material);
	/*
	pShaderEffect->SetTechnique(technique);
	pShaderEffect->Begin(nullptr, 0);
	pShaderEffect->BeginPass(0);

	D3DXMATRIX viewMatrix, projMatrix;
	pDevice->GetTransform(D3DTS_VIEW, &viewMatrix);
	pDevice->GetTransform(D3DTS_PROJECTION, &projMatrix);

	D3DXMATRIX mat = GetParent()->GetTransformMatrix() * viewMatrix * projMatrix;
	pShaderEffect->SetMatrix(mWVP, &mat);

	pMesh->DrawSubset(0);

	pShaderEffect->EndPass();
	pShaderEffect->End();
	*/
}
