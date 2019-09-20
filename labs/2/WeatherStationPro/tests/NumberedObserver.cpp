#include "NumberedObserver.h"

CNumberedObserver::CNumberedObserver(std::ostream &strm, int number)
	: m_strm(strm)
	, m_number(number)
{
}

void CNumberedObserver::Update(double value, EventType eventType)
{
	m_strm << m_number;
}