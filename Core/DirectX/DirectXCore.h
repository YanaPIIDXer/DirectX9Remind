#ifndef DIRECTXCORE_H
#define DIRECTXCORE_H

#include <d3d9.h>
#include <Windows.h>

// DirectX�̃R�A
class DirectXCore
{
public:
	// �f�X�g���N�^
	~DirectXCore();

	// ������
	static bool Initialize(HWND hWnd);

	// �f�o�C�X�擾
	static LPDIRECT3DDEVICE9 GetDevice() { return instance.pDevice; }

private:

	// Direct3D9
	LPDIRECT3D9 pD3D9 = nullptr;

	// Direct3D�f�o�C�X
	LPDIRECT3DDEVICE9 pDevice = nullptr;


	// ���
	void release();

// ====== Signleton ======
public:

	// �C���X�^���X�擾
	DirectXCore& GetInstance() { return instance; }

private:
	// �R���X�g���N�^
	DirectXCore();

	// �C���X�^���X
	static DirectXCore instance;
};

#endif		// #ifndef DIRECTXCORE_H
