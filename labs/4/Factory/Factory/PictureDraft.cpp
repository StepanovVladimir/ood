#include "pch.h"
#include "PictureDraft.h"

bool CPictureDraft::IsEmpty() const
{
	return m_shapes.empty();
}

size_t CPictureDraft::GetShapesCount() const
{
	return m_shapes.size();
}

const CShape& CPictureDraft::GetShapeAt(size_t index) const
{
	return *(m_shapes[index]);
}

void CPictureDraft::AddShape(std::unique_ptr<CShape>&& shape)
{
	m_shapes.push_back(move(shape));
}