#include "pch.h"
#include "GroupShape.h"
#include <algorithm>

using namespace std;

optional<RectD> CGroupShape::GetFrame() const
{
	if (GetShapesCount() == 0)
	{
		return nullopt;
	}

	shared_ptr<IShape> shape = *min_element(begin(), end(), LessLeft);
	if (!shape->GetFrame())
	{
		return nullopt;
	}

	double left = shape->GetFrame()->GetLeftTop().x;
	double top = (*min_element(begin(), end(), LessTop))->GetFrame()->GetLeftTop().y;

	shared_ptr<IShape> rightShape = *max_element(begin(), end(), LessRight);
	double width = rightShape->GetFrame()->GetLeftTop().x + rightShape->GetFrame()->GetWidth() - left;

	shared_ptr<IShape> bottomShape = *max_element(begin(), end(), LessBottom);
	double height = bottomShape->GetFrame()->GetLeftTop().y + bottomShape->GetFrame()->GetHeight() - top;

	return RectD({ left, top }, width, height);
}

void CGroupShape::SetFrame(const RectD& newFrame)
{
	optional<RectD> oldframe = GetFrame();
	for (size_t i = 0; i < GetShapesCount(); ++i)
	{
		if (!GetShapeAtIndex(i)->GetFrame())
		{
			continue;
		}

		double relativeLeft = (GetShapeAtIndex(i)->GetFrame()->GetLeftTop().x - oldframe->GetLeftTop().x) / oldframe->GetWidth();
		double relativeTop = (GetShapeAtIndex(i)->GetFrame()->GetLeftTop().y - oldframe->GetLeftTop().y) / oldframe->GetHeight();
		double relativeWidth = GetShapeAtIndex(i)->GetFrame()->GetWidth() / oldframe->GetWidth();
		double relativeHeight = GetShapeAtIndex(i)->GetFrame()->GetHeight() / oldframe->GetHeight();

		double newLeft = newFrame.GetLeftTop().x + relativeLeft * newFrame.GetWidth();
		double newTop = newFrame.GetLeftTop().y + relativeTop * newFrame.GetHeight();
		double newWidth = relativeWidth * newFrame.GetWidth();
		double newHeight = relativeHeight * newFrame.GetHeight();

		GetShapeAtIndex(i)->SetFrame(RectD({ newLeft, newTop }, newWidth, newHeight));
	}
}

CLineStyle CGroupShape::GetOutlineStyle() const
{
	if (GetShapesCount() == 0)
	{
		return CLineStyle();
	}

	CLineStyle outlineStyle = GetShapeAtIndex(0)->GetOutlineStyle();
	for (size_t i = 1; i < GetShapesCount(); ++i)
	{
		if (outlineStyle != GetShapeAtIndex(i)->GetOutlineStyle())
		{
			return CLineStyle();
		}
	}

	return outlineStyle;
}

void CGroupShape::SetOutlineStyle(const CLineStyle& outlineStyle)
{
	for (size_t i = 0; i < GetShapesCount(); ++i)
	{
		GetShapeAtIndex(i)->SetOutlineStyle(outlineStyle);
	}
}

CStyle CGroupShape::GetFillStyle() const
{
	if (GetShapesCount() == 0)
	{
		return CStyle();
	}

	CStyle fillStyle = GetShapeAtIndex(0)->GetFillStyle();
	for (size_t i = 1; i < GetShapesCount(); ++i)
	{
		if (fillStyle != GetShapeAtIndex(i)->GetFillStyle())
		{
			return CStyle();
		}
	}

	return fillStyle;
}

void CGroupShape::SetFillStyle(const CStyle& fillStyle)
{
	for (size_t i = 0; i < GetShapesCount(); ++i)
	{
		GetShapeAtIndex(i)->SetFillStyle(fillStyle);
	}
}

CGroupShape* CGroupShape::GetGroup()
{
	return this;
}

const CGroupShape* CGroupShape::GetGroup() const
{
	return this;
}

void CGroupShape::Draw(ICanvas& canvas) const
{
	for (size_t i = 0; i < GetShapesCount(); ++i)
	{
		GetShapeAtIndex(i)->Draw(canvas);
	}
}

bool CGroupShape::LessLeft(const shared_ptr<IShape>& first, const shared_ptr<IShape>& second)
{
	if (!first->GetFrame() && !second->GetFrame())
	{
		return false;
	}
	if (!first->GetFrame())
	{
		return false;
	}
	if (!second->GetFrame())
	{
		return true;
	}
	return first->GetFrame()->GetLeftTop().x < second->GetFrame()->GetLeftTop().x;
}

bool CGroupShape::LessTop(const shared_ptr<IShape>& first, const shared_ptr<IShape>& second)
{
	if (!first->GetFrame() && !second->GetFrame())
	{
		return false;
	}
	if (!first->GetFrame())
	{
		return false;
	}
	if (!second->GetFrame())
	{
		return true;
	}
	return first->GetFrame()->GetLeftTop().y < second->GetFrame()->GetLeftTop().y;
}

bool CGroupShape::LessRight(const shared_ptr<IShape>& first, const shared_ptr<IShape>& second)
{
	if (!first->GetFrame() && !second->GetFrame())
	{
		return false;
	}
	if (!first->GetFrame())
	{
		return true;
	}
	if (!second->GetFrame())
	{
		return false;
	}
	return first->GetFrame()->GetLeftTop().x + first->GetFrame()->GetWidth()
		< second->GetFrame()->GetLeftTop().x + second->GetFrame()->GetWidth();
}

bool CGroupShape::LessBottom(const shared_ptr<IShape>& first, const shared_ptr<IShape>& second)
{
	if (!first->GetFrame() && !second->GetFrame())
	{
		return false;
	}
	if (!first->GetFrame())
	{
		return true;
	}
	if (!second->GetFrame())
	{
		return false;
	}
	return first->GetFrame()->GetLeftTop().y + first->GetFrame()->GetHeight()
		< second->GetFrame()->GetLeftTop().y + second->GetFrame()->GetHeight();
}