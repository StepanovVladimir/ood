#pragma once

#include "IObserver.h"
#include "IObservable.h"

template <typename T>
class CObserver : public IObserver<T>
{
public:
	CObserver()
		: m_inObservable(nullptr)
		, m_outObservable(nullptr)
	{
	}

	~CObserver()
	{
		RemoveFromInObservable();
		RemoveFromOutObservable();
	}

	bool RegisterOnObservable(IObservable<T> &observable, size_t priority)
	{
		if (observable.RegisterObserver(*this, priority))
		{
			if (observable.GetType() == ObservableType::In)
			{
				RemoveFromInObservable();
				m_inObservable = &observable;
				m_inPriority = priority;
			}
			else
			{
				RemoveFromOutObservable();
				m_outObservable = &observable;
				m_outPriority = priority;
			}
			return true;
		}
		return false;
	}

	void RemoveFromInObservable() override
	{
		if (m_inObservable != nullptr)
		{
			m_inObservable->RemoveObserver(m_inPriority);
			m_inObservable = nullptr;
		}
	}

	void RemoveFromOutObservable() override
	{
		if (m_outObservable != nullptr)
		{
			m_outObservable->RemoveObserver(m_outPriority);
			m_outObservable = nullptr;
		}
	}

private:
	IObservable<T> *m_inObservable;
	size_t m_inPriority;

	IObservable<T> *m_outObservable;
	size_t m_outPriority;
};