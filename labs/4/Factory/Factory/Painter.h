#pragma once

#include "PictureDraft.h"

class CPainter
{
public:
	void DraftPicture(CPictureDraft& draft, ICanvas& canvas) const;
};