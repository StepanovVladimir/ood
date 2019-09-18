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
	void RemoveFromObservable(const IObservable<WeatherInfo> &observable) override;

protected:
	IObservable<WeatherInfo> *m_inObservable;
	IObservable<WeatherInfo> *m_outObservable;
};