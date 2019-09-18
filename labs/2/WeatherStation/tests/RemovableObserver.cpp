#include "pch.h"
#include "RemovableObserver.h"

CRemovableObserver::CRemovableObserver()
	: m_observable(nullptr)
{
}

CRemovableObserver::~CRemovableObserver()
{
	if (m_observable != nullptr)
	{
		m_observable->RemoveObserver(*this);
	}
}

bool CRemovableObserver::RegisterOnObservable(IObservable<WeatherInfo> &observable)
{
	if (m_observable == nullptr)
	{
		m_observable = &observable;
		return true;
	}
	return false;
}

void CRemovableObserver::RemoveFromObservable()
{
	m_observable = nullptr;
}

void CRemovableObserver::Update(const WeatherInfo &weatherInfo)
{
	m_observable->RemoveObserver(*this);
}