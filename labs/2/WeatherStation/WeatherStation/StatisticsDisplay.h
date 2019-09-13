#pragma once

#include "IObserver.h"
#include "IObservable.h"
#include "WeatherInfo.h"
#include "Statistics.h"

class CStatisticsDisplay : public IObserver<WeatherInfo>
{
public:
	CStatisticsDisplay(IObservable<WeatherInfo> &observable);
	~CStatisticsDisplay();

private:
	void Update(const WeatherInfo &weatherCondition) override;

	IObservable<WeatherInfo> &m_observable;
	
	CStatistics m_temperatureStatistics;
	CStatistics m_humidityStatistics;
	CStatistics m_pressureStatistics;
};