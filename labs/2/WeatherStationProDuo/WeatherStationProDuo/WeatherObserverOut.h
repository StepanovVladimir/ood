#pragma once

#include "IObservable.h"
#include "WeatherInfo.h"

class CWeatherObserverOut : public IObserver<WeatherInfoOut>
{
public:
	CWeatherObserverOut();
	~CWeatherObserverOut();

private:
	bool RegisterOnObservable(IObservable<WeatherInfoOut> &observable) override;
	void RemoveFromObservable() override;

	IObservable<WeatherInfoOut> *m_observable;
};