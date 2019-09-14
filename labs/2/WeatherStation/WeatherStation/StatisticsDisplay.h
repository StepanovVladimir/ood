#pragma once

#include "Observer.h"
#include "WeatherInfo.h"
#include "Statistics.h"

class CStatisticsDisplay : public CObserver<WeatherInfo>
{
public:
	CStatisticsDisplay() = default;
	CStatisticsDisplay(IObservable<WeatherInfo> &observable);

private:
	void Update(const WeatherInfo &weatherCondition) override;

	CStatistics m_temperatureStatistics;
	CStatistics m_humidityStatistics;
	CStatistics m_pressureStatistics;
};