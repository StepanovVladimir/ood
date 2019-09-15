#pragma once

#include "IObserver.h"
#include "IObservable.h"

template <typename T>
class CObserver : public IObserver<T>
{
public:
	CObserver()
		: m_observable(nullptr)
	{
	}

	~CObserver()
	{
		RemoveFromObservable();
	}

	bool RegisterOnObservable(IObservable<T> &observable, size_t priority)
	{
		if (observable.RegisterObserver(*this, priority))
		{
			RemoveFromObservable();
			m_observable = &observable;
			m_priority = priority;
			return true;
		}
		return false;
	}

	void RemoveFromObservable() override
	{
		if (m_observable != nullptr)
		{
			m_observable->RemoveObserver(m_priority);
			m_observable = nullptr;
		}
	}

private:
	IObservable<T> *m_observable;
	size_t m_priority;
};