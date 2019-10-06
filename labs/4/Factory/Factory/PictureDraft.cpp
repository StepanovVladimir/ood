#include "pch.h"
#include "PictureDraft.h"

const CShape& CPictureDraft::operator[](size_t index) const
{
	if (index >= m_shapes.size())
	{
		throw std::runtime_error("There is no shape with this index");
	}
	return *(m_shapes[index]);
}

bool CPictureDraft::IsEmpty() const
{
	return m_shapes.empty();
}

size_t CPictureDraft::GetShapesCount() const
{
	return m_shapes.size();
}
void CPictureDraft::AddShape(std::unique_ptr<CShape>&& shape)
{
	m_shapes.push_back(move(shape));
}