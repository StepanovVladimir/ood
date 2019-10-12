#pragma once

#include "IParagraph.h"
#include "IImage.h"

class CConstDocumentItem
{
public:
	virtual ~CConstDocumentItem() = default;

	std::shared_ptr<const IParagraph> GetParagraph() const;
	std::shared_ptr<const IImage> GetImage() const;
};