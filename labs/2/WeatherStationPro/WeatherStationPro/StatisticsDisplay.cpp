#include "pch.h"
#include "StatisticsDisplay.h"
#include <iostream>

using namespace std;

void CStatisticsDisplay::Update(double value, EventType eventType)
{
	switch (eventType)
	{
	case EventType::Temperature:
		m_temperatureStatistics.Update(value);
		cout << "Temperature statistics: " << m_temperatureStatistics.ToString() << endl;
		break;

	case EventType::Humidity:
		m_humidityStatistics.Update(value);
		cout << "Humidity statistics: " << m_humidityStatistics.ToString() << endl;
		break;

	case EventType::Pressure:
		m_pressureStatistics.Update(value);
		cout << "Pressure statistics: " << m_pressureStatistics.ToString() << endl;
		break;

	case EventType::WindSpeed:
		m_windSpeedStatistics.Update(value);
		cout << "Wind speed statistics: " << m_windSpeedStatistics.ToString() << endl;
		break;

	case EventType::WindDirection:
		m_windDirectionStatistics.Update(value);
		cout << "Wind direction statistics: " << m_windDirectionStatistics.ToString() << endl;
		break;
	}
}