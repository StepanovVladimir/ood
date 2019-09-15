#pragma once

#include "Observer.h"
#include "WeatherInfo.h"
#include "Statistics.h"
#include "DirectionStatistics.h"

class CStatisticsDisplay : public CObserver<WeatherInfo>
{
private:
	void Update(const WeatherInfo &weatherInfo) override;

	CStatistics m_temperatureStatistics;
	CStatistics m_humidityStatistics;
	CStatistics m_pressureStatistics;
	CStatistics m_windSpeedStatistics;
	CDirectionStatistics m_windDirectionStatistics;
};