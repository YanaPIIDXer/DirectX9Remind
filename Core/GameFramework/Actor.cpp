#include "stdafx.h"
#include "Actor.h"
#include "Scene.h"

// コンストラクタ
Actor::Actor(Scene* pInScene, const D3DXVECTOR3 &inPosition, const D3DXVECTOR3 &inEulerAngle)
	: pScene(pInScene)
	, position(inPosition)
	, eulerAngle(inEulerAngle)
	, scale(1.0f, 1.0f, 1.0f)
{
	pScene->RegisterActor(this);
}

// デストラクタ
Actor::~Actor()
{
}
