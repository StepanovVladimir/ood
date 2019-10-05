#pragma once

#include "Shape.h"
#include <memory>
#include <string>

struct IShapeFactory
{
public:
	virtual ~IShapeFactory() = default;

	virtual std::unique_ptr<CShape> CreateShape(const std::string& description) const = 0;
};