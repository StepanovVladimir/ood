#include "pch.h"
#include "WeatherData.h"
#include "CurrentConditionDisplay.h"
#include "StatisticsDisplay.h"
#include <iostream>

int main()
{
	CWeatherData wd;

	CCurrentConditionDisplay display(wd);

	CStatisticsDisplay statsDisplay;
	statsDisplay.RegisterOnObservable(wd);

	wd.SetData({ 3, 0.7, 760 });
	wd.SetData({ 4, 0.8, 761 });

	statsDisplay.RemoveFromObservable();

	wd.SetData({ 10, 0.8, 761 });
	wd.SetData({ -10, 0.8, 761 });

	{
		CStatisticsDisplay sd(wd);
		wd.SetData({ 3, 0.7, 760 });
		wd.SetData({ 4, 0.8, 761 });
	}

	wd.SetData({ 10, 0.8, 761 });

	return 0;
}