#pragma once

#include "IObserver.h"

template <typename T>
class IObservable
{
public:
	virtual ~IObservable() = default;

	virtual bool RegisterObserver(IObserver<T> &observer, size_t priority, EventType eventType) = 0;
	virtual void RemoveFromEvent(IObserver<T> &observer, EventType eventType) = 0;
	virtual void RemoveObserver(IObserver<T> &observer) = 0;
	
	virtual void NotifyObservers(EventType eventType) const = 0;
};