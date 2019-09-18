#pragma once

#include "WeatherObserver.h"
#include "Statistics.h"

class CStatisticsDisplay : public CWeatherObserver
{
private:
	void Update(const WeatherInfo &weatherInfo, const IObservable<WeatherInfo> &observable) override;

	CStatistics m_inTemperatureStatistics;
	CStatistics m_inHumidityStatistics;
	CStatistics m_inPressureStatistics;

	CStatistics m_outTemperatureStatistics;
	CStatistics m_outHumidityStatistics;
	CStatistics m_outPressureStatistics;

	void UpdateStatistics(const WeatherInfo &weatherInfo,
		CStatistics &temperature, CStatistics &humidity, CStatistics &pressure);
};