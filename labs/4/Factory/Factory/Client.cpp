#include "pch.h"
#include "Client.h"
#include "ShapeFactory.h"
#include "Designer.h"
#include "Canvas.h"
#include "Painter.h"

using namespace std;

void CClient::CreatePictureDraft(istream& strm)
{
	CShapeFactory shapeFactory;
	CDesigner designer(shapeFactory);
	m_pictureDraft = make_unique<CPictureDraft>(designer.CreateDraft(strm));
}

void CClient::DrawPicture(ICanvas& canvas) const
{
	if (m_pictureDraft == nullptr)
	{
		throw runtime_error("There is no picture draft");
	}

	CPainter painter;
	painter.DrawPicture(*m_pictureDraft, canvas);
}