#pragma once

#include "IObservable.h"
#include "WeatherInfo.h"

class CWeatherObserver : public IObserver<WeatherInfo>
{
public:
	CWeatherObserver();
	~CWeatherObserver();

private:
	bool RegisterOnObservable(IObservable<WeatherInfo> &observable) override;
	void RemoveFromObservable() override;

	IObservable<WeatherInfo> *m_observable;
};