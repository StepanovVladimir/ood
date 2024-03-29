#include "pch.h"
#include "ConstDocumentItem.h"

using namespace std;

CConstDocumentItem::CConstDocumentItem(shared_ptr<IParagraph> paragraph)
	: m_paragraph(paragraph)
{
}

CConstDocumentItem::CConstDocumentItem(shared_ptr<IImage> image)
	: m_image(image)
{
}

shared_ptr<const IParagraph> CConstDocumentItem::GetParagraph() const
{
	return m_paragraph;
}

shared_ptr<const IImage> CConstDocumentItem::GetImage() const
{
	return m_image;
}