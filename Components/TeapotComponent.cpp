#include "stdafx.h"
#include "TeapotComponent.h"
#include "Core/DirectX/DirectXCore.h"
#include "GameFramework/Actor.h"

// �R���X�g���N�^
TeapotComponent::TeapotComponent(Actor* pInParent)
	: Component(pInParent)
	, pMesh(nullptr)
	, material({})
	, shader(std::bind(&TeapotComponent::postRender, this, std::placeholders::_1, std::placeholders::_2))
{
	if (FAILED(D3DXCreateTeapot(DirectXCore::GetDevice(), &pMesh, nullptr)))
	{
		MessageBox(nullptr, _T("�e�B�[�|�b�g���ӂ��U����"), _T("Error"), MB_OK);
	}

	shader.Load();

	material.Diffuse = { 1.0f, 1.0f, 1.0f, 1.0f };
	material.Ambient = { 1.0f, 1.0f, 1.0f, 1.0f };
}

// �f�X�g���N�^
TeapotComponent::~TeapotComponent()
{
	SAFE_RELEASE(pMesh);
}

// �X�V
void TeapotComponent::Update(LPDIRECT3DDEVICE9 pDevice)
{
	shader.SetWorldMatrix(GetParent()->GetTransformMatrix());
}

// �`��
void TeapotComponent::Render(LPDIRECT3DDEVICE9 pDevice)
{
	if (pMesh == nullptr) { return; }
	shader.Render(pDevice);
}


// Shader�ł̕`��
void TeapotComponent::postRender(LPDIRECT3DDEVICE9 pDevice, LPD3DXEFFECT pEffect)
{
	pMesh->DrawSubset(0);
}
