#include "stdafx.h"
#include "TeapotComponent.h"
#include "Core/DirectX/DirectXCore.h"
#include "GameFramework/Actor.h"

// コンストラクタ
TeapotComponent::TeapotComponent(Actor* pInParent)
	: Component(pInParent)
	, pMesh(nullptr)
	, material({})
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

	pDevice->SetMaterial(&material);

	D3DXMATRIX mat = GetParent()->GetTransformMatrix();
	pDevice->SetTransform(D3DTS_WORLD, &mat);

	pMesh->DrawSubset(0);
}
