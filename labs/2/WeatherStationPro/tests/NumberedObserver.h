#pragma once

#include "../WeatherStationPro/WeatherObserver.h"
#include <iostream>

class CNumberedObserver : public CWeatherObserver
{
public:
	CNumberedObserver(std::ostream &strm, int number);

private:
	void Update(double value, EventType eventType) override;

	std::ostream &m_strm;
	int m_number;
};