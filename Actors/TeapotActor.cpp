#include "stdafx.h"
#include "TeapotActor.h"
#include "Components/TeapotComponent.h"

// �R���X�g���N�^
TeapotActor::TeapotActor(Scene* pInScene)
	: Actor(pInScene)
{
	AddComponent(new TeapotComponent(this));
}

// �f�X�g���N�^
TeapotActor::~TeapotActor()
{
}
