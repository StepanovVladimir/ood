#pragma once

template <typename T>
class IObserver
{
public:
	virtual ~IObserver() = default;

	virtual void Update(T const& data) = 0;
	virtual void RemoveFromObservable() = 0;
};