#pragma once

#include "WeatherObserver.h"
#include "Statistics.h"

class CStatisticsDisplay : public CWeatherObserver
{
private:
	void Update(const WeatherInfo &weatherInfo) override;

	CStatistics m_temperatureStatistics;
	CStatistics m_humidityStatistics;
	CStatistics m_pressureStatistics;
};