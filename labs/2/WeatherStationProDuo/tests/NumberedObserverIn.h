#pragma once

#include "../WeatherStationProDuo/WeatherObserverIn.h"
#include <iostream>

class CNumberedObserverIn : public CWeatherObserverIn
{
public:
	CNumberedObserverIn(std::ostream &strm, int number);

private:
	void Update(const WeatherInfoIn &weatherInfo) override;

	std::ostream &m_strm;
	int m_number;
};