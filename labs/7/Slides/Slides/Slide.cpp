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

CShapes& CSlide::GetShapes()
{
	return m_shapes;
}

void CSlide::CreateGroup(const set<size_t>& indexes)
{
	vector<shared_ptr<IShape>> shapes;
	for (auto iter = indexes.rbegin(); iter != indexes.rend(); ++iter)
	{
		shapes.push_back(m_shapes[*iter]);
		m_shapes.RemoveShapeAtIndex(*iter);
	}
	shared_ptr<IShape> group = make_shared<CGroupShape>(shapes);
	m_shapes.InsertShape(group);
}

void CSlide::Ungroup(size_t index)
{
	CGroupShape* group = m_shapes[index]->GetGroup();
	if (group == nullptr)
	{
		throw runtime_error("This element is not a group");
	}

	CConstShapes shapes = group->GetShapes();
	m_shapes.RemoveShapeAtIndex(index);

	for (auto shape : shapes)
	{
		m_shapes.InsertShape(shape);
	}
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
	for (size_t i = 0; i < m_shapes.GetShapesCount(); ++i)
	{
		m_shapes[i]->Draw(canvas);
	}
}