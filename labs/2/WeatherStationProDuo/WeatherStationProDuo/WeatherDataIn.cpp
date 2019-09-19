#include "pch.h"
#include "WeatherDataIn.h"

WeatherInfoIn CWeatherDataIn::GetData() const
{
	return m_info;
}

void CWeatherDataIn::SetData(const WeatherInfoIn &info)
{
	m_info = info;

	MeasurementsChanged();
}

double CWeatherDataIn::GetTemperature() const
{
	return m_info.temperature;
}

double CWeatherDataIn::GetHumidity() const
{
	return m_info.humidity;
}

double CWeatherDataIn::GetPressure() const
{
	return m_info.pressure;
}

void CWeatherDataIn::MeasurementsChanged() const
{
	NotifyObservers();
}