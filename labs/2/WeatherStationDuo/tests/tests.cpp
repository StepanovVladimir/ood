#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"
#include "../WeatherStationDuo/WeatherData.h"
#include "RemovableObserver.h"
#include "NumberedObserver.h"
#include <sstream>

using namespace std;

TEST_CASE("An observer that in the Update method deletes itself tests")
{
	CWeatherData weatherData(ObservableType::In);
	CRemovableObserver observer;
	observer.RegisterOnObservable(weatherData, 0);

	CHECK_NOTHROW(weatherData.SetData({ 20, 45, 760 }));
}

TEST_CASE("Priority of the alert tests")
{
	ostringstream strm;

	CWeatherData weatherData(ObservableType::In);

	CNumberedObserver observer1(strm, 1);
	CNumberedObserver observer2(strm, 2);
	CNumberedObserver observer3(strm, 3);
	CNumberedObserver observer4(strm, 4);

	CHECK(observer1.RegisterOnObservable(weatherData, 1));
	CHECK(observer2.RegisterOnObservable(weatherData, 4));
	CHECK(observer3.RegisterOnObservable(weatherData, 2));
	CHECK(observer4.RegisterOnObservable(weatherData, 3));

	weatherData.SetData({ 20, 45, 760 });

	CHECK(strm.str() == "1in 3in 4in 2in ");
}

TEST_CASE("Attempt to register observers for the same priority tests")
{
	ostringstream strm;

	CWeatherData weatherData(ObservableType::In);

	CNumberedObserver observer1(strm, 1);
	CNumberedObserver observer2(strm, 2);

	CHECK(observer1.RegisterOnObservable(weatherData, 1));
	CHECK_FALSE(observer2.RegisterOnObservable(weatherData, 1));

	weatherData.SetData({ 20, 45, 760 });

	CHECK(strm.str() == "1in ");
}

TEST_CASE("Re-registration to another priority tests")
{
	stringstream strm;

	CWeatherData weatherData(ObservableType::In);

	CNumberedObserver observer1(strm, 1);
	CNumberedObserver observer2(strm, 2);

	observer1.RegisterOnObservable(weatherData, 1);
	observer2.RegisterOnObservable(weatherData, 2);

	CHECK(observer1.RegisterOnObservable(weatherData, 3));

	weatherData.SetData({ 20, 45, 760 });

	CHECK(strm.str() == "2in 1in ");
}

TEST_CASE("Two types of observables tests")
{
	stringstream strm;

	CWeatherData weatherDataIn(ObservableType::In);
	CWeatherData weatherDataOut(ObservableType::Out);

	CNumberedObserver observer(strm, 1);

	observer.RegisterOnObservable(weatherDataIn, 1);
	CHECK(observer.RegisterOnObservable(weatherDataOut, 1));

	weatherDataIn.SetData({ 20, 45, 760 });
	CHECK(strm.str() == "1in ");

	weatherDataOut.SetData({ 20, 45, 760 });
	CHECK(strm.str() == "1in 1out ");
}