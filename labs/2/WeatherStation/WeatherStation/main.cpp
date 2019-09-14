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
	display.RegisterOnObservable(weatherData, 0);

	CStatisticsDisplay statsDisplay;
	statsDisplay.RegisterOnObservable(weatherData, 1);

	weatherData.SetData({ 3, 70, 760 });
	weatherData.SetData({ 4, 80, 761 });
	cout << "----------------\n";

	statsDisplay.RemoveFromObservable();

	weatherData.SetData({ 10, 80, 761 });
	weatherData.SetData({ -10, 80, 761 });
	cout << "----------------\n";

	{
		CStatisticsDisplay statsDisplay;
		statsDisplay.RegisterOnObservable(weatherData, 1);

		weatherData.SetData({ 3, 70, 760 });
		weatherData.SetData({ 4, 80, 761 });
		cout << "----------------\n";
	}

	weatherData.SetData({ 10, 80, 761 });
	weatherData.SetData({ 10, 50, 759 });

	return 0;
}