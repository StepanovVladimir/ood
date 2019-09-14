#include "pch.h"
#include "StatisticsDisplay.h"
#include <iostream>

using namespace std;

void CStatisticsDisplay::Update(const WeatherInfo &weatherInfo)
{
	m_temperatureStatistics.Update(weatherInfo.temperature);
	m_humidityStatistics.Update(weatherInfo.humidity);
	m_pressureStatistics.Update(weatherInfo.pressure);

	cout << "Statistics:\n";
	cout << "  temperature: " << m_temperatureStatistics.ToString() << endl;
	cout << "  humidity: " << m_humidityStatistics.ToString() << endl;
	cout << "  pressure: " << m_pressureStatistics.ToString() << endl;
}