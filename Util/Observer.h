#ifndef OBSERVER_H
#define OBSERVER_H

// 通知を受け取る為のインタフェース
template <typename T>
class IObservable
{
public:
	virtual ~IPositionObservable() = 0;

	// 通知
	virtual void OnNotice(const T& item) = 0;

	// Observerが破棄された時に呼ばれる
	virtual void OnDisposeObserver() = 0;
};

// イベントを通知する為のインタフェース
template<typename T>
class IObserver
{
public:
	virtual ~IObserver() = 0;

	// 登録
	virtual void Register(IObservable<T>* pObservable) = 0;

	// 破棄.
	virtual void Unregister(IObservable<T>* pObservable) = 0;
};

#endif		// #ifndef OBSERVER_H
