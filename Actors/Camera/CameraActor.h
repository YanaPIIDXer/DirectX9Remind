#ifndef CAMERAACTOR_H
#define CAMERAACTOR_H

#include "GameFramework/Actor.h"
#include "Util/Observer.h"
#include <vector>

typedef IObservable<D3DXVECTOR3> PositionObservable;

// カメラアクター
class CameraActor : public Actor, public IObserver<D3DXVECTOR3>
{
public:

	// コンストラクタ
	CameraActor(Scene* pInScene);

	// デストラクタ
	virtual ~CameraActor();

	// === IObserverの実装 ===
	virtual void Register(PositionObservable* pObservable) override;
	virtual void Unregister(PositionObservable* pObservable) override;
	// ======================

protected:

	// 毎フレームの処理
	virtual void Tick() override;

private:

	// 座標を受け取るオブジェクトのリスト
	std::vector<PositionObservable*> positionObservables;
};

#endif		// #ifndef CAMERAACTOR_H
