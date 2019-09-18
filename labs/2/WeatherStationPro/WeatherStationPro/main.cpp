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
	weatherData.RegisterObserver(display, 0);

	CStatisticsDisplay statsDisplay;
	weatherData.RegisterObserver(statsDisplay, 1);

	weatherData.SetData({ 3, 70, 760, 5, 0 });
	weatherData.SetData({ 4, 80, 761, 4, 270 });
	cout << "----------------\n";

	weatherData.RemoveObserver(statsDisplay);

	weatherData.SetData({ 10, 80, 761, 6, 180 });
	weatherData.SetData({ -10, 80, 761, 5, 100 });
	cout << "----------------\n";

	{
		CStatisticsDisplay statsDisplay;
		weatherData.RegisterObserver(statsDisplay, 1);

		weatherData.SetData({ 3, 70, 760, 3, 270 });
		weatherData.SetData({ 4, 80, 761, 4, 180 });
		cout << "----------------\n";
	}

	weatherData.SetData({ 10, 80, 761, 3, 200 });
	weatherData.SetData({ 10, 50, 759, 3, 150 });

	return 0;
}