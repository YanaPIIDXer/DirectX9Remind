#include "stdafx.h"
#include "CameraComponent.h"
#include "GameFramework/Actor.h"

// コンストラクタ
CameraComponent::CameraComponent(Actor* pInParent)
	: Component(pInParent)
{
}

// デストラクタ
CameraComponent::~CameraComponent()
{
}

// 更新
void CameraComponent::Update(LPDIRECT3DDEVICE9 pDevice)
{
	D3DXMATRIX mat = GetParent()->GetTransformMatrix();
	D3DXVECTOR3 at(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 look(0.0f, 0.0f, 1.0f);
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
	D3DXVec3TransformCoord(&at, &at, &mat);
	D3DXVec3TransformCoord(&look, &look, &mat);
	D3DXVec3TransformCoord(&up, &up, &mat);
	D3DXMATRIX viewMatrix;
	D3DXMatrixLookAtLH(&viewMatrix, &at, &look, &up);
	pDevice->SetTransform(D3DTS_VIEW, &viewMatrix);
}
