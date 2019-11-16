#include "pch.h"
#include "Shapes.h"

using namespace std;

CShapes::CShapes()
	: CConstShapes(vector<shared_ptr<IShape>>())
{
}

CShapes::CShapes(const vector<shared_ptr<IShape>>& shapes)
	: CConstShapes(shapes)
{
}

void CShapes::InsertShape(const shared_ptr<IShape>& shape, size_t position)
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