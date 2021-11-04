#include "stdafx.h"
#include "Actor.h"
#include "Scene.h"
#include "Component.h"

// �R���X�g���N�^
Actor::Actor(Scene* pInScene, const D3DXVECTOR3 &inPosition, const D3DXVECTOR3 &inEulerAngle)
	: pScene(pInScene)
	, position(inPosition)
	, eulerAngle(inEulerAngle)
	, scale(1.0f, 1.0f, 1.0f)
	, bIsDestroyed(false)
{
	pScene->RegisterActor(this);
}

// �f�X�g���N�^
Actor::~Actor()
{
}

// �X�V
void Actor::Update()
{
	for (auto it = components.begin(); it != components.end(); ++it)
	{
		(*it)->Update();
	}
	Tick();
}

// �`��
void Actor::Render()
{
}
