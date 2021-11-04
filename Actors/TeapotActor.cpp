#include "stdafx.h"
#include "TeapotActor.h"
#include "Components/TeapotComponent.h"

// �R���X�g���N�^
TeapotActor::TeapotActor(Scene* pInScene, IObserver<D3DXVECTOR3>* pInCameraObserver)
	: Actor(pInScene)
	, pTeapotComponent(new TeapotComponent(this))
	, pCameraObserver(pInCameraObserver)
{
	AddComponent(pTeapotComponent);
	pCameraObserver->Register(this);
}

// �f�X�g���N�^
TeapotActor::~TeapotActor()
{
	if (pCameraObserver != nullptr)
	{
		pCameraObserver->Unregister(this);
	}
}

void TeapotActor::OnNotice(const D3DXVECTOR3& item)
{
	pTeapotComponent->SetCameraPosition(item);
}

void TeapotActor::OnDisposeObserver()
{
	pCameraObserver = nullptr;
}
