#pragma once

#include "Observable.h"
#include "WeatherInfo.h"
#include <set>

class CWeatherData : public CObservable<WeatherInfo>
{
public:
	WeatherInfo GetData() const override;

	double GetTemperature() const;
	double GetHumidity() const;
	double GetPressure() const;

	void MeasurementsChanged() const;
	void SetMeasurements(const WeatherInfo &weatherInfo);

private:
	WeatherInfo m_info;
};