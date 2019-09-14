#include "pch.h"
#include "WeatherData.h"
#include "CurrentConditionDisplay.h"
#include "StatisticsDisplay.h"
#include <iostream>

using namespace std;

int main()
{
	CWeatherData wd;

	CCurrentConditionDisplay display(wd);

	CStatisticsDisplay statsDisplay;
	statsDisplay.RegisterOnObservable(wd);

	wd.SetData({ 3, 0.7, 760 });
	wd.SetData({ 4, 0.8, 761 });
	cout << "----------------\n";

	statsDisplay.RemoveFromObservable();

	wd.SetData({ 10, 0.8, 761 });
	wd.SetData({ -10, 0.8, 761 });
	cout << "----------------\n";

	{
		CStatisticsDisplay sd(wd);
		wd.SetData({ 3, 0.7, 760 });
		wd.SetData({ 4, 0.8, 761 });
		cout << "----------------\n";
	}

	wd.SetData({ 10, 0.8, 761 });
	wd.SetData({ 10, 0.5, 759 });

	return 0;
}