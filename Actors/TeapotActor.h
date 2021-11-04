#ifndef TEAPOTACTOR_H
#define TEAPOTACTOR_H

#include "GameFramework/Actor.h"
#include "Util/Observer.h"

class TeapotComponent;

// �e�B�[�|�b�g�A�N�^�[
class TeapotActor : public Actor, public IObservable<D3DXVECTOR3>
{
public:

	// �R���X�g���N�^
	TeapotActor(Scene* pInScene, IObserver<D3DXVECTOR3> *pInObserver);

	// �f�X�g���N�^
	virtual ~TeapotActor();

	// IObservable�̎���
	virtual void OnNotice(const D3DXVECTOR3& item) override;
	virtual void OnDisposeObserver() override;

private:

	// �e�B�[�|�b�g�R���|�[�l���g
	TeapotComponent* pTeapotComponent;

	// Observer
	IObserver<D3DXVECTOR3>* pCameraObserver;
};

#endif		// #ifndef TEAPOTACTOR_H
