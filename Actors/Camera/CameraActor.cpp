#include "stdafx.h"
#include "CameraActor.h"
#include "Components/CameraComponent.h"

// �R���X�g���N�^
CameraActor::CameraActor(Scene* pInScene)
	: Actor(pInScene)
{
	AddComponent(new CameraComponent(this));
}

// �f�X�g���N�^
CameraActor::~CameraActor()
{
	for (auto it = positionObservables.begin(); it != positionObservables.end(); ++it)
	{
		(*it)->OnDisposeObserver();
	}
}

void CameraActor::Register(PositionObservable* pObservable)
{
	positionObservables.push_back(pObservable);
}

void CameraActor::Unregister(PositionObservable* pObservable)
{
	for (auto it = positionObservables.begin(); it != positionObservables.end(); ++it)
	{
		if ((*it) == pObservable)
		{
			positionObservables.erase(it);
			return;
		}
	}
}


// ���t���[���̏���
void CameraActor::Tick()
{
	for (auto it = positionObservables.begin(); it != positionObservables.end(); ++it)
	{
		(*it)->OnNotice(GetPosition());
	}
}
