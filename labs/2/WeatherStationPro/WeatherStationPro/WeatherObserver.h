#pragma once

#include "IObservable.h"
#include "WeatherInfo.h"
#include <set>

class CWeatherObserver : public IObserver<WeatherInfo>
{
public:
	CWeatherObserver();
	~CWeatherObserver();

private:
	bool RegisterOnEvent(IObservable<WeatherInfo> &observable, EventType eventType) override;
	void RemoveFromEvent(EventType eventType) override;

	IObservable<WeatherInfo> *m_observable;
	std::set<EventType> m_eventTypes;
};