#pragma once

#include "IObservable.h"
#include <set>

template <typename T>
class CObservable : public IObservable<T>
{
public:
	typedef IObserver<T> ObserverType;

	void RegisterObserver(ObserverType &observer) override
	{
		m_observers.insert(&observer);
	}

	void NotifyObservers() const override
	{
		T data = GetData();
		for (auto &observer : m_observers)
		{
			observer->Update(data);
		}
	}

	void RemoveObserver(ObserverType &observer) override
	{
		m_observers.erase(&observer);
	}

protected:
	virtual T GetData() const = 0;

private:
	std::set<ObserverType*> m_observers;
};