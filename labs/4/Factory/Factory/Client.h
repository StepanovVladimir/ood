#pragma once

#include "PictureDraft.h"
#include <iostream>

class CClient
{
public:
	void CreatePictureDraft(std::istream& strm);
	void DrawPicture(ICanvas& canvas) const;

private:
	std::unique_ptr<CPictureDraft> m_pictureDraft;
};