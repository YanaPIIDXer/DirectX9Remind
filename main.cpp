#include "stdafx.h"
#include "Core/DirectX/DirectXCore.h"
#include <d3dx9.h>
#include "GameFramework/ScenePlayer.h"
#include "Scene/GameScene.h"

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// ============== TODO:後で色々とクラス化する時に整理する ===========================
/*

// DirectX関係の初期化
bool InitD3D9(HWND hWnd)
{
	if (!DirectXCore::Initialize(hWnd)) { return false; }
	auto *pDevice = DirectXCore::GetDevice();

	D3DLIGHT9 light = {};
	light.Type = D3DLIGHT_DIRECTIONAL;
	light.Diffuse = { 1.0f, 1.0f, 1.0f, 1.0f };
	light.Range = 1000.0f;
	light.Direction = D3DXVECTOR3(0.0f, -1.0f, 0.0f);
	pDevice->SetLight(0, &light);
	pDevice->LightEnable(0, TRUE);

	return true;
}

// 描画
void Render()
{
	auto *pDevice = DirectXCore::GetDevice();

	pDevice->Clear(0, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	if (FAILED(pDevice->BeginScene())) { return; }

	D3DXMATRIX viewMatrix;
	D3DXVECTOR3 eye(0.0f, 0.0f, 5.0f);
	D3DXVECTOR3 at(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
	D3DXMatrixLookAtLH(&viewMatrix, &eye, &at, &up);
	pDevice->SetTransform(D3DTS_VIEW, &viewMatrix);

	pDevice->EndScene();
	pDevice->Present(nullptr, nullptr, nullptr, nullptr);
}
*/
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

	if (!DirectXCore::Initialize(hWnd))
	{
		MessageBox(nullptr, _T("DirectXの初期化に失敗しました"), _T("Error"), MB_OK);
		msg.message = WM_QUIT;		// メッセージループに入らず、安全に解放処理に進むように
	}

	ScenePlayer scenePlayer(new GameScene());

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			scenePlayer.Update();
			scenePlayer.Render();
		}
	}

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
