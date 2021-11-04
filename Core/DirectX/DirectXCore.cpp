#include "stdafx.h"
#include "DirectXCore.h"

DirectXCore DirectXCore::instance;

// コンストラクタ
DirectXCore::DirectXCore()
{
}

// デストラクタ
DirectXCore::~DirectXCore()
{
	release();
}

// 初期化
bool DirectXCore::Initialize(HWND hWnd)
{
	instance.release();		// 一旦解放

	instance.pD3D9 = Direct3DCreate9(D3D_SDK_VERSION);
	if (instance.pD3D9 == nullptr)
	{
		MessageBox(nullptr, _T("Direct3Dの初期化に失敗しました"), _T("Error"), MB_OK);
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
			MessageBox(nullptr, _T("Direct3Dデバイスの初期化に失敗しました"), _T("Error"), MB_OK);
			return false;
		}
	}

	instance.pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	instance.pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);

	return true;
}


// 解放
void DirectXCore::release()
{
	SAFE_RELEASE(pDevice);
	SAFE_RELEASE(pD3D9);
}
