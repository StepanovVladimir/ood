#pragma once

#include "IObservable.h"
#include <set>

template <typename T>
class CObservable : public IObservable<T>
{
public:
	void NotifyObservers() const override
	{
		T data = GetData();
		std::set<ObserverType*> observers = m_observers;

		for (auto &observer : observers)
		{
			observer->Update(data);
		}
	}

protected:
	virtual T GetData() const = 0;

private:
	typedef IObserver<T> ObserverType;

	void RegisterObserver(ObserverType &observer) override
	{
		m_observers.insert(&observer);
	}

	void RemoveObserver(ObserverType &observer) override
	{
		m_observers.erase(&observer);
	}

	std::set<ObserverType*> m_observers;
};