#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"
#include "../WeatherStationProDuo/WeatherDataIn.h"
#include "../WeatherStationProDuo/WeatherDataOut.h"
#include "NumberedObserverIn.h"
#include "NumberedObserverOut.h"
#include <sstream>

using namespace std;

TEST_CASE("Priority of the alert tests")
{
	ostringstream strm;

	CWeatherDataIn weatherData;

	CNumberedObserverIn observer1(strm, 1);
	CNumberedObserverIn observer2(strm, 2);
	CNumberedObserverIn observer3(strm, 3);
	CNumberedObserverIn observer4(strm, 4);

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

	CWeatherDataIn weatherData;

	CNumberedObserverIn observer1(strm, 1);
	CNumberedObserverIn observer2(strm, 2);

	weatherData.RegisterObserver(observer1, 1);
	CHECK(weatherData.RegisterObserver(observer2, 1));

	weatherData.SetData({ 20, 45, 760 });

	CHECK(strm.str() == "1in 2in ");
}

TEST_CASE("Two observables tests")
{
	stringstream strm;

	CWeatherDataIn weatherDataIn;
	CWeatherDataOut weatherDataOut;

	CNumberedObserverIn observerIn(strm, 1);
	CNumberedObserverOut observerOut(strm, 1);

	weatherDataIn.RegisterObserver(observerIn, 1);
	weatherDataOut.RegisterObserver(observerOut, 1);

	weatherDataIn.SetData({ 20, 45, 760 });
	CHECK(strm.str() == "1in ");

	weatherDataOut.SetData({ 20, 45, 760 });
	CHECK(strm.str() == "1in 1out ");
}