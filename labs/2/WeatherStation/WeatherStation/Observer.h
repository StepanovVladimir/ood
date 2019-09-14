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

	CObserver(IObservable<T> &observable)
		: m_observable(&observable)
	{
		m_observable->RegisterObserver(*this);
	}

	~CObserver()
	{
		RemoveFromObservable();
	}

	void RegisterOnObservable(IObservable<T> &observable)
	{
		if (m_observable != &observable)
		{
			RemoveFromObservable();
			m_observable = &observable;
			m_observable->RegisterObserver(*this);
		}
	}

	void RemoveFromObservable() override
	{
		if (m_observable != nullptr)
		{
			m_observable->RemoveObserver(*this);
			m_observable = nullptr;
		}
	}

private:
	IObservable<T> *m_observable;
};