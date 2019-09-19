#pragma once

#include "WeatherObserverOut.h"
#include "Statistics.h"
#include "DirectionStatistics.h"

class CStatisticsDisplayOut : public CWeatherObserverOut
{
private:
	void Update(const WeatherInfoOut &weatherInfo) override;

	CStatistics m_temperatureStatistics;
	CStatistics m_humidityStatistics;
	CStatistics m_pressureStatistics;
	CStatistics m_windSpeedStatistics;
	CDirectionStatistics m_windDirectionStatistics;
};