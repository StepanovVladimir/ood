#include "pch.h"
#include "Slide.h"
#include "GroupShape.h"

using namespace std;

CSlide::CSlide(double widht, double height, RGBAColor backgroundColor)
	: m_width(widht)
	, m_height(height)
	, m_backgroundColor(backgroundColor)
{
}

double CSlide::GetWidth() const
{
	return m_width;
}

double CSlide::GetHeight() const
{
	return m_height;
}

RGBAColor CSlide::GetBackgroundColor() const
{
	return m_backgroundColor;
}

void CSlide::SetBackgroundColor(RGBAColor color)
{
	m_backgroundColor = color;
}

void CSlide::CreateGroup(const set<size_t>& indexes)
{
	shared_ptr<CGroupShape> group = make_shared<CGroupShape>();
	for (auto iter = indexes.rbegin(); iter != indexes.rend(); ++iter)
	{
		group->InsertShape(GetShapeAtIndex(*iter), 0);
		RemoveShapeAtIndex(*iter);
	}
	InsertShape(group);
}

void CSlide::Ungroup(size_t index)
{
	CGroupShape* group = GetShapeAtIndex(index)->GetGroup();

	if (group == nullptr)
	{
		throw runtime_error("This element is not a group");
	}

	for (auto shape : *group)
	{
		InsertShape(shape);
	}

	RemoveShapeAtIndex(index);
}

void CSlide::Draw(ICanvas& canvas) const
{
	canvas.SetLineWidth(0);
	canvas.BeginFill(m_backgroundColor);
	canvas.MoveTo(0, 0);
	canvas.LineTo(m_width, 0);
	canvas.LineTo(m_width, m_height);
	canvas.LineTo(0, m_height);
	canvas.LineTo(0, 0);
	canvas.EndFill();
	for (size_t i = 0; i < GetShapesCount(); ++i)
	{
		GetShapeAtIndex(i)->Draw(canvas);
	}
}