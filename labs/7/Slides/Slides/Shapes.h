#pragma once

#include "IShape.h"
#include <memory>

class CShapes
{
public:
	virtual ~CShapes() = default;

	size_t GetShapesCount() const;
	std::unique_ptr<IShape> GetShapeAtIndex(size_t index);
	void InsertShape(std::unique_ptr<IShape>&& shape, size_t position = std::numeric_limits<size_t>::max());
	void RemoveShapeAtIndex(size_t index);
};