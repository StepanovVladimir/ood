#include "pch.h"
#include "RemovableObserver.h"

void CRemovableObserver::Update(const WeatherInfo &weatherInfo, const IObservable<WeatherInfo> &observable)
{
	if (m_inObservable == &observable)
	{
		m_inObservable->RemoveObserver(*this);
	}
	if (m_outObservable == &observable)
	{
		m_outObservable->RemoveObserver(*this);
	}
}