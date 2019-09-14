#pragma once

#include "IObservable.h"
#include <map>

template <typename T>
class CObservable : public IObservable<T>
{
public:
	~CObservable()
	{
		std::map<size_t, ObserverType*> observers = m_observers;

		for (auto &observer : observers)
		{
			observer.second->RemoveFromObservable();
		}
	}

	void NotifyObservers() const override
	{
		T data = GetData();
		std::map<size_t, ObserverType*> observers = m_observers;

		for (auto &observer : observers)
		{
			observer.second->Update(data);
		}
	}

protected:
	virtual T GetData() const = 0;

private:
	typedef IObserver<T> ObserverType;

	bool RegisterObserver(ObserverType &observer, size_t priority) override
	{
		return m_observers.try_emplace(priority, &observer).second;
	}

	void RemoveObserver(size_t priority) override
	{
		m_observers.erase(priority);
	}

	std::map<size_t, ObserverType*> m_observers;
};