#include "pch.h"
#include "Painter.h"

void CPainter::DrawPicture(CPictureDraft& draft, ICanvas& canvas) const
{
	for (size_t i = 0; i < draft.GetShapesCount(); i++)
	{
		draft[i].Draw(canvas);
	}
}