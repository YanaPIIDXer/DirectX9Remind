#include "stdafx.h"
#include "PlayerController.h"
#include "GameFramework/Actor.h"

// �R���X�g���N�^
PlayerController::PlayerController(Actor* pInParent)
	: Component(pInParent)
{
}

// �f�X�g���N�^
PlayerController::~PlayerController()
{
}

// �X�V
void PlayerController::Update(LPDIRECT3DDEVICE9 pDevice)
{
	D3DXVECTOR3 pos = GetParent()->GetPosition();
	if (GetAsyncKeyState(VK_UP))
	{
		pos.z += 1.0f;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		pos.z -= 1.0f;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		pos.x -= 1.0f;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		pos.x += 1.0f;
	}
	GetParent()->SetPosition(pos);
}
