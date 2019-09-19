#include "pch.h"
#include "WeatherObserver.h"

CWeatherObserver::CWeatherObserver()
	: m_observable(nullptr)
{
}

CWeatherObserver::~CWeatherObserver()
{
	if (m_observable != nullptr)
	{
		m_observable->RemoveObserver(*this);
	}
}

bool CWeatherObserver::RegisterOnEvent(IObservable<WeatherInfo> &observable, EventType eventType)
{
	if (m_observable == nullptr)
	{
		m_observable = &observable;
		m_eventTypes.insert(eventType);
		return true;
	}
	if (m_observable == &observable && m_eventTypes.find(eventType) == m_eventTypes.end())
	{
		m_eventTypes.insert(eventType);
		return true;
	}
	return false;
}

void CWeatherObserver::RemoveFromEvent(EventType eventType)
{
	m_eventTypes.erase(eventType);
	if (m_eventTypes.empty())
	{
		m_observable = nullptr;
	}
}