#pragma once

#include "ConstShapes.h"

class CShapes : public CConstShapes
{
public:
	CShapes();
	CShapes(const std::vector<std::shared_ptr<IShape>>& shapes);

	void InsertShape(const std::shared_ptr<IShape>& shape, size_t position = std::numeric_limits<size_t>::max());
	void RemoveShapeAtIndex(size_t index);
};