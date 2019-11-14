#pragma once

#include "IShape.h"
#include <vector>

class CGroupShape : public IShape
{
public:
	CGroupShape(const std::vector<std::shared_ptr<IShape>>& shapes);

	size_t GetShapesCount() const;
	std::shared_ptr<IShape> GetShapeAtIndex(size_t index);
	const std::shared_ptr<IShape> GetShapeAtIndex(size_t index) const;

	RectD GetFrame() const override;
	void SetFrame(const RectD& frame) override;

	CLineStyle GetOutlineStyle() const override;
	void SetOutlineStyle(const CLineStyle& outlineStyle) override;

	CStyle GetFillStyle() const override;
	void SetFillStyle(const CStyle& fillStyle) override;

	CGroupShape* GetGroup() override;
	const CGroupShape* GetGroup() const override;

	void Draw(ICanvas& canvas) const override;

private:
	std::vector<std::shared_ptr<IShape>> m_shapes;

	RectD CreateFrame() const;

	static bool LessLeft(const std::shared_ptr<IShape>& first, const std::shared_ptr<IShape>& second);
	static bool LessTop(const std::shared_ptr<IShape>& first, const std::shared_ptr<IShape>& second);
	static bool LessRight(const std::shared_ptr<IShape>& first, const std::shared_ptr<IShape>& second);
	static bool LessBottom(const std::shared_ptr<IShape>& first, const std::shared_ptr<IShape>& second);
};