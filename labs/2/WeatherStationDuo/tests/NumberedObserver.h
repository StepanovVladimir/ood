#pragma once

#include "../WeatherStationDuo/Observer.h"
#include "../WeatherStationDuo/WeatherInfo.h"
#include <iostream>

class CNumberedObserver : public CObserver<WeatherInfo>
{
public:
	CNumberedObserver(std::ostream &strm, int number);

private:
	void Update(const WeatherInfo &weatherInfo, ObservableType observableType) override;

	std::ostream &m_strm;
	int m_number;
};

