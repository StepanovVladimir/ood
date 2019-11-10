#include "pch.h"
#include "Shapes.h"

using namespace std;

size_t CShapes::GetShapesCount() const
{
	return m_shapes.size();
}

shared_ptr<IShape> CShapes::GetShapeAtIndex(size_t index)
{
	if (index >= m_shapes.size())
	{
		throw runtime_error("There is no shape with such index");
	}
	return m_shapes[index];
}

const std::shared_ptr<IShape> CShapes::GetShapeAtIndex(size_t index) const
{
	if (index >= m_shapes.size())
	{
		throw runtime_error("There is no shape with such index");
	}
	return m_shapes[index];
}

void CShapes::InsertShape(const shared_ptr<IShape>& shape, size_t position = numeric_limits<size_t>::max())
{
	if (position > m_shapes.size())
	{
		m_shapes.push_back(shape);
	}
	else
	{
		m_shapes.insert(m_shapes.begin() + position, shape);
	}
}

void CShapes::RemoveShapeAtIndex(size_t index)
{
	if (index >= m_shapes.size())
	{
		throw runtime_error("There is no shape with such index");
	}
	m_shapes.erase(m_shapes.begin() + index);
}