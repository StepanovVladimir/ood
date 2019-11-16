#pragma once

#include "IShape.h"
#include <vector>

class CConstShapes
{
public:
	CConstShapes(const std::vector<std::shared_ptr<IShape>>& shapes);

	virtual ~CConstShapes() = default;

	size_t GetShapesCount() const;

	std::shared_ptr<IShape> operator[](size_t index);
	const std::shared_ptr<IShape> operator[](size_t index) const;

	std::vector<std::shared_ptr<IShape>>::iterator begin();
	std::vector<std::shared_ptr<IShape>>::const_iterator begin() const;

	std::vector<std::shared_ptr<IShape>>::iterator end();
	std::vector<std::shared_ptr<IShape>>::const_iterator end() const;

protected:
	std::vector<std::shared_ptr<IShape>> m_shapes;
};