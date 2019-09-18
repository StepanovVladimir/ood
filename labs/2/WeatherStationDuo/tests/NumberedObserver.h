#pragma once

#include "../WeatherStationDuo/WeatherObserver.h"
#include <iostream>

class CNumberedObserver : public CWeatherObserver
{
public:
	CNumberedObserver(std::ostream &strm, int number);

private:
	void Update(const WeatherInfo &weatherInfo, const IObservable<WeatherInfo> &observable) override;

	std::ostream &m_strm;
	int m_number;
};

