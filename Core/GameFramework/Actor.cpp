#include "stdafx.h"
#include "Actor.h"
#include "Scene.h"

// コンストラクタ
Actor::Actor(Scene* pInScene)
	: pScene(pInScene)
{
}

// デストラクタ
Actor::~Actor()
{
}
