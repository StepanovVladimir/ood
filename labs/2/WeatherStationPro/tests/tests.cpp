#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"
#include "../WeatherStationPro/WeatherData.h"
#include "NumberedObserver.h"
#include <sstream>

using namespace std;

TEST_CASE("Priority of the alert tests")
{
	ostringstream strm;

	CWeatherData weatherData;

	CNumberedObserver observer1(strm, 1);
	CNumberedObserver observer2(strm, 2);
	CNumberedObserver observer3(strm, 3);
	CNumberedObserver observer4(strm, 4);

	CHECK(weatherData.RegisterObserver(observer1, 1, EventType::Temperature));
	CHECK(weatherData.RegisterObserver(observer2, 4, EventType::Temperature));
	CHECK(weatherData.RegisterObserver(observer3, 2, EventType::Temperature));
	CHECK(weatherData.RegisterObserver(observer4, 3, EventType::Temperature));

	weatherData.SetData({ 20, 45, 760, 3, 30 });

	CHECK(strm.str() == "1342");
}

TEST_CASE("Register observers for the same priority tests")
{
	ostringstream strm;

	CWeatherData weatherData;

	CNumberedObserver observer1(strm, 1);
	CNumberedObserver observer2(strm, 2);

	weatherData.RegisterObserver(observer1, 1, EventType::Temperature);
	CHECK(weatherData.RegisterObserver(observer2, 1, EventType::Temperature));

	weatherData.SetData({ 20, 45, 760 });

	CHECK(strm.str() == "12");
}