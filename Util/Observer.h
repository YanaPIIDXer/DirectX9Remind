#ifndef OBSERVER_H
#define OBSERVER_H

// �ʒm���󂯎��ׂ̃C���^�t�F�[�X
template <typename T>
class IObservable
{
public:
	// �ʒm
	virtual void OnNotice(const T& item) = 0;

	// Observer���j�����ꂽ���ɌĂ΂��
	virtual void OnDisposeObserver() = 0;
};

// �C�x���g��ʒm����ׂ̃C���^�t�F�[�X
template<typename T>
class IObserver
{
public:
	// �o�^
	virtual void Register(IObservable<T>* pObservable) = 0;

	// �j��.
	virtual void Unregister(IObservable<T>* pObservable) = 0;
};

#endif		// #ifndef OBSERVER_H