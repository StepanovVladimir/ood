#pragma once

#include "../WeatherStationDuo/Observer.h"
#include "../WeatherStationDuo/WeatherInfo.h"

class CRemovableObserver : public CObserver<WeatherInfo>
{
private:
	void Update(const WeatherInfo &weatherInfo, ObservableType observableType) override;
};