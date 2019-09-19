#pragma once

#include "EventType.h"

template<typename T>
class IObservable;

template <typename T>
class IObserver
{
public:
	virtual ~IObserver() = default;

	virtual bool RegisterOnEvent(IObservable<T> &observable, EventType eventType) = 0;
	virtual void RemoveFromEvent(EventType eventType) = 0;

	virtual void Update(double value, EventType eventType) = 0;
};