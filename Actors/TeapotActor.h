#ifndef TEAPOTACTOR_H
#define TEAPOTACTOR_H

#include "GameFramework/Actor.h"
#include "Util/Observer.h"

class TeapotComponent;

// ティーポットアクター
class TeapotActor : public Actor, public IObservable<D3DXVECTOR3>
{
public:

	// コンストラクタ
	TeapotActor(Scene* pInScene, IObserver<D3DXVECTOR3> *pInObserver);

	// デストラクタ
	virtual ~TeapotActor();

	// IObservableの実装
	virtual void OnNotice(const D3DXVECTOR3& item) override;
	virtual void OnDisposeObserver() override;

private:

	// ティーポットコンポーネント
	TeapotComponent* pTeapotComponent;

	// Observer
	IObserver<D3DXVECTOR3>* pCameraObserver;
};

#endif		// #ifndef TEAPOTACTOR_H
