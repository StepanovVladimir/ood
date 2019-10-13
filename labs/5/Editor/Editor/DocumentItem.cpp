#include "pch.h"
#include "DocumentItem.h"

using namespace std;

CDocumentItem::CDocumentItem(shared_ptr<IParagraph> paragraph)
	: CConstDocumentItem(paragraph)
{
}

CDocumentItem::CDocumentItem(shared_ptr<IImage> image)
	: CConstDocumentItem(image)
{
}

shared_ptr<IParagraph> CDocumentItem::GetParagraph()
{
	return m_paragraph;
}

shared_ptr<IImage> CDocumentItem::GetImage()
{
	return m_image;
}