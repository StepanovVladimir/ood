#include "pch.h"
#include "CurrentConditionDisplay.h"
#include <iostream>

using namespace std;

void CCurrentConditionDisplay::Update(const WeatherInfo &weatherInfo, const IObservable<WeatherInfo> &observable)
{
	if (m_inObservable == &observable)
	{
		cout << "Current condition indoors:\n";
	}
	if (m_outObservable == &observable)
	{
		cout << "Current condition without:\n";
	}

	cout << "  temperature: " << weatherInfo.temperature << endl;
	cout << "  humidity: " << weatherInfo.humidity << endl;
	cout << "  pressure: " << weatherInfo.pressure << endl;
}