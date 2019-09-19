#include "pch.h"
#include "WeatherObserverOut.h"

CWeatherObserverOut::CWeatherObserverOut()
	: m_observable(nullptr)
{
}

CWeatherObserverOut::~CWeatherObserverOut()
{
	if (m_observable != nullptr)
	{
		m_observable->RemoveObserver(*this);
	}
}

bool CWeatherObserverOut::RegisterOnObservable(IObservable<WeatherInfoOut> &observable)
{
	if (m_observable == nullptr)
	{
		m_observable = &observable;
		return true;
	}
	return false;
}

void CWeatherObserverOut::RemoveFromObservable()
{
	m_observable = nullptr;
}