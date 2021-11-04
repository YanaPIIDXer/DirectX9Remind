#ifndef DIRECTXCORE_H
#define DIRECTXCORE_H

#include <d3d9.h>
#include <Windows.h>

// DirectXのコア
class DirectXCore
{
public:
	// デストラクタ
	~DirectXCore();

	// 初期化
	static bool Initialize(HWND hWnd);

	// デバイス取得
	static LPDIRECT3DDEVICE9 GetDevice() { return instance.pDevice; }

private:

	// Direct3D9
	LPDIRECT3D9 pD3D9 = nullptr;

	// Direct3Dデバイス
	LPDIRECT3DDEVICE9 pDevice = nullptr;


	// 解放
	void release();

// ====== Signleton ======
public:

	// インスタンス取得
	DirectXCore& GetInstance() { return instance; }

private:
	// コンストラクタ
	DirectXCore();

	// インスタンス
	static DirectXCore instance;
};

#endif		// #ifndef DIRECTXCORE_H
