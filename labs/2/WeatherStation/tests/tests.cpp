#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"
#include "../WeatherStation/WeatherData.h"
#include "RemovableObserver.h"
#include "NumberedObserver.h"
#include <sstream>

using namespace std;

TEST_CASE("An observer that in the Update method deletes itself tests")
{
	CWeatherData weatherData;
	CRemovableObserver observer;
	observer.RegisterOnObservable(weatherData, 0);

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

	CHECK(observer1.RegisterOnObservable(weatherData, 1));
	CHECK(observer2.RegisterOnObservable(weatherData, 4));
	CHECK(observer3.RegisterOnObservable(weatherData, 2));
	CHECK(observer4.RegisterOnObservable(weatherData, 3));

	weatherData.SetData({ 20, 45, 760 });

	CHECK(strm.str() == "1342");
}

TEST_CASE("Attempt to register observers for the same priority tests")
{
	ostringstream strm;

	CWeatherData weatherData;

	CNumberedObserver observer1(strm, 1);
	CNumberedObserver observer2(strm, 2);

	CHECK(observer1.RegisterOnObservable(weatherData, 1));
	CHECK_FALSE(observer2.RegisterOnObservable(weatherData, 1));

	weatherData.SetData({ 20, 45, 760 });

	CHECK(strm.str() == "1");
}

TEST_CASE("Re-registration to another priority tests")
{
	stringstream strm;

	CWeatherData weatherData;

	CNumberedObserver observer1(strm, 1);
	CNumberedObserver observer2(strm, 2);

	observer1.RegisterOnObservable(weatherData, 1);
	observer2.RegisterOnObservable(weatherData, 2);

	CHECK(observer1.RegisterOnObservable(weatherData, 3));

	weatherData.SetData({ 20, 45, 760 });

	CHECK(strm.str() == "21");
}