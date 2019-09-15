#pragma once

#include "Observable.h"
#include "WeatherInfo.h"

class CWeatherData : public CObservable<WeatherInfo>
{
public:
	WeatherInfo GetData() const override;
	void SetData(const WeatherInfo &weatherInfo);

	double GetTemperature() const;
	double GetHumidity() const;
	double GetPressure() const;

	void MeasurementsChanged() const;

private:
	WeatherInfo m_info;
};