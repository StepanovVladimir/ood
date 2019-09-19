#include "NumberedObserverOut.h"

CNumberedObserverOut::CNumberedObserverOut(std::ostream &strm, int number)
	: m_strm(strm)
	, m_number(number)
{
}

void CNumberedObserverOut::Update(const WeatherInfoOut &weatherInfo)
{
	m_strm << m_number << "out ";
}