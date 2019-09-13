#include "pch.h"
#include "StatisticsDisplay.h"
#include <iostream>

using namespace std;

CStatisticsDisplay::CStatisticsDisplay(IObservable<WeatherInfo> &observable)
	: m_observable(observable)
{
	m_observable.RegisterObserver(*this);
}

CStatisticsDisplay::~CStatisticsDisplay()
{
	m_observable.RemoveObserver(*this);
}

void CStatisticsDisplay::Update(const WeatherInfo &weatherCondition)
{
	m_temperatureStatistics.Update(weatherCondition.temperature);
	m_humidityStatistics.Update(weatherCondition.humidity);
	m_pressureStatistics.Update(weatherCondition.pressure);

	cout << "Statistics:\n";
	cout << "  temperature: " << m_temperatureStatistics.ToString() << endl;
	cout << "  humidity: " << m_humidityStatistics.ToString() << endl;
	cout << "  pressure: " << m_pressureStatistics.ToString() << endl;
}