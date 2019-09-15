#pragma once

#include <string>

class CStatistics
{
public:
	CStatistics();

	void Update(double value);

	std::string ToString() const;

private:
	double m_min;
	double m_max;
	double m_average;
	double m_sum;
	size_t m_count;
};