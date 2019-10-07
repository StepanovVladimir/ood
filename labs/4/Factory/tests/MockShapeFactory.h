#pragma once

#include "../Factory/IShapeFactory.h"

class CMockShapeFactory : public IShapeFactory
{
public:
	std::unique_ptr<CShape> CreateShape(const std::string& description) const override;
};