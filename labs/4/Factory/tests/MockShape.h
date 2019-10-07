#pragma once

#include "../Factory/Shape.h"
#include <string>

class CMockShape : public CShape
{
public:
	CMockShape(const std::string& descr);

	void Draw(ICanvas& canvas) const override;

	const std::string& GetDescr() const;
private:
	std::string m_descr;
};