#pragma once

#include "Observer.h"
#include "WeatherInfo.h"
#include "Statistics.h"

class CStatisticsDisplay : public CObserver<WeatherInfo>
{
private:
	void Update(const WeatherInfo &weatherInfo) override;

	CStatistics m_temperatureStatistics;
	CStatistics m_humidityStatistics;
	CStatistics m_pressureStatistics;
};