#pragma once

#include "IObservable.h"
#include <map>

template <typename T>
class CObservable : public IObservable<T>
{
public:
	typedef IObserver<T> ObserverType;

	~CObservable()
	{
		auto observers = m_observers;

		for (auto &observer : observers)
		{
			observer.second->RemoveFromObservable();
		}
	}

	bool RegisterObserver(ObserverType &observer, size_t priority) override
	{
		if (observer.RegisterOnObservable(*this))
		{
			m_observers.emplace(priority, &observer);
			return true;
		}
		return false;
	}

	void NotifyObservers() const override
	{
		T data = GetData();
		auto observers = m_observers;

		for (auto &observer : observers)
		{
			observer.second->Update(data);
		}
	}

	void RemoveObserver(ObserverType &observer) override
	{
		for (auto iter = m_observers.begin(); iter != m_observers.end(); iter++)
		{
			if (iter->second == &observer)
			{
				iter->second->RemoveFromObservable();
				m_observers.erase(iter);
				break;
			}
		}
	}

	virtual T GetData() const = 0;

private:
	std::multimap<size_t, ObserverType*> m_observers;
};