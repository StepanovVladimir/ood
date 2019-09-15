#include "pch.h"
#include "WeatherData.h"

WeatherInfo CWeatherData::GetData() const
{
	return m_info;
}

void CWeatherData::SetData(const WeatherInfo &info)
{
	m_info = info;

	MeasurementsChanged();
}

double CWeatherData::GetTemperature() const
{
	return m_info.temperature;
}

double CWeatherData::GetHumidity() const
{
	return m_info.humidity;
}

double CWeatherData::GetPressure() const
{
	return m_info.pressure;
}

double CWeatherData::GetWindSpeed() const
{
	return m_info.windSpeed;
}

double CWeatherData::GetWindDirection() const
{
	return m_info.windDirection;
}

void CWeatherData::MeasurementsChanged() const
{
	NotifyObservers();
}