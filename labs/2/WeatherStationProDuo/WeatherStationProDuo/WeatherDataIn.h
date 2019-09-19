#pragma once

#include "Observable.h"
#include "WeatherInfo.h"

class CWeatherDataIn : public CObservable<WeatherInfoIn>
{
public:
	WeatherInfoIn GetData() const override;
	void SetData(const WeatherInfoIn &weatherInfo);

	double GetTemperature() const;
	double GetHumidity() const;
	double GetPressure() const;

	void MeasurementsChanged() const;

private:
	WeatherInfoIn m_info;
};