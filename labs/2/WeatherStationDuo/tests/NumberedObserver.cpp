#include "NumberedObserver.h"

CNumberedObserver::CNumberedObserver(std::ostream &strm, int number)
	: m_strm(strm)
	, m_number(number)
{
}

void CNumberedObserver::Update(const WeatherInfo &weatherInfo, const IObservable<WeatherInfo> &observable)
{
	if (m_inObservable == &observable)
	{
		m_strm << m_number << "in ";
	}
	if (m_outObservable == &observable)
	{
		m_strm << m_number << "out ";
	}
}