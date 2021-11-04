#include "stdafx.h"
#include <Windows.h>
#include <tchar.h>
#include <d3d9.h>
#include <d3dx9.h>

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// ============== TODO:後で色々とクラス化する時に整理する ===========================

LPDIRECT3D9 pD3D9 = nullptr;
LPDIRECT3DDEVICE9 pDevice = nullptr;
LPD3DXMESH pTeapot = nullptr;

// DirectX関係の初期化
bool InitD3D9(HWND hWnd)
{
	pD3D9 = Direct3DCreate9(D3D_SDK_VERSION);
	if (pD3D9 == nullptr)
	{
		MessageBox(nullptr, _T("Direct3Dの初期化に失敗しました"), _T("Error"), MB_OK);
		return false;
	}

	{
		D3DPRESENT_PARAMETERS params = {};
		params.Windowed = TRUE;
		params.SwapEffect = D3DSWAPEFFECT_DISCARD;
		params.BackBufferFormat = D3DFMT_UNKNOWN;

		if (FAILED(pD3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &params, &pDevice)))
		{
			MessageBox(nullptr, _T("Direct3Dデバイスの初期化に失敗しました"), _T("Error"), MB_OK);
			return false;
		}
	}

	if (FAILED(D3DXCreateTeapot(pDevice, &pTeapot, nullptr)))
	{
		MessageBox(nullptr, _T("ティーポットが砕け散った"), _T("Error"), MB_OK);
		return false;
	}
	return true;
}

// 描画
void Render()
{
	pDevice->Clear(0, nullptr, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	if (FAILED(pDevice->BeginScene())) { return; }

	D3DXMATRIX viewMatrix;
	D3DXVECTOR3 eye(0.0f, 0.0f, 5.0f);
	D3DXVECTOR3 at(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
	D3DXMatrixLookAtLH(&viewMatrix, &eye, &at, &up);
	pDevice->SetTransform(D3DTS_VIEW, &viewMatrix);

	D3DXMATRIX projMat;
	D3DXMatrixPerspectiveFovLH(&projMat, D3DXToRadian(45.0f),  1.0f, 0.1f, 1000.0f);
	pDevice->SetTransform(D3DTS_PROJECTION, &projMat);


	D3DXMATRIX matTeapot;
	D3DXMatrixTranslation(&matTeapot, 0.0f, 0.0f, -5.0f);
	pDevice->SetTransform(D3DTS_WORLD, &matTeapot);
	pTeapot->DrawSubset(0);

	pDevice->EndScene();
	pDevice->Present(nullptr, nullptr, nullptr, nullptr);
}

// DirectX関係の解放
void ReleaseD3D9()
{
	SAFE_RELEASE(pTeapot);
	SAFE_RELEASE(pDevice);
	SAFE_RELEASE(pD3D9);
}

// ==================================================================================

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR pArgs, int argc)
{
	const TCHAR* className = _T("DirectX9");
	WNDCLASSEX windowClass = { sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0, 0, hInstance, nullptr, nullptr, nullptr, nullptr, className, nullptr };
	RegisterClassEx(&windowClass);

	const int windowWidth = 1024;
	const int windowHeight = 768;
	HWND hWnd = CreateWindow(className, _T("DirectX 9 Remind"), WS_OVERLAPPEDWINDOW, 100, 100, windowWidth, windowHeight, nullptr, nullptr, hInstance, nullptr);
	ShowWindow(hWnd, SW_SHOWDEFAULT);

	MSG msg = {};

	if (!InitD3D9(hWnd))
	{
		MessageBox(nullptr, _T("DirectXの初期化に失敗しました"), _T("Error"), MB_OK);
		msg.message = WM_QUIT;		// メッセージループに入らず、安全に解放処理に進むように
	}

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Render();
		}
	}

	ReleaseD3D9();
	UnregisterClass(className, hInstance);
	return 0;
}

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
