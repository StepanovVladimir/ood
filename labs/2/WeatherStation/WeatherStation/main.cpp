#include "pch.h"
#include "WeatherData.h"
#include "CurrentConditionDisplay.h"
#include "StatisticsDisplay.h"
#include <iostream>

using namespace std;

int main()
{
	CWeatherData weatherData;

	CCurrentConditionDisplay display;
	weatherData.RegisterObserver(display, 1);

	CStatisticsDisplay statsDisplay;
	weatherData.RegisterObserver(statsDisplay, 2);

	weatherData.SetData({ 3, 70, 760 });
	weatherData.SetData({ 4, 80, 761 });
	cout << "----------------\n";

	weatherData.RemoveObserver(statsDisplay);

	weatherData.SetData({ 10, 80, 761 });
	weatherData.SetData({ -10, 80, 761 });
	cout << "----------------\n";

	{
		CStatisticsDisplay statsDisplay;
		weatherData.RegisterObserver(statsDisplay, 2);

		weatherData.SetData({ 3, 70, 760 });
		weatherData.SetData({ 4, 80, 761 });
		cout << "----------------\n";
	}

	weatherData.SetData({ 10, 80, 761 });
	weatherData.SetData({ 10, 50, 759 });

	return 0;
}