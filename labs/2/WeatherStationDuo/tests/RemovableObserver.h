#pragma once

#include "../WeatherStationDuo/WeatherObserver.h"

class CRemovableObserver : public CWeatherObserver
{
private:
	void Update(const WeatherInfo &weatherInfo, const IObservable<WeatherInfo> &observable) override;
};