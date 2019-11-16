#include "pch.h"
#include "GroupShape.h"
#include <algorithm>

using namespace std;

CGroupShape::CGroupShape(const vector<shared_ptr<IShape>>& shapes)
	: m_shapes(shapes)
{
	if (m_shapes.GetShapesCount() < 2)
	{
		throw runtime_error("You cannot create a group of less than two elements");
	}
}

CConstShapes& CGroupShape::GetShapes()
{
	return m_shapes;
}

RectD CGroupShape::GetFrame() const
{
	return CreateFrame();
}

void CGroupShape::SetFrame(const RectD& newFrame)
{
	RectD oldframe = CreateFrame();
	for (size_t i = 0; i < m_shapes.GetShapesCount(); ++i)
	{
		double relativeLeft = (m_shapes[i]->GetFrame().GetLeftTop().x - oldframe.GetLeftTop().x) / oldframe.GetWidth();
		double relativeTop = (m_shapes[i]->GetFrame().GetLeftTop().y - oldframe.GetLeftTop().y) / oldframe.GetHeight();
		double relativeWidth = m_shapes[i]->GetFrame().GetWidth() / oldframe.GetWidth();
		double relativeHeight = m_shapes[i]->GetFrame().GetHeight() / oldframe.GetHeight();

		double newLeft = newFrame.GetLeftTop().x + relativeLeft * newFrame.GetWidth();
		double newTop = newFrame.GetLeftTop().y + relativeTop * newFrame.GetHeight();
		double newWidth = relativeWidth * newFrame.GetWidth();
		double newHeight = relativeHeight * newFrame.GetHeight();

		m_shapes[i]->SetFrame(RectD({ newLeft, newTop }, newWidth, newHeight));
	}
}

CLineStyle CGroupShape::GetOutlineStyle() const
{
	bool outlineStylesAreEquivalent = true;
	CLineStyle outlineStyle = m_shapes[0]->GetOutlineStyle();
	for (size_t i = 1; i < m_shapes.GetShapesCount(); ++i)
	{
		if (outlineStyle != m_shapes[i]->GetOutlineStyle())
		{
			outlineStylesAreEquivalent = false;
			break;
		}
	}
	if (outlineStylesAreEquivalent)
	{
		return outlineStyle;
	}
	else
	{
		return CLineStyle();
	}
}

void CGroupShape::SetOutlineStyle(const CLineStyle& outlineStyle)
{
	for (size_t i = 0; i < m_shapes.GetShapesCount(); ++i)
	{
		m_shapes[i]->SetOutlineStyle(outlineStyle);
	}
}

CStyle CGroupShape::GetFillStyle() const
{
	bool fillStylesAreEquivalent = true;
	CStyle fillStyle = m_shapes[0]->GetFillStyle();
	for (size_t i = 1; i < m_shapes.GetShapesCount(); ++i)
	{
		if (fillStyle != m_shapes[i]->GetFillStyle())
		{
			fillStylesAreEquivalent = false;
			break;
		}
	}
	if (fillStylesAreEquivalent)
	{
		return fillStyle;
	}
	else
	{
		return CStyle();
	}
}

void CGroupShape::SetFillStyle(const CStyle& fillStyle)
{
	for (size_t i = 0; i < m_shapes.GetShapesCount(); ++i)
	{
		m_shapes[i]->SetFillStyle(fillStyle);
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
	for (size_t i = 0; i < m_shapes.GetShapesCount(); ++i)
	{
		m_shapes[i]->Draw(canvas);
	}
}

RectD CGroupShape::CreateFrame() const
{
	double left = (*min_element(m_shapes.begin(), m_shapes.end(), LessLeft))->GetFrame().GetLeftTop().x;
	double top = (*min_element(m_shapes.begin(), m_shapes.end(), LessTop))->GetFrame().GetLeftTop().y;

	shared_ptr<IShape> rightShape = *max_element(m_shapes.begin(), m_shapes.end(), LessRight);
	double width = rightShape->GetFrame().GetLeftTop().x + rightShape->GetFrame().GetWidth() - left;

	shared_ptr<IShape> bottomShape = *max_element(m_shapes.begin(), m_shapes.end(), LessBottom);
	double height = bottomShape->GetFrame().GetLeftTop().y + bottomShape->GetFrame().GetHeight() - top;
	
	return RectD({ left, top }, width, height);
}

bool CGroupShape::LessLeft(const shared_ptr<IShape>& first, const shared_ptr<IShape>& second)
{
	return first->GetFrame().GetLeftTop().x < second->GetFrame().GetLeftTop().x;
}

bool CGroupShape::LessTop(const shared_ptr<IShape>& first, const shared_ptr<IShape>& second)
{
	return first->GetFrame().GetLeftTop().y < second->GetFrame().GetLeftTop().y;
}

bool CGroupShape::LessRight(const shared_ptr<IShape>& first, const shared_ptr<IShape>& second)
{
	return first->GetFrame().GetLeftTop().x + first->GetFrame().GetWidth()
		< second->GetFrame().GetLeftTop().x + second->GetFrame().GetWidth();
}

bool CGroupShape::LessBottom(const shared_ptr<IShape>& first, const shared_ptr<IShape>& second)
{
	return first->GetFrame().GetLeftTop().y + first->GetFrame().GetHeight()
		< second->GetFrame().GetLeftTop().y + second->GetFrame().GetHeight();
}