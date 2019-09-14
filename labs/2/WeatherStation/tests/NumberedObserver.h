#pragma once

#include "../WeatherStation/Observer.h"
#include "../WeatherStation/WeatherInfo.h"
#include <iostream>

class CNumberedObserver : public CObserver<WeatherInfo>
{
public:
	CNumberedObserver(std::ostream &strm, int number);

private:
	void Update(const WeatherInfo &weatherInfo) override;

	std::ostream &m_strm;
	int m_number;
};

