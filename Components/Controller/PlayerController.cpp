#include "stdafx.h"
#include "PlayerController.h"
#include "GameFramework/Actor.h"

// コンストラクタ
PlayerController::PlayerController(Actor* pInParent)
	: Component(pInParent)
{
}

// デストラクタ
PlayerController::~PlayerController()
{
}

// 更新
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
