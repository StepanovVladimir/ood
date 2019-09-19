#pragma once

#include "../WeatherStationProDuo/WeatherObserverOut.h"
#include <iostream>

class CNumberedObserverOut : public CWeatherObserverOut
{
public:
	CNumberedObserverOut(std::ostream &strm, int number);

private:
	void Update(const WeatherInfoOut &weatherInfo) override;

	std::ostream &m_strm;
	int m_number;
};