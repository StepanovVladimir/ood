#include "pch.h"
#include "DirectionStatistics.h"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

CDirectionStatistics::CDirectionStatistics()
	: m_average(0)
	, m_sumX(0)
	, m_sumY(0)
{
}

void CDirectionStatistics::Update(double value)
{
	m_sumX += cos(value * M_PI / 180);
	m_sumY += sin(value * M_PI / 180);

	m_average = atan2(m_sumY, m_sumX) * 180 / M_PI;

	if (m_average < 0)
	{
		m_average += 360;
	}
}

string CDirectionStatistics::ToString() const
{
	return "average = " + to_string(m_average);
}