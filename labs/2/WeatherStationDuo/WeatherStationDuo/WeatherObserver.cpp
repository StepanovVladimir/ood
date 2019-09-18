#include "pch.h"
#include "WeatherObserver.h"

CWeatherObserver::CWeatherObserver()
	: m_inObservable(nullptr)
	, m_outObservable(nullptr)
{
}

CWeatherObserver::~CWeatherObserver()
{
	if (m_inObservable != nullptr)
	{
		m_inObservable->RemoveObserver(*this);
	}
	if (m_outObservable != nullptr)
	{
		m_outObservable->RemoveObserver(*this);
	}
}

bool CWeatherObserver::RegisterOnObservable(IObservable<WeatherInfo> &observable)
{
	if (m_inObservable == nullptr)
	{
		m_inObservable = &observable;
		return true;
	}
	if (m_outObservable == nullptr && m_inObservable != &observable)
	{
		m_outObservable = &observable;
		return true;
	}
	return false;
}

void CWeatherObserver::RemoveFromObservable(const IObservable<WeatherInfo> &observable)
{
	if (m_inObservable == &observable)
	{
		m_inObservable = nullptr;
	}
	if (m_outObservable == &observable)
	{
		m_outObservable = nullptr;
	}
}