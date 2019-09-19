#pragma once

#include "WeatherObserverIn.h"
#include "Statistics.h"
#include "DirectionStatistics.h"

class CStatisticsDisplayIn : public CWeatherObserverIn
{
private:
	void Update(const WeatherInfoIn &weatherInfo) override;

	CStatistics m_temperatureStatistics;
	CStatistics m_humidityStatistics;
	CStatistics m_pressureStatistics;
};