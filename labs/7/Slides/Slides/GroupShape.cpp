#include "pch.h"
#include "GroupShape.h"
#include <algorithm>

using namespace std;

CGroupShape::CGroupShape(const vector<shared_ptr<IShape>>& shapes)
{
	if (shapes.size() < 2)
	{
		throw runtime_error("You cannot create a group of less than two elements");
	}
	m_shapes = shapes;	
}

size_t CGroupShape::GetShapesCount() const
{
	return m_shapes.size();
}

shared_ptr<IShape> CGroupShape::GetShapeAtIndex(size_t index)
{
	if (index >= m_shapes.size())
	{
		throw runtime_error("There is no shape with such index");
	}
	return m_shapes[index];
}

const std::shared_ptr<IShape> CGroupShape::GetShapeAtIndex(size_t index) const
{
	if (index >= m_shapes.size())
	{
		throw runtime_error("There is no shape with such index");
	}
	return m_shapes[index];
}

RectD CGroupShape::GetFrame() const
{
	return CreateFrame();
}

void CGroupShape::SetFrame(const RectD& newFrame)
{
	RectD oldframe = CreateFrame();
	for (size_t i = 0; i < m_shapes.size(); ++i)
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

const CLineStyle& CGroupShape::GetOutlineStyle() const
{
	bool outlineStylesAreEquivalent = true;
	CLineStyle outlineStyle = m_shapes[0]->GetOutlineStyle();
	for (size_t i = 1; i < m_shapes.size(); ++i)
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
	for (size_t i = 0; i < m_shapes.size(); ++i)
	{
		m_shapes[i]->SetOutlineStyle(outlineStyle);
	}
}

const CStyle& CGroupShape::GetFillStyle() const
{
	bool fillStylesAreEquivalent = true;
	CStyle fillStyle = m_shapes[0]->GetFillStyle();
	for (size_t i = 1; i < m_shapes.size(); ++i)
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
	for (size_t i = 0; i < m_shapes.size(); ++i)
	{
		m_shapes[i]->SetFillStyle(fillStyle);
	}
}

shared_ptr<CGroupShape> CGroupShape::GetGroup()
{
	return make_shared<CGroupShape>(this);
}

const shared_ptr<CGroupShape> CGroupShape::GetGroup() const
{
	return make_shared<CGroupShape>(this);
}

void CGroupShape::Draw(ICanvas& canvas) const
{
	for (size_t i = 0; i < m_shapes.size(); ++i)
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