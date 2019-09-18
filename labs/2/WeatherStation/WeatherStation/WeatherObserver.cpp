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

bool CWeatherObserver::RegisterOnObservable(IObservable<WeatherInfo> &observable)
{
	if (m_observable == nullptr)
	{
		m_observable = &observable;
		return true;
	}
	return false;
}

void CWeatherObserver::RemoveFromObservable()
{
	m_observable = nullptr;
}