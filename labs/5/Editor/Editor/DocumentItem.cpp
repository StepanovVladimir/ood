#include "pch.h"
#include "DocumentItem.h"

using namespace std;

shared_ptr<IParagraph> CDocumentItem::GetParagraph()
{
	return shared_ptr<IParagraph>();
}

shared_ptr<IImage> CDocumentItem::GetImage()
{
	return shared_ptr<IImage>();
}