#include "pch.h"
#include "Statistics.h"

using namespace std;

CStatistics::CStatistics()
	: m_min(numeric_limits<double>::infinity())
	, m_max(-numeric_limits<double>::infinity())
	, m_average(0)
	, m_sum(0)
	, m_count(0)
{
}

void CStatistics::Update(double value)
{
	if (m_min > value)
	{
		m_min = value;
	}
	if (m_max < value)
	{
		m_max = value;
	}
	m_sum += value;
	m_count++;
	m_average = m_sum / m_count;
}

string CStatistics::ToString()
{
	return "min = " + to_string(m_min) + "; max = " + to_string(m_max) + "; average = " + to_string(m_average);
}