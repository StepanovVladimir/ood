#pragma once

#include "Observable.h"
#include "WeatherInfo.h"

class CWeatherDataOut : public CObservable<WeatherInfoOut>
{
public:
	WeatherInfoOut GetData() const override;
	void SetData(const WeatherInfoOut &weatherInfo);

	double GetTemperature() const;
	double GetHumidity() const;
	double GetPressure() const;
	double GetWindSpeed() const;
	double GetWindDirection() const;

	void MeasurementsChanged() const;

private:
	WeatherInfoOut m_info;
};