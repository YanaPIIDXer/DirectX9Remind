#include <Windows.h>
#include <tchar.h>
#include <d3d9.h>

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// ============== TODO:��ŐF�X�ƃN���X�����鎞�ɐ������� ===========================

// ���S�ȉ��
#define SAFE_RELEASE(p) if (p != nullptr) { p->Release(); p = nullptr; }

LPDIRECT3D9 pD3D9 = nullptr;
LPDIRECT3DDEVICE9 pDevice = nullptr;

// DirectX�֌W�̏�����
bool InitD3D9(HWND hWnd)
{
	pD3D9 = Direct3DCreate9(D3D_SDK_VERSION);
	if (pD3D9 == nullptr)
	{
		MessageBox(nullptr, _T("Direct3D�̏������Ɏ��s���܂���"), _T("Error"), MB_OK);
		return false;
	}

	{
		D3DPRESENT_PARAMETERS params = {};
		params.Windowed = TRUE;
		params.SwapEffect = D3DSWAPEFFECT_DISCARD;
		params.BackBufferFormat = D3DFMT_UNKNOWN;

		if (FAILED(pD3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &params, &pDevice)))
		{
			MessageBox(nullptr, _T("Direct3D�f�o�C�X�̏������Ɏ��s���܂���"), _T("Error"), MB_OK);
			return false;
		}
	}
	return true;
}

// DirectX�֌W�̉��
void ReleaseD3D9()
{
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
		MessageBox(nullptr, _T("DirectX�̏������Ɏ��s���܂���"), _T("Error"), MB_OK);
		msg.message = WM_QUIT;		// ���b�Z�[�W���[�v�ɓ��炸�A���S�ɉ�������ɐi�ނ悤��
	}

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
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
