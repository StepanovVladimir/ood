#include "NumberedObserver.h"

CNumberedObserver::CNumberedObserver(std::ostream &strm, int number)
	: m_strm(strm)
	, m_number(number)
{
}

void CNumberedObserver::Update(const WeatherInfo &weatherInfo, ObservableType observableType)
{
	if (observableType == ObservableType::In)
	{
		m_strm << m_number << "in ";
	}
	else
	{
		m_strm << m_number << "out ";
	}
}