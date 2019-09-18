#include "pch.h"
#include "StatisticsDisplay.h"
#include <iostream>

using namespace std;

void CStatisticsDisplay::Update(const WeatherInfo &weatherInfo, const IObservable<WeatherInfo> &observable)
{
	if (m_inObservable == &observable)
	{
		cout << "Statistics indoors:\n";
		UpdateStatistics(weatherInfo,
			m_inTemperatureStatistics, m_inHumidityStatistics, m_inPressureStatistics);
	}
	if (m_outObservable == &observable)
	{
		cout << "Statistics without:\n";
		UpdateStatistics(weatherInfo,
			m_outTemperatureStatistics, m_outHumidityStatistics, m_outPressureStatistics);
	}
}

void CStatisticsDisplay::UpdateStatistics(const WeatherInfo &weatherInfo,
	CStatistics &temperature, CStatistics &humidity, CStatistics &pressure)
{
	temperature.Update(weatherInfo.temperature);
	humidity.Update(weatherInfo.humidity);
	pressure.Update(weatherInfo.pressure);

	cout << "  temperature: " << temperature.ToString() << endl;
	cout << "  humidity: " << humidity.ToString() << endl;
	cout << "  pressure: " << pressure.ToString() << endl;
}