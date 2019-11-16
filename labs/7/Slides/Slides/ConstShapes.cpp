#include "pch.h"
#include "ConstShapes.h"

using namespace std;

CConstShapes::CConstShapes(const vector<shared_ptr<IShape>>& shapes)
	: m_shapes(shapes)
{
}

size_t CConstShapes::GetShapesCount() const
{
	return m_shapes.size();
}

shared_ptr<IShape> CConstShapes::operator[](size_t index)
{
	if (index >= m_shapes.size())
	{
		throw runtime_error("There is no shape with such index");
	}
	return m_shapes[index];
}

const std::shared_ptr<IShape> CConstShapes::operator[](size_t index) const
{
	if (index >= m_shapes.size())
	{
		throw runtime_error("There is no shape with such index");
	}
	return m_shapes[index];
}

vector<shared_ptr<IShape>>::iterator CConstShapes::begin()
{
	return m_shapes.begin();
}

vector<shared_ptr<IShape>>::const_iterator CConstShapes::begin() const
{
	return m_shapes.begin();
}

vector<shared_ptr<IShape>>::iterator CConstShapes::end()
{
	return m_shapes.end();
}

vector<shared_ptr<IShape>>::const_iterator CConstShapes::end() const
{
	return m_shapes.end();
}