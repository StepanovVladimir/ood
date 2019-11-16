#pragma once

#include "IShape.h"
#include "ConstShapes.h"
#include <vector>

class CGroupShape : public IShape
{
public:
	CGroupShape(const std::vector<std::shared_ptr<IShape>>& shapes);

	CConstShapes& GetShapes();

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
	CConstShapes m_shapes;

	RectD CreateFrame() const;

	static bool LessLeft(const std::shared_ptr<IShape>& first, const std::shared_ptr<IShape>& second);
	static bool LessTop(const std::shared_ptr<IShape>& first, const std::shared_ptr<IShape>& second);
	static bool LessRight(const std::shared_ptr<IShape>& first, const std::shared_ptr<IShape>& second);
	static bool LessBottom(const std::shared_ptr<IShape>& first, const std::shared_ptr<IShape>& second);
};