#pragma once

#include "Observer.h"
#include "WeatherInfo.h"
#include "Statistics.h"

class CStatisticsDisplay : public CObserver<WeatherInfo>
{
private:
	void Update(const WeatherInfo &weatherInfo, ObservableType observableType) override;

	CStatistics m_inTemperatureStatistics;
	CStatistics m_inHumidityStatistics;
	CStatistics m_inPressureStatistics;

	CStatistics m_outTemperatureStatistics;
	CStatistics m_outHumidityStatistics;
	CStatistics m_outPressureStatistics;

	void UpdateStatistics(const WeatherInfo &weatherInfo,
		CStatistics &temperature, CStatistics &humidity, CStatistics &pressure);
};