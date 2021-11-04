#include "stdafx.h"
#include "DirectXCore.h"

DirectXCore DirectXCore::instance;

// �R���X�g���N�^
DirectXCore::DirectXCore()
{
}

// �f�X�g���N�^
DirectXCore::~DirectXCore()
{
	release();
}

// ������
bool DirectXCore::Initialize(HWND hWnd)
{
	instance.release();		// ��U���

	instance.pD3D9 = Direct3DCreate9(D3D_SDK_VERSION);
	if (instance.pD3D9 == nullptr)
	{
		MessageBox(nullptr, _T("Direct3D�̏������Ɏ��s���܂���"), _T("Error"), MB_OK);
		return false;
	}

	{
		D3DPRESENT_PARAMETERS params = {};
		params.Windowed = TRUE;
		params.SwapEffect = D3DSWAPEFFECT_DISCARD;
		params.BackBufferFormat = D3DFMT_UNKNOWN;
		params.EnableAutoDepthStencil = TRUE;
		params.AutoDepthStencilFormat = D3DFMT_D16;

		if (FAILED(instance.pD3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &params, &instance.pDevice)))
		{
			MessageBox(nullptr, _T("Direct3D�f�o�C�X�̏������Ɏ��s���܂���"), _T("Error"), MB_OK);
			return false;
		}
	}

	instance.pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	instance.pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);

	return true;
}


// ���
void DirectXCore::release()
{
	SAFE_RELEASE(pDevice);
	SAFE_RELEASE(pD3D9);
}
