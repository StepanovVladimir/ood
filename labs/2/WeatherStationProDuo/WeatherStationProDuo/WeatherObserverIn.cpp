#include "pch.h"
#include "WeatherObserverIn.h"

CWeatherObserverIn::CWeatherObserverIn()
	: m_observable(nullptr)
{
}

CWeatherObserverIn::~CWeatherObserverIn()
{
	if (m_observable != nullptr)
	{
		m_observable->RemoveObserver(*this);
	}
}

bool CWeatherObserverIn::RegisterOnObservable(IObservable<WeatherInfoIn> &observable)
{
	if (m_observable == nullptr)
	{
		m_observable = &observable;
		return true;
	}
	return false;
}

void CWeatherObserverIn::RemoveFromObservable()
{
	m_observable = nullptr;
}