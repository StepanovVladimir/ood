#pragma once

#include "ConstDocumentItem.h"

class CDocumentItem : public CConstDocumentItem
{
public:
	std::shared_ptr<IParagraph> GetParagraph();
	std::shared_ptr<IImage> GetImage();
};