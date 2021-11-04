#include "stdafx.h"
#include "PlayerController.h"
#include "GameFramework/Actor.h"

// コンストラクタ
PlayerController::PlayerController(Actor* pInParent)
	: Component(pInParent)
	, forwardCallback([](float value) {})
	, rightCallback([](float value) {})
{
}

// デストラクタ
PlayerController::~PlayerController()
{
}

// 更新
void PlayerController::Update(LPDIRECT3DDEVICE9 pDevice)
{
	D3DXVECTOR2 vec(0.0f, 0.0f);
	if (GetAsyncKeyState(VK_UP))
	{
		vec.y += 1.0f;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		vec.y -= 1.0f;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		vec.x -= 1.0f;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		vec.x += 1.0f;
	}
	D3DXVec2Normalize(&vec, &vec);
	forwardCallback(vec.y);
	rightCallback(vec.x);
}
