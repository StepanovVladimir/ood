#pragma once

#include "ObservableType.h"

template <typename T>
class IObserver
{
public:
	virtual ~IObserver() = default;

	virtual void Update(T const& data, ObservableType observableType) = 0;
	virtual void RemoveFromInObservable() = 0;
	virtual void RemoveFromOutObservable() = 0;
};