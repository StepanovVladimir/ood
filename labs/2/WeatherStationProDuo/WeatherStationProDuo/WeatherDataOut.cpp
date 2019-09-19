#include "pch.h"
#include "WeatherDataOut.h"

WeatherInfoOut CWeatherDataOut::GetData() const
{
	return m_info;
}

void CWeatherDataOut::SetData(const WeatherInfoOut &info)
{
	m_info = info;

	MeasurementsChanged();
}

double CWeatherDataOut::GetTemperature() const
{
	return m_info.temperature;
}

double CWeatherDataOut::GetHumidity() const
{
	return m_info.humidity;
}

double CWeatherDataOut::GetPressure() const
{
	return m_info.pressure;
}

double CWeatherDataOut::GetWindSpeed() const
{
	return m_info.windSpeed;
}

double CWeatherDataOut::GetWindDirection() const
{
	return m_info.windDirection;
}

void CWeatherDataOut::MeasurementsChanged() const
{
	NotifyObservers();
}