#include "NumberedObserverIn.h"

CNumberedObserverIn::CNumberedObserverIn(std::ostream &strm, int number)
	: m_strm(strm)
	, m_number(number)
{
}

void CNumberedObserverIn::Update(const WeatherInfoIn &weatherInfo)
{
	m_strm << m_number << "in ";
}