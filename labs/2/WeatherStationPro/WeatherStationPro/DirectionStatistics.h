#pragma once

#include <string>

class CDirectionStatistics
{
public:
	CDirectionStatistics();

	void Update(double value);

	std::string ToString() const;

private:
	double m_average;
	double m_sumX;
	double m_sumY;
};

