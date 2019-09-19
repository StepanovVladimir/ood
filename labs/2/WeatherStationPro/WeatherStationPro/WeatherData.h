#pragma once

#include "IObservable.h"
#include "WeatherInfo.h"
#include <map>

class CWeatherData : public IObservable<WeatherInfo>
{
public:
	~CWeatherData();

	bool RegisterObserver(IObserver<WeatherInfo> &observer, size_t priority, EventType eventType) override;
	void RemoveFromEvent(IObserver<WeatherInfo> &observer, EventType eventType) override;
	void RemoveObserver(IObserver<WeatherInfo> &observer) override;

	void NotifyObservers(EventType eventType) const override;

	WeatherInfo GetData() const;
	void SetData(const WeatherInfo &weatherInfo);

	double GetTemperature() const;
	double GetHumidity() const;
	double GetPressure() const;
	double GetWindSpeed() const;
	double GetWindDirection() const;

private:
	using Observers = std::multimap<size_t, IObserver<WeatherInfo>*>;

	Observers m_temperatureObservers;
	Observers m_humidityObservers;
	Observers m_pressureObservers;
	Observers m_windSpeedObservers;
	Observers m_windDirectionObservers;

	WeatherInfo m_info;

	void RemoveFromEvent(Observers &observers, IObserver<WeatherInfo> &observer, EventType eventType);
	void UpdateObservers(const Observers &observers, double value, EventType eventType) const;
};