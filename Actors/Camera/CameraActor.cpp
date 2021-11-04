#include "stdafx.h"
#include "CameraActor.h"
#include "Components/CameraComponent.h"

// コンストラクタ
CameraActor::CameraActor(Scene* pInScene)
	: Actor(pInScene)
{
	AddComponent(new CameraComponent(this));
}

// デストラクタ
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


// 毎フレームの処理
void CameraActor::Tick()
{
	for (auto it = positionObservables.begin(); it != positionObservables.end(); ++it)
	{
		(*it)->OnNotice(GetPosition());
	}
}
