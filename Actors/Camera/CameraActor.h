#ifndef CAMERAACTOR_H
#define CAMERAACTOR_H

#include "GameFramework/Actor.h"
#include "Util/Observer.h"
#include <vector>

typedef IObservable<D3DXVECTOR3> PositionObservable;

// �J�����A�N�^�[
class CameraActor : public Actor, public IObserver<D3DXVECTOR3>
{
public:

	// �R���X�g���N�^
	CameraActor(Scene* pInScene);

	// �f�X�g���N�^
	virtual ~CameraActor();

	// === IObserver�̎��� ===
	virtual void Register(PositionObservable* pObservable) override;
	virtual void Unregister(PositionObservable* pObservable) override;
	// ======================

protected:

	// ���t���[���̏���
	virtual void Tick() override;

private:

	// ���W���󂯎��I�u�W�F�N�g�̃��X�g
	std::vector<PositionObservable*> positionObservables;
};

#endif		// #ifndef CAMERAACTOR_H
