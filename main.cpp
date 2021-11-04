#include <Windows.h>
#include <tchar.h>

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

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
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
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
