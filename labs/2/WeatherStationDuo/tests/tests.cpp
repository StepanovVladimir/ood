#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"
#include "../WeatherStationDuo/WeatherData.h"
#include "RemovableObserver.h"
#include "NumberedObserver.h"
#include <sstream>

using namespace std;

TEST_CASE("An observer that in the Update method deletes itself tests")
{
	CWeatherData weatherData;
	CRemovableObserver observer;
	weatherData.RegisterObserver(observer, 0);

	CHECK_NOTHROW(weatherData.SetData({ 20, 45, 760 }));
}

TEST_CASE("Priority of the alert tests")
{
	ostringstream strm;

	CWeatherData weatherData;

	CNumberedObserver observer1(strm, 1);
	CNumberedObserver observer2(strm, 2);
	CNumberedObserver observer3(strm, 3);
	CNumberedObserver observer4(strm, 4);

	CHECK(weatherData.RegisterObserver(observer1, 1));
	CHECK(weatherData.RegisterObserver(observer2, 4));
	CHECK(weatherData.RegisterObserver(observer3, 2));
	CHECK(weatherData.RegisterObserver(observer4, 3));

	weatherData.SetData({ 20, 45, 760 });

	CHECK(strm.str() == "1in 3in 4in 2in ");
}

TEST_CASE("Register observers for the same priority tests")
{
	ostringstream strm;

	CWeatherData weatherData;

	CNumberedObserver observer1(strm, 1);
	CNumberedObserver observer2(strm, 2);

	weatherData.RegisterObserver(observer1, 1);
	CHECK(weatherData.RegisterObserver(observer2, 1));

	weatherData.SetData({ 20, 45, 760 });

	CHECK(strm.str() == "1in 2in ");
}

TEST_CASE("Two observables tests")
{
	stringstream strm;

	CWeatherData weatherData1;
	CWeatherData weatherData2;

	CNumberedObserver observer(strm, 1);

	weatherData1.RegisterObserver(observer, 1);
	CHECK(weatherData2.RegisterObserver(observer, 1));

	weatherData1.SetData({ 20, 45, 760 });
	CHECK(strm.str() == "1in ");

	weatherData2.SetData({ 20, 45, 760 });
	CHECK(strm.str() == "1in 1out ");
}