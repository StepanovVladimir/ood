#pragma once

#include "IShape.h"
#include <vector>

class CShapes
{
public:
	size_t GetShapesCount() const;

	std::shared_ptr<IShape> GetShapeAtIndex(size_t index);
	const std::shared_ptr<IShape> GetShapeAtIndex(size_t index) const;

	std::vector<std::shared_ptr<IShape>>::iterator begin();
	std::vector<std::shared_ptr<IShape>>::const_iterator begin() const;

	std::vector<std::shared_ptr<IShape>>::iterator end();
	std::vector<std::shared_ptr<IShape>>::const_iterator end() const;

	void InsertShape(const std::shared_ptr<IShape>& shape, size_t position = std::numeric_limits<size_t>::max());
	void RemoveShapeAtIndex(size_t index);

private:
	std::vector<std::shared_ptr<IShape>> m_shapes;
};