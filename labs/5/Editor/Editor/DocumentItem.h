#pragma once

#include "ConstDocumentItem.h"

class CDocumentItem : public CConstDocumentItem
{
public:
	CDocumentItem(std::shared_ptr<IParagraph> paragraph);
	CDocumentItem(std::shared_ptr<IImage> image);

	std::shared_ptr<IParagraph> GetParagraph();
	std::shared_ptr<IImage> GetImage();
};