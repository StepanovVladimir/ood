#pragma once

#include "../WeatherStation/WeatherObserver.h"
#include <iostream>

class CNumberedObserver : public CWeatherObserver
{
public:
	CNumberedObserver(std::ostream &strm, int number);

private:
	void Update(const WeatherInfo &weatherInfo) override;

	std::ostream &m_strm;
	int m_number;
};