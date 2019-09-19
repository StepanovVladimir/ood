#include "pch.h"
#include "WeatherData.h"

CWeatherData::~CWeatherData()
{
	auto observers = m_temperatureObservers;
	for (auto &observer : observers)
	{
		observer.second->RemoveFromEvent(EventType::Temperature);
	}

	observers = m_humidityObservers;
	for (auto &observer : observers)
	{
		observer.second->RemoveFromEvent(EventType::Humidity);
	}

	observers = m_pressureObservers;
	for (auto &observer : observers)
	{
		observer.second->RemoveFromEvent(EventType::Pressure);
	}

	observers = m_windSpeedObservers;
	for (auto &observer : observers)
	{
		observer.second->RemoveFromEvent(EventType::WindSpeed);
	}

	observers = m_windDirectionObservers;
	for (auto &observer : observers)
	{
		observer.second->RemoveFromEvent(EventType::WindDirection);
	}
}

bool CWeatherData::RegisterObserver(IObserver<WeatherInfo> &observer, size_t priority, EventType eventType)
{
	if (observer.RegisterOnEvent(*this, eventType))
	{
		switch (eventType)
		{
		case EventType::Temperature:
			m_temperatureObservers.emplace(priority, &observer);
			break;

		case EventType::Humidity:
			m_humidityObservers.emplace(priority, &observer);
			break;

		case EventType::Pressure:
			m_pressureObservers.emplace(priority, &observer);
			break;

		case EventType::WindSpeed:
			m_windSpeedObservers.emplace(priority, &observer);
			break;

		case EventType::WindDirection:
			m_windDirectionObservers.emplace(priority, &observer);
			break;
		}
		return true;
	}
	return false;
}

void CWeatherData::RemoveFromEvent(IObserver<WeatherInfo> &observer, EventType eventType)
{
	switch (eventType)
	{
	case EventType::Temperature:
		RemoveFromEvent(m_temperatureObservers, observer, eventType);
		break;

	case EventType::Humidity:
		RemoveFromEvent(m_humidityObservers, observer, eventType);
		break;

	case EventType::Pressure:
		RemoveFromEvent(m_pressureObservers, observer, eventType);
		break;

	case EventType::WindSpeed:
		RemoveFromEvent(m_windSpeedObservers, observer, eventType);
		break;

	case EventType::WindDirection:
		RemoveFromEvent(m_windDirectionObservers, observer, eventType);
		break;
	}
}

void CWeatherData::RemoveObserver(IObserver<WeatherInfo> &observer)
{
	RemoveFromEvent(m_temperatureObservers, observer, EventType::Temperature);
	RemoveFromEvent(m_humidityObservers, observer, EventType::Humidity);
	RemoveFromEvent(m_pressureObservers, observer, EventType::Pressure);
	RemoveFromEvent(m_windSpeedObservers, observer, EventType::WindSpeed);
	RemoveFromEvent(m_windDirectionObservers, observer, EventType::WindDirection);
}

void CWeatherData::NotifyObservers(EventType eventType) const
{
	switch (eventType)
	{
	case EventType::Temperature:
		UpdateObservers(m_temperatureObservers, GetTemperature(), eventType);
		break;

	case EventType::Humidity:
		UpdateObservers(m_humidityObservers, GetHumidity(), eventType);
		break;

	case EventType::Pressure:
		UpdateObservers(m_pressureObservers, GetPressure(), eventType);
		break;

	case EventType::WindSpeed:
		UpdateObservers(m_windSpeedObservers, GetWindSpeed(), eventType);
		break;

	case EventType::WindDirection:
		UpdateObservers(m_windDirectionObservers, GetWindDirection(), eventType);
		break;
	}
}

WeatherInfo CWeatherData::GetData() const
{
	return m_info;
}

void CWeatherData::SetData(const WeatherInfo &info)
{
	if (m_info.temperature != info.temperature)
	{
		m_info.temperature = info.temperature;
		NotifyObservers(EventType::Temperature);
	}
	if (m_info.humidity != info.humidity)
	{
		m_info.humidity = info.humidity;
		NotifyObservers(EventType::Humidity);
	}
	if (m_info.pressure != info.pressure)
	{
		m_info.pressure = info.pressure;
		NotifyObservers(EventType::Pressure);
	}
	if (m_info.windSpeed != info.windSpeed)
	{
		m_info.windSpeed = info.windSpeed;
		NotifyObservers(EventType::WindSpeed);
	}
	if (m_info.windDirection != info.windDirection)
	{
		m_info.windDirection = info.windDirection;
		NotifyObservers(EventType::WindDirection);
	}
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

void CWeatherData::RemoveFromEvent(Observers &observers, IObserver<WeatherInfo> &observer, EventType eventType)
{
	for (auto iter = observers.begin(); iter != observers.end(); iter++)
	{
		if (iter->second == &observer)
		{
			iter->second->RemoveFromEvent(eventType);
			observers.erase(iter);
			break;
		}
	}
}

void CWeatherData::UpdateObservers(const Observers &observers, double value, EventType eventType) const
{
	auto tmpObservers = observers;
	for (auto &observer : tmpObservers)
	{
		observer.second->Update(value, eventType);
	}
}