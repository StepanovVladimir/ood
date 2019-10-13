#pragma once

#include "IParagraph.h"
#include "IImage.h"

class CConstDocumentItem
{
public:
	CConstDocumentItem(std::shared_ptr<IParagraph> paragraph);
	CConstDocumentItem(std::shared_ptr<IImage> image);
	virtual ~CConstDocumentItem() = default;

	std::shared_ptr<const IParagraph> GetParagraph() const;
	std::shared_ptr<const IImage> GetImage() const;

protected:
	std::shared_ptr<IParagraph> m_paragraph;
	std::shared_ptr<IImage> m_image;
};