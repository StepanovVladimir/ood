#pragma once

#include "Shape.h"
#include <memory>
#include <vector>

class CPictureDraft
{
public:
	CPictureDraft() = default;
	CPictureDraft(const CPictureDraft&) = delete;
	CPictureDraft(CPictureDraft&&) = default;
	
	CPictureDraft& operator=(const CPictureDraft&) = delete;
	CPictureDraft& operator=(CPictureDraft&&) = default;

	const CShape& operator[](size_t index) const;

	bool IsEmpty() const;
	size_t GetShapesCount() const;
	void AddShape(std::unique_ptr<CShape>&& shape);

private:
	std::vector<std::unique_ptr<CShape>> m_shapes;
};