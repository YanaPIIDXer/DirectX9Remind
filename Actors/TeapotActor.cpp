#include "stdafx.h"
#include "TeapotActor.h"
#include "Components/TeapotComponent.h"

// コンストラクタ
TeapotActor::TeapotActor(Scene* pInScene)
	: Actor(pInScene)
{
	AddComponent(new TeapotComponent(this));
}

// デストラクタ
TeapotActor::~TeapotActor()
{
}
