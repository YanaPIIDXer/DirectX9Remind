#include "stdafx.h"
#include "Component.h"

// コンストラクタ
Component::Component(Actor* pInParent)
	: pParent(pInParent)
{
}

// デストラクタ
Component::~Component()
{
}
