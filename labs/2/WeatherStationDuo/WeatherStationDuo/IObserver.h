#pragma once

template<typename T>
class IObservable;

template <typename T>
class IObserver
{
public:
	virtual ~IObserver() = default;

	virtual bool RegisterOnObservable(IObservable<T> &observable) = 0;
	virtual void RemoveFromObservable(const IObservable<T> &observable) = 0;

	virtual void Update(T const& data, const IObservable<T> &observable) = 0;
};