#include "stdafx.h"
#include "Actor.h"
#include "Scene.h"
#include "Component.h"

// コンストラクタ
Actor::Actor(Scene* pInScene, const D3DXVECTOR3 &inPosition, const D3DXVECTOR3 &inEulerAngle)
	: pScene(pInScene)
	, position(inPosition)
	, eulerAngle(inEulerAngle)
	, scale(1.0f, 1.0f, 1.0f)
	, bIsDestroyed(false)
{
	pScene->RegisterActor(this);
}

// デストラクタ
Actor::~Actor()
{
}

// 更新
void Actor::Update()
{
	for (auto it = components.begin(); it != components.end(); ++it)
	{
		(*it)->Update();
	}
	Tick();
}

// 描画
void Actor::Render()
{
}
