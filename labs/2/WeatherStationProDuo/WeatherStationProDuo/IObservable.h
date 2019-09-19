#pragma once

#include "IObserver.h"

template <typename T>
class IObservable
{
public:
	virtual ~IObservable() = default;

	virtual bool RegisterObserver(IObserver<T> &observer, size_t priority) = 0;
	virtual void NotifyObservers() const = 0;
	virtual void RemoveObserver(IObserver<T> &observer) = 0;
};