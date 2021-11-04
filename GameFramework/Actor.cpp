#include "stdafx.h"
#include "Actor.h"
#include "Scene.h"
#include "Component.h"

// �R���X�g���N�^
Actor::Actor(Scene* pInScene)
	: pScene(pInScene)
	, position(0.0f, 0.0f, 0.0f)
	, eulerAngle(0.0f, 0.0f, 0.0f)
	, scale(1.0f, 1.0f, 1.0f)
	, bIsDestroyed(false)
{
	pScene->RegisterActor(this);
}

// �f�X�g���N�^
Actor::~Actor()
{
	for (auto it = components.begin(); it != components.end(); ++it)
	{
		delete (*it);
	}
}

// �X�V
void Actor::Update(LPDIRECT3DDEVICE9 pDevice)
{
	for (auto it = components.begin(); it != components.end(); ++it)
	{
		(*it)->Update(pDevice);
	}
	Tick();
}

// �`��
void Actor::Render(LPDIRECT3DDEVICE9 pDevice)
{
	for (auto it = components.begin(); it != components.end(); ++it)
	{
		(*it)->Render(pDevice);
	}
}

// �p���s����擾
D3DXMATRIX Actor::GetTransformMatrix() const
{
	D3DXMATRIX positionMatrix, rotationMatrix, scaleMatrix;
	D3DXMatrixTranslation(&positionMatrix, position.x, position.y, position.z);
	D3DXMatrixRotationYawPitchRoll(&rotationMatrix, eulerAngle.y, eulerAngle.x, eulerAngle.z);
	D3DXMatrixScaling(&scaleMatrix, scale.x, scale.y, scale.z);
	return scaleMatrix * rotationMatrix * positionMatrix;
}


// �R���|�[�l���g�ǉ�
void Actor::AddComponent(Component* pComponent)
{
	components.push_back(pComponent);
	pComponent->Initialize();
}
