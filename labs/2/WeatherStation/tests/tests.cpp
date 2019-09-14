#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"
#include "../WeatherStation/WeatherData.h"
#include "../WeatherStation/CurrentConditionDisplay.h"
#include "../WeatherStation/StatisticsDisplay.h"
#include "../WeatherStation/RemovableObserver.h"

TEST_CASE("An observer that in the Update method deletes itself tests")
{
	CWeatherData weatherData;
	CRemovableObserver removableObserver(weatherData);
	CHECK_NOTHROW(weatherData.SetData({ 20, 45, 760 }));
}