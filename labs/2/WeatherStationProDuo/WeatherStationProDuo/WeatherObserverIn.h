#pragma once

#include "IObservable.h"
#include "WeatherInfo.h"

class CWeatherObserverIn : public IObserver<WeatherInfoIn>
{
public:
	CWeatherObserverIn();
	~CWeatherObserverIn();

private:
	bool RegisterOnObservable(IObservable<WeatherInfoIn> &observable) override;
	void RemoveFromObservable() override;

	IObservable<WeatherInfoIn> *m_observable;
};